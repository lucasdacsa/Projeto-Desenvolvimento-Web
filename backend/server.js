// ==============================================================================
// 1. IMPORTAÇÕES DE BIBLIOTECAS (Pegando as ferramentas na caixa de ferramentas)
// ==============================================================================
// O dotenv é o "manual de instruções". Ele lê o arquivo .env e ensina o servidor a usar as variáveis de ambiente.
import "dotenv/config";
// O Express é o "gerente" do nosso servidor. Ele escuta os pedidos da internet.
import express from "express";

// O Prisma é o "tradutor". Ele pega o que escrevemos em JavaScript e traduz para o banco de dados (SQLite) entender.
import { PrismaClient } from "@prisma/client";

// O CORS é o "porteiro". Ele permite que o seu Front-end (HTML/Site) converse com este Back-end sem ser bloqueado por questões de segurança.
import cors from "cors";

// --- Ferramentas de Segurança (Para a nota de Autenticação) ---

// O Bcrypt é o "triturador". Ele pega a senha (ex: "123456") e transforma num código maluco ("$2b$10$wTf...") para ninguém descobrir.
import bcrypt from "bcryptjs";

// O JWT fabrica "crachás VIP". Quando o usuário faz login, ele ganha um crachá virtual para entrar nas áreas protegidas.
import jwt from "jsonwebtoken";

// O Cookie-Parser é a "mochila". Ele permite que o servidor guarde e leia o crachá VIP direto no navegador do usuário.
import cookieParser from "cookie-parser";

// ==============================================================================
// 2. INICIALIZAÇÃO E CONFIGURAÇÃO (Ligando as máquinas)
// ==============================================================================
const prisma = new PrismaClient(); // Liga a conexão com o banco de dados
const app = express(); // Cria o nosso servidor web

// Regras gerais do nosso servidor (os "app.use"):
app.use(express.json()); // Ensina o servidor a ler pacotes de dados no formato JSON
app.use(cors()); // Libera a porta para o site conversar com a gente
app.use(cookieParser()); // Ensina o servidor a mexer na "mochila" de cookies do usuário

// ==============================================================================
// 3. ROTAS DE NEWSLETTER (Atendimento para captura de e-mails)
// ==============================================================================
// app.post significa: "Estou preparado para RECEBER dados e salvar".
app.post("/api/newsletter", async (req, res) => {
  try {
    // "Tente fazer isso:"
    const { email } = req.body; // req.body é o formulário que o cliente preencheu

    // Manda o Prisma criar uma linha nova na tabela 'Inscrito'
    const novoInscrito = await prisma.inscrito.create({
      data: { email: email },
    });

    res.status(201).json(novoInscrito); // res = Resposta! 201 significa "Criado com Sucesso"
  } catch (erro) {
    // "Se der algum erro no meio do caminho, capture aqui e não deixe o servidor explodir"
    console.error("Erro na newsletter:", erro);
    res.status(500).json({ error: "Erro ao se inscrever." }); // 500 = Erro interno do servidor
  }
});

// ==============================================================================
// 4. ROTAS DE CATÁLOGO (Categorias e Jogos)
// ==============================================================================

// Rota para CRIAR categorias
app.post("/api/categorias", async (req, res) => {
  try {
    const { nome } = req.body; // Pega o nome digitado ("Ação", "RPG", etc)

    const novaCategoria = await prisma.categoria.create({
      data: { nome: nome },
    });

    res.status(201).json(novaCategoria);
  } catch (erro) {
    console.error("Erro ao criar categoria:", erro);
    res.status(500).json({ error: "Erro ao salvar a categoria." });
  }
});

// Rota para CRIAR jogos e vincular com as categorias (Requisito de Relacionamento)
app.post("/api/jogos", async (req, res) => {
  try {
    const { titulo, descricao, ano, capaUrl, categoriaId } = req.body;

    const novoJogo = await prisma.jogo.create({
      data: {
        titulo: titulo,
        descricao: descricao,
        ano: ano,
        capaUrl: capaUrl,
        categoriaId: categoriaId, // É aqui que o banco amarra o jogo na categoria!
      },
    });

    res.status(201).json(novoJogo);
  } catch (erro) {
    console.error("Erro ao criar jogo:", erro);
    res.status(500).json({ error: "Erro ao salvar o jogo no catálogo." });
  }
});

