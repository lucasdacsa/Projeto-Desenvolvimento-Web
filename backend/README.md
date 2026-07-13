# API - Catálogo de Jogos 🎮

Esta é uma API RESTful desenvolvida em Node.js com Express, construída para gerenciar um catálogo de jogos e categorias, incluindo um sistema de autenticação segura.

## Tecnologias Utilizadas

- **Node.js & Express:** Servidor e roteamento.
- **Prisma ORM & PostgreSQL:** Modelagem e persistência de dados.
- **Bcryptjs:** Criptografia de senhas (Hash).
- **JSON Web Token (JWT) & Cookie-Parser:** Autenticação e controle de sessão.

## Entidades Principais

- **Usuário:** Dados de autenticação (id, nome, email, senha).
- **Categoria:** Gêneros dos jogos (id, nome).
- **Jogo:** Detalhes do jogo (id, titulo, descricao, ano, capaUrl) com relacionamento para Categoria.
- **Inscrito:** E-mails capturados pela Newsletter (id, email).

## Principais Rotas

- `POST /api/cadastro` - Cria um novo usuário com senha criptografada.
- `POST /api/login` - Autentica o usuário e gera o token de sessão (cookie).
- `GET /api/perfil` - Rota privada (VIP) que exige autenticação.
- `GET /api/jogos` - Lista todos os jogos e suas categorias.
- `POST, PUT, DELETE /api/jogos` - CRUD completo para o catálogo.

## Como rodar o projeto localmente

1. Clone este repositório no seu computador.
2. Abra o terminal na pasta do projeto e instale as dependências:
   ```bash
   npm install
   ```
