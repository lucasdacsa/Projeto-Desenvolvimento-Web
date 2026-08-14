// ==============================================================================
// CONFIGURAÇÃO DA API
// ==============================================================================

const API_URL = "http://localhost:3001";

// ==============================================================================
// CATÁLOGO DE JOGOS
// ==============================================================================

// Guarda os jogos carregados do banco
let todosOsJogos = [];

// ==============================================================================
// CARREGAR JOGOS DO BANCO DE DADOS
// ==============================================================================

async function carregarJogos() {
  // CORREÇÃO AQUI: Ajustado para "catalogo-jogos"
  const catalogo = document.getElementById("catalogo-jogos");

  try {
    // Busca os jogos no backend
    const response = await fetch(`${API_URL}/api/jogos`);

    // Verifica se o servidor respondeu corretamente
    if (!response.ok) {
      throw new Error(`Erro HTTP: ${response.status}`);
    }

    // Converte a resposta para JSON
    const jogos = await response.json();

    // Guarda os jogos na variável
    todosOsJogos = jogos;

    // Mostra os jogos na tela
    mostrarJogos(todosOsJogos);
  } catch (erro) {
    console.error("Erro ao carregar jogos:", erro);

    catalogo.innerHTML = `
            <div class="col-span-full text-center">
                <p class="text-red-400 text-lg">
                    Não foi possível carregar os jogos.
                </p>
                <p class="text-gray-400 mt-2">
                    Verifique se o backend está funcionando na porta 3001.
                </p>
            </div>
        `;
  }
}

// ==============================================================================
// MOSTRAR JOGOS NA TELA
// ==============================================================================

function mostrarJogos(jogos) {
  // CORREÇÃO AQUI: Ajustado para "catalogo-jogos"
  const catalogo = document.getElementById("catalogo-jogos");

  // Limpa o catálogo
  catalogo.innerHTML = "";

  // Se não existir nenhum jogo
  if (jogos.length === 0) {
    catalogo.innerHTML = `
            <p class="text-gray-400 col-span-full text-center">
                Nenhum jogo encontrado no banco de dados.
            </p>
        `;
    return;
  }

  // Cria um card para cada jogo
  jogos.forEach((jogo) => {
    const card = document.createElement("div");

    card.className =
      "bg-gray-800 rounded-xl overflow-hidden shadow-lg hover:scale-105 transition duration-300";

    // Caso o jogo não tenha imagem
    const imagem = jogo.capaUrl
      ? jogo.capaUrl
      : "https://via.placeholder.com/600x300?text=GameFlix";

    card.innerHTML = `
            <img
                class="w-full h-48 object-cover"
                src="${imagem}"
                alt="${jogo.titulo}"
                onerror="this.src='https://via.placeholder.com/600x300?text=Imagem+indisponível'"
            >
            <div class="p-4">
                <h2 class="text-xl font-bold mb-2">
                    ${jogo.titulo}
                </h2>
                <p class="text-gray-400 mb-2">
                    ${jogo.descricao || "Sem descrição disponível."}
                </p>
                ${
                  jogo.ano
                    ? `
                            <p class="text-gray-500 text-sm">
                                Ano: ${jogo.ano}
                            </p>
                          `
                    : ""
                }
                <button
                    type="button"
                    class="mt-4 bg-blue-500 px-4 py-2 rounded hover:bg-blue-600"
                    onclick="verJogo(${jogo.id})">
                    Ver jogo
                </button>
            </div>
        `;

    catalogo.appendChild(card);
  });
}

// ==============================================================================
// BOTÃO "VER JOGO"
// ==============================================================================

function verJogo(id) {
  const jogo = todosOsJogos.find((item) => item.id === id);

  if (!jogo) {
    alert("Jogo não encontrado.");
    return;
  }

  alert(
    `Jogo: ${jogo.titulo}\n\n` +
      `Descrição: ${jogo.descricao || "Sem descrição"}\n` +
      `Ano: ${jogo.ano || "Não informado"}`,
  );
}

// ==============================================================================
// SISTEMA DE BUSCA
// ==============================================================================

const campoBusca = document.getElementById("campoBusca");

if (campoBusca) {
  campoBusca.addEventListener("input", function () {
    const texto = campoBusca.value.toLowerCase().trim();

    // Se o campo estiver vazio, mostra todos
    if (texto === "") {
      mostrarJogos(todosOsJogos);
      return;
    }

    // Filtra pelo título ou descrição
    const jogosFiltrados = todosOsJogos.filter((jogo) => {
      const titulo = (jogo.titulo || "").toLowerCase();
      const descricao = (jogo.descricao || "").toLowerCase();

      return titulo.includes(texto) || descricao.includes(texto);
    });

    mostrarJogos(jogosFiltrados);
  });
}

// ==============================================================================
// NEWSLETTER
// ==============================================================================

const newsletterForm = document.getElementById("newsletterForm");

if (newsletterForm) {
  newsletterForm.addEventListener("submit", async function (event) {
    event.preventDefault();

    const emailInput = document.getElementById("emailNewsletter");
    const email = emailInput.value.trim();

    // Verifica se o e-mail foi preenchido
    if (!email) {
      alert("Digite um e-mail.");
      return;
    }

    try {
      const response = await fetch(`${API_URL}/api/newsletter`, {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({
          email: email,
        }),
      });

      const dados = await response.json();

      if (response.ok) {
        alert("E-mail cadastrado com sucesso no banco de dados!");
        emailInput.value = "";
      } else {
        alert(dados.error || "Ops! Ocorreu um erro ao cadastrar o e-mail.");
      }
    } catch (erro) {
      console.error("Erro de conexão com a API:", erro);
      alert("Não foi possível conectar ao servidor.");
    }
  });
}

// ==============================================================================
// INICIAR O SISTEMA
// ==============================================================================

// Quando a página carregar, busca os jogos
carregarJogos();
