// ==============================================================================
// 1. IMPORTAÇÕES DE BIBLIOTECAS (Pegando as ferramentas na caixa de ferramentas)
// ==============================================================================
import "dotenv/config";
import express from "express";
import { PrismaClient } from "@prisma/client";
import cors from "cors"; // <-- O porteiro (já estava importado certinho aqui!)
import bcrypt from "bcryptjs";
import jwt from "jsonwebtoken";
import cookieParser from "cookie-parser";

// ==============================================================================
// 2. INICIALIZAÇÃO E CONFIGURAÇÃO (Ligando as máquinas)
// ==============================================================================
const prisma = new PrismaClient(); // Liga a conexão com o banco de dados
const app = express();

// Regras gerais do nosso servidor (os "app.use"):
app.use(cors()); // Libera a porta para o site Vercel conversar com a API
app.use(express.json()); // Ensina o servidor a ler pacotes de dados no formato JSON
app.use(cookieParser()); // Ensina o servidor a mexer na "mochila" de cookies do usuário

// ==============================================================================
// 3. ROTAS DE NEWSLETTER (Atendimento para captura de e-mails)
// ==============================================================================
app.post("/api/newsletter", async (req, res) => {
  try {
    const { email } = req.body;
    const novoInscrito = await prisma.inscrito.create({
      data: { email: email },
    });
    res.status(201).json(novoInscrito);
  } catch (erro) {
    console.error("Erro na newsletter:", erro);
    res.status(500).json({ error: "Erro ao se inscrever." });
  }
});

// ==============================================================================
// 4. ROTAS DE CATÁLOGO (Categorias e Jogos)
// ==============================================================================
app.post("/api/categorias", async (req, res) => {
  try {
    const { nome } = req.body;
    const novaCategoria = await prisma.categoria.create({
      data: { nome: nome },
    });
    res.status(201).json(novaCategoria);
  } catch (erro) {
    console.error("Erro ao criar categoria:", erro);
    res.status(500).json({ error: "Erro ao salvar a categoria." });
  }
});

app.post("/api/jogos", async (req, res) => {
  try {
    const { titulo, descricao, ano, capaUrl, categoriaId } = req.body;
    const novoJogo = await prisma.jogo.create({
      data: {
        titulo: titulo,
        descricao: descricao,
        ano: ano,
        capaUrl: capaUrl,
        categoriaId: categoriaId,
      },
    });
    res.status(201).json(novoJogo);
  } catch (erro) {
    console.error("Erro ao criar jogo:", erro);
    res.status(500).json({ error: "Erro ao salvar o jogo no catálogo." });
  }
});

app.get("/api/jogos", async (req, res) => {
  try {
    const jogos = await prisma.jogo.findMany();
    res.status(200).json(jogos);
  } catch (erro) {
    console.error("Erro ao buscar os jogos:", erro);
    res.status(500).json({ error: "Erro interno ao carregar o catálogo." });
  }
});

// ==============================================================================
// 5. ROTA DE CADASTRO (Requisito de Segurança - Peso Grande na Nota)
// ==============================================================================
app.post("/api/cadastro", async (req, res) => {
  try {
    const { nome, email, senha } = req.body;

    const usuarioExistente = await prisma.usuario.findUnique({
      where: { email: email },
    });

    if (usuarioExistente) {
      return res.status(400).json({ error: "Este e-mail já está em uso." });
    }

    const salt = await bcrypt.genSalt(10);
    const senhaHash = await bcrypt.hash(senha, salt);

    const novoUsuario = await prisma.usuario.create({
      data: {
        nome: nome,
        email: email,
        senha: senhaHash,
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
    const { email, senha } = req.body;

    const usuario = await prisma.usuario.findUnique({
      where: { email: email },
    });

    if (!usuario) {
      return res.status(401).json({ error: "E-mail ou senha incorretos." });
    }

    const senhaValida = await bcrypt.compare(senha, usuario.senha);
    if (!senhaValida) {
      return res.status(401).json({ error: "E-mail ou senha incorretos." });
    }

    const token = jwt.sign({ id: usuario.id }, "CHAVE_SECRETA_DO_PROJETO", {
      expiresIn: "1h",
    });

    res.cookie("token", token, {
      httpOnly: true,
      secure: false,
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
  const token = req.cookies.token;

  if (!token) {
    return res
      .status(403)
      .json({ error: "Acesso negado. Você precisa fazer login primeiro!" });
  }

  try {
    const dadosDoToken = jwt.verify(token, "CHAVE_SECRETA_DO_PROJETO");
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
// O process.env.PORT pega a porta dinâmica da nuvem. Se não existir, usa a 3001.
const PORTA = process.env.PORT || 3001;

app.listen(PORTA, () => {
  console.log(`Servidor rodando na porta ${PORTA} 🚀`);
});
