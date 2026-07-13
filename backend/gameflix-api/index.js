const express = require("express");
const cors = require("cors");
const { PrismaClient } = require("@prisma/client");

// Novas importações exigidas pelo Prisma 7
const { PrismaPg } = require("@prisma/adapter-pg");
const { Pool } = require("pg");
require("dotenv").config();

// Configurando o novo Adaptador do banco de dados
const pool = new Pool({ connectionString: process.env.DATABASE_URL });
const adapter = new PrismaPg(pool);
const prisma = new PrismaClient({ adapter });

const app = express();

// Configurações de segurança e formato de dados
app.use(cors());
app.use(express.json());

// ==========================================
// ROTAS DA APLICAÇÃO
// ==========================================

// Rota principal para testar se o servidor está online
app.get("/", (req, res) => {
  res.send("API do GameFlix está rodando perfeitamente!");
});

// Rota para listar todos os jogos do catálogo
app.get("/games", async (req, res) => {
  try {
    const games = await prisma.game.findMany();
    res.json(games);
  } catch (error) {
    res.status(500).json({ error: "Erro ao buscar jogos no banco de dados." });
  }
});

// Rota para cadastrar e-mail na Newsletter
app.post("/newsletter", async (req, res) => {
  const { email } = req.body;

  if (!email) {
    return res.status(400).json({ error: "O e-mail é obrigatório." });
  }

  try {
    const novoCadastro = await prisma.newsletter.create({
      data: { email },
    });
    res
      .status(201)
      .json({ message: "E-mail cadastrado com sucesso!", data: novoCadastro });
  } catch (error) {
    // O Prisma retorna um erro se o e-mail já existir
    res.status(400).json({ error: "Este e-mail já está cadastrado!" });
  }
});

// ==========================================
// LIGANDO O SERVIDOR
// ==========================================
const PORT = 3000;
app.listen(PORT, () => {
  console.log(`🚀 Servidor rodando na porta http://localhost:${PORT}`);
});
