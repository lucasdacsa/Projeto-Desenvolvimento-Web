#include <iostream>    //→ Permite usar cin e cout para entrada e saída no console.
#include <string>     //→ Permite trabalhar com strings (getline, texto com espaços).
#include <vector>    // → Permite usar vetores dinâmicos (vector), que são listas que podem crescer.
#include <limits>   // → Usado para limpar o buffer do teclado com cin.ignore().

using namespace std;

/*struct é como um molde para criar objetos. Aqui, cada Filme terá um título e um ano.
É como se fosse uma "ficha de cadastro" para um filme, Onde pode colocar as variaveis  */ 
struct Filme { 
    string titulo;
    string ano;
};

int main () {
    /* Criar o vetor. Esta é a nossa lista principal chamado listaDeFilmes.
    Ela vai guardar todos os objetos do tipo "Filme*/
    vector<Filme> listaDeFilmes;
    
    int opcao;

    // O do { ... } while mantém o menu rodando até o usuário escolher 3 (Sair).
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1 - Cadastrar Filme" << endl;
        cout << "2 - Listar Filmes" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // O cin.ignore() serve para limpar o ENTER que o usuário digitou, evitando problemas no getline.
        // Isso evita que o "getline" pule a leitura do título.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // cin usado para ler dados do dispositivo de entrada padrão

        if (opcao == 1) {
            
            // --- Bloco para CADASTRAR ---
            Filme novoFilme; // Cria uma "ficha" temporária para preencher.

            cout << "Digite o titulo do filme: ";
            getline(cin, novoFilme.titulo); // Pede ao usuario o titulo
            // getline usado para permitir que strings usem espaço

            cout << "Digite o ano do filme: "; // pede ao usuario o ano
            getline(cin, novoFilme.ano);

            // (Adicionar):
            // Usa push_back para adicionar o filme na lista (vector).
            listaDeFilmes.push_back(novoFilme);

            cout << "=> Filme cadastrado com sucesso!" << endl;

        } else if (opcao == 2) { 

            // --- Bloco para LISTAR ---
            cout << "\n--- Filmes Cadastrados ---" << endl;

            if (listaDeFilmes.empty()) { //verifica se a lista ta vazia se estiver mostra a mensagem
                cout << "A lista esta vazia." << endl; 
            } else {
                // (Listar):
                // Este loop "for" passa por cada filme que está na "listaDeFilmes".
                for (const Filme &filme : listaDeFilmes) {
                    cout << "-> Titulo: " << filme.titulo << " | Ano: " << filme.ano << endl;
                }
            }

        } else if (opcao == 3) { // Encerra o programa.
            cout << "Saindo..." << endl;
        } else {
            cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 3); // enquanto a opção for diferente de 3, o menu volta a aparecer.
    return 0;
}