#include <iostream>    // → Permite usar cin e cout para entrada e saída no console.
#include <string>     // → Permite trabalhar com strings (getline, texto com espaços).
#include <vector>    // → Permite usar vetores dinâmicos (vector), que são listas que podem crescer.
#include <limits>   // → Usado para limpar o buffer do teclado com cin.ignore().

using namespace std;

/* 
   Definição de uma struct:
   - struct é como um "molde" que permite criar objetos personalizados.
   - Aqui, cada Filme terá um título e um ano.
   - É como se fosse uma ficha de cadastro de filmes.
*/
struct Filme { 
    string titulo;
    string ano;
};

// -----------------------------------------------------------------------------
// Função para cadastrar filme
// Recebe a lista de filmes por referência (vector<Filme> &),
// para que o novo filme seja adicionado diretamente na lista principal.
// -----------------------------------------------------------------------------
void cadastrarFilme(vector<Filme> &listaDeFilmes) {
    Filme novoFilme; // Cria uma ficha temporária para guardar os dados do novo filme.

    // Pede os dados ao usuário
    cout << "Digite o titulo do filme: ";
    getline(cin, novoFilme.titulo); // getline permite ler textos com espaços

    cout << "Digite o ano do filme: "; 
    getline(cin, novoFilme.ano);

    // Adiciona o filme preenchido na lista (vector)
    listaDeFilmes.push_back(novoFilme); 

    cout << "=> Filme cadastrado com sucesso!" << endl;
}

// -----------------------------------------------------------------------------
// Função para listar todos os filmes cadastrados
// Recebe a lista de filmes por referência constante (const &),
// assim ela pode ser lida mas não alterada.
// -----------------------------------------------------------------------------
void listarFilmes(const vector<Filme> &listaDeFilmes) {
    cout << "\n--- Filmes Cadastrados ---" << endl;

    // Verifica se a lista está vazia
    if (listaDeFilmes.empty()) { 
        cout << "A lista esta vazia." << endl; 
    } else {
        // Se houver filmes, percorre o vector e exibe cada um
        for (const Filme &filme : listaDeFilmes) {
            cout << "-> Titulo: " << filme.titulo 
                 << " | Ano: " << filme.ano << endl;
        }
    }
}

// -----------------------------------------------------------------------------
// Função do menu principal
// Aqui ficam as opções do programa (Cadastrar, Listar e Sair).
// -----------------------------------------------------------------------------
void menu() {
    vector<Filme> listaDeFilmes;  // Cria o vector principal que guarda os filmes
    int opcao;                    // Variável que guarda a escolha do usuário

    // Estrutura de repetição que mantém o menu ativo até que a opção "3 - Sair" seja escolhida
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1 - Cadastrar Filme" << endl;
        cout << "2 - Listar Filmes" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Limpa o ENTER que sobra do cin, para evitar problemas no getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        // Estruturas de controle (if/else) para chamar as funções certas
        if (opcao == 1) {
            cadastrarFilme(listaDeFilmes);  // Chama a função de cadastro
        } else if (opcao == 2) { 
            listarFilmes(listaDeFilmes);    // Chama a função de listagem
        } else if (opcao == 3) { 
            cout << "Saindo..." << endl;    // Finaliza o programa
        } else {
            cout << "Opcao invalida!" << endl; // Caso o usuário digite algo inválido
        }

    } while (opcao != 3); // Enquanto a opção for diferente de 3, o menu continua aparecendo
}

// -----------------------------------------------------------------------------
// Função principal
// É o ponto de entrada do programa: inicia chamando o menu.
// -----------------------------------------------------------------------------
int main() {
    menu();  // Inicia o programa
    return 0;
}