// Rota GET: "Estou preparado para LER e ENVIAR dados".
// Serve para o seu site pedir: "Ei servidor, me manda todos os jogos cadastrados!"
app.get("/api/jogos", async (req, res) => {
  try {
    const jogos = await prisma.jogo.findMany({
      include: {
        categoria: true, // "Além do jogo, traga o nome da categoria junto, por favor."
      },
    });

    res.status(200).json(jogos); // 200 = "OK, Pedido atendido com sucesso!"
  } catch (erro) {
    console.error("Erro ao listar jogos:", erro);
    res.status(500).json({ error: "Erro ao obter o catálogo de jogos." });
  }
});

// ==============================================================================
// 5. ROTA DE CADASTRO (Requisito de Segurança - Peso Grande na Nota)
// ==============================================================================
app.post("/api/cadastro", async (req, res) => {
  try {
    const { nome, email, senha } = req.body;

    // Passo 1: Verifica se esse e-mail já existe no banco
    const usuarioExistente = await prisma.usuario.findUnique({
      where: { email: email },
    });

    if (usuarioExistente) {
      // Se já existir...
      return res.status(400).json({ error: "Este e-mail já está em uso." }); // 400 = "Cliente, você enviou algo errado"
    }

    // Passo 2: Embaralha a senha com a ferramenta Bcrypt
    const salt = await bcrypt.genSalt(10); // Cria um fator de mistura
    const senhaHash = await bcrypt.hash(senha, salt); // Transforma a senha real no Hash (ex: $2b$10$...)

    // Passo 3: Salva o usuário no banco (com a senha escondida!)
    const novoUsuario = await prisma.usuario.create({
      data: {
        nome: nome,
        email: email,
        senha: senhaHash, // Nunca guarde a senha pura!
      },
    });

    res.status(201).json({ message: "Usuário criado com sucesso!" });
  } catch (erro) {
    console.error("Erro ao cadastrar:", erro);
    res.status(500).json({ error: "Erro interno no servidor." });
  }
});

// ==============================================================================
// 6. ROTA DE LOGIN E SESSÃO (Criando o crachá VIP)
// ==============================================================================
app.post("/api/login", async (req, res) => {
  try {
    const { email, senha } = req.body; // Pega o email e senha que o cliente digitou no form

    // 1. Procura o cliente no banco pelo e-mail
    const usuario = await prisma.usuario.findUnique({
      where: { email: email },
    });

    if (!usuario) {
      return res.status(401).json({ error: "E-mail ou senha incorretos." }); // 401 = Não autorizado
    }

    // 2. Pega a senha que ele digitou agora e compara com a mistura (Hash) do banco
    const senhaValida = await bcrypt.compare(senha, usuario.senha);
    if (!senhaValida) {
      return res.status(401).json({ error: "E-mail ou senha incorretos." });
    }

    // 3. Se a senha bateu, fabricamos o crachá VIP (Token)
    const token = jwt.sign({ id: usuario.id }, "CHAVE_SECRETA_DO_PROJETO", {
      expiresIn: "1h", // O crachá vale por 1 hora
    });

    // 4. Guardamos o crachá na mochila (Cookie) do cliente
    res.cookie("token", token, {
      httpOnly: true, // Protege contra hackers roubarem o crachá
      secure: false, // Falso porque não temos HTTPS (cadeado verde) no ambiente local
    });

    res.status(200).json({ message: "Login realizado com sucesso!" });
  } catch (erro) {
    console.error("Erro no login:", erro);
    res.status(500).json({ error: "Erro interno no servidor." });
  }
});

// ==============================================================================
// 7. ROTA PRIVADA (Área VIP - Só entra quem tem o crachá)
// ==============================================================================
app.get("/api/perfil", (req, res) => {
  // O porteiro tenta puxar o crachá (Token) da mochila (Cookie) do cliente
  const token = req.cookies.token;

  if (!token) {
    // Se não tiver crachá...
    return res
      .status(403) // 403 = Proibido!
      .json({ error: "Acesso negado. Você precisa fazer login primeiro!" });
  }

  try {
    // Verifica se o crachá é falso ou se já venceu a validade de 1 hora
    const dadosDoToken = jwt.verify(token, "CHAVE_SECRETA_DO_PROJETO");

    // Se estiver tudo certo, deixa o cliente entrar na rota
    res.status(200).json({
      message: "Bem-vindo à área VIP protegida!",
      id_do_usuario: dadosDoToken.id,
    });
  } catch (erro) {
    res.status(403).json({ error: "Token inválido ou expirado." });
  }
});

// ==============================================================================
// 8. INICIAR O SERVIDOR (Ligando a chave geral)
// ==============================================================================
const PORTA = 3001; // O canal de rádio que o servidor vai sintonizar

app.listen(PORTA, () => {
  console.log(`Servidor rodando na porta ${PORTA} 🚀`); // Aviso no terminal
});
