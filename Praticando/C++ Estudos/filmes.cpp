#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm> // Necessário para std::max
using namespace std;

/*-----------------------------------------------------------
  CLASSE FILME
  Representa um filme com seus atributos e métodos básicos.
-----------------------------------------------------------*/
class Filme {
private:
    int id;            // Identificador único do filme
    string titulo;     // Título do filme
    string genero;     // Gênero do filme (ex: ação, drama, etc.)
    int ano;           // Ano de lançamento
    double avaliacao;  // Avaliação (nota de 0 a 10)

public:
    // Construtor com valores padrão
    Filme(int _id = 0, string _titulo = "", string _genero = "", int _ano = 0, double _avaliacao = 0.0)
        : id(_id), titulo(_titulo), genero(_genero), ano(_ano), avaliacao(_avaliacao) {}

    // Métodos de acesso (getters)
    int getId() const { return id; }
    string getTitulo() const { return titulo; }
    string getGenero() const { return genero; }
    int getAno() const { return ano; }
    double getAvaliacao() const { return avaliacao; }

    // Métodos de modificação (setters)
    void setTitulo(const string& novoTitulo) { titulo = novoTitulo; }
    void setGenero(const string& novoGenero) { genero = novoGenero; }
    void setAno(int novoAno) { ano = novoAno; }
    void setAvaliacao(double novaAvaliacao) { avaliacao = novaAvaliacao; }

    // Converte os dados do filme para uma linha de texto (CSV)
    string toString() const {
        return to_string(id) + "," + titulo + "," + genero + "," +
               to_string(ano) + "," + to_string(avaliacao);
    }

    // Exibe os dados do filme formatados na tela
    void exibir() const {
        cout << "ID: " << id
             << " | Título: " << titulo
             << " | Gênero: " << genero
             << " | Ano: " << ano
             << " | Avaliação: " << avaliacao << endl;
    }
};

/*-----------------------------------------------------------
  CLASSE SISTEMAFILMES
  Controla o CRUD e a manipulação do arquivo de filmes.
-----------------------------------------------------------*/
class SistemaFilmes {
private:
    vector<Filme> filmes; // Vetor que armazena todos os filmes
    int proximoId;        // Guarda o próximo ID disponível

    // Função auxiliar para limpar buffer de entrada
    void limparEntrada() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    // Construtor: carrega os dados do arquivo assim que o sistema inicia
    SistemaFilmes() : proximoId(1) {
        carregarDoArquivo();
    }

    /*-----------------------------
      FUNÇÃO: Adicionar novo filme
    ------------------------------*/
    void adicionarFilme() {
        string titulo, genero;
        int ano;
        double avaliacao;

        cout << "\n=== Adicionar Filme ===\n";
        cout << "Título: ";
        getline(cin, titulo);
        cout << "Gênero: ";
        getline(cin, genero);

        // Valida o campo "ano"
        cout << "Ano: ";
        while (!(cin >> ano)) {
            cout << "Entrada inválida. Digite um número para o ano: ";
            limparEntrada();
        }

        // Valida o campo "avaliação"
        cout << "Avaliação (0 a 10): ";
        while (!(cin >> avaliacao) || avaliacao < 0 || avaliacao > 10) {
            cout << "Digite uma avaliação válida entre 0 e 10: ";
            limparEntrada();
        }
        limparEntrada(); // Limpa o buffer

        // Cria um novo objeto Filme e adiciona ao vetor
        filmes.push_back(Filme(proximoId++, titulo, genero, ano, avaliacao));
        cout << "Filme adicionado com sucesso!\n";
    }

    /*-----------------------------
      FUNÇÃO: Listar todos os filmes
    ------------------------------*/
    void listarFilmes() {
        cout << "\n=== Lista de Filmes ===\n";
        if (filmes.empty()) {
            cout << "Nenhum filme cadastrado.\n";
            return;
        }

        // Percorre o vetor e exibe cada filme
        for (const auto& f : filmes) {
            f.exibir();
        }
    }

    /*-----------------------------
      FUNÇÃO: Editar um filme existente
    ------------------------------*/
    void editarFilme() {
        int id;
        cout << "\nDigite o ID do filme que deseja editar: ";
        cin >> id;
        limparEntrada();

        // Procura o filme pelo ID informado
        for (auto& f : filmes) {
            if (f.getId() == id) {
                string titulo, genero;
                int ano;
                double avaliacao;

                cout << "Novo título (atual: " << f.getTitulo() << "): ";
                getline(cin, titulo);
                cout << "Novo gênero (atual: " << f.getGenero() << "): ";
                getline(cin, genero);

                cout << "Novo ano (atual: " << f.getAno() << "): ";
                while (!(cin >> ano)) {
                    cout << "Entrada inválida. Digite um número: ";
                    limparEntrada();
                }

                cout << "Nova avaliação (atual: " << f.getAvaliacao() << "): ";
                while (!(cin >> avaliacao) || avaliacao < 0 || avaliacao > 10) {
                    cout << "Digite uma avaliação válida entre 0 e 10: ";
                    limparEntrada();
                }
                limparEntrada();

                // Atualiza os dados do filme
                f.setTitulo(titulo);
                f.setGenero(genero);
                f.setAno(ano);
                f.setAvaliacao(avaliacao);

                cout << "Filme atualizado com sucesso!\n";
                return;
            }
        }

        cout << "Filme não encontrado.\n";
    }

    /*-----------------------------
      FUNÇÃO: Remover um filme
    ------------------------------*/
    void removerFilme() {
        int id;
        cout << "\nDigite o ID do filme que deseja remover: ";
        cin >> id;
        limparEntrada();

        // Procura o filme e remove do vetor
        for (size_t i = 0; i < filmes.size(); ++i) {
            if (filmes[i].getId() == id) {
                filmes.erase(filmes.begin() + i);
                cout << "Filme removido com sucesso!\n";
                return;
            }
        }
        cout << "Filme não encontrado.\n";
    }

    /*-----------------------------
      FUNÇÃO: Buscar filme por título
    ------------------------------*/
    void buscarFilme() {
        string termo;
        cout << "\nDigite parte do título para buscar: ";
        getline(cin, termo);

        bool encontrado = false;
        for (const auto& f : filmes) {
            // Usa find() para procurar o termo dentro do título
            if (f.getTitulo().find(termo) != string::npos) {
                f.exibir();
                encontrado = true;
            }
        }

        if (!encontrado)
            cout << "Nenhum filme encontrado.\n";
    }

    /*-----------------------------
      FUNÇÃO: Salvar no arquivo
      Salva todos os filmes no arquivo "filmes.txt"
    ------------------------------*/
    void salvarNoArquivo() {
        ofstream arquivo("filmes.txt");
        for (const auto& f : filmes) {
            arquivo << f.toString() << endl;
        }
        arquivo.close();
    }

    /*-----------------------------
      FUNÇÃO: Carregar do arquivo
      Lê os filmes salvos em "filmes.txt" ao iniciar o programa
    ------------------------------*/
    void carregarDoArquivo() {
        ifstream arquivo("filmes.txt");
        if (!arquivo.is_open())
            return; // Se o arquivo não existir, não faz nada

        filmes.clear();
        string linha;

        // Lê linha por linha do arquivo CSV
        while (getline(arquivo, linha)) {
            vector<string> campos;
            size_t pos = 0;

            // Divide os campos separados por vírgulas
            while ((pos = linha.find(',')) != string::npos) {
                campos.push_back(linha.substr(0, pos));
                linha.erase(0, pos + 1);
            }
            campos.push_back(linha);

            // Se houver 5 campos válidos, cria um objeto Filme
            if (campos.size() == 5) {
                Filme f(stoi(campos[0]), campos[1], campos[2],
                        stoi(campos[3]), stod(campos[4]));
                filmes.push_back(f);
                proximoId = max(proximoId, f.getId() + 1);
            }
        }

        arquivo.close();
    }

    /*-----------------------------
      MENU PRINCIPAL
      Exibe as opções e chama as funções do CRUD
    ------------------------------*/
    void menu() {
        int opcao;
        do {
            cout << "\n===== Sistema de Gerenciamento de Filmes =====\n";
            cout << "1. Adicionar Filme\n";
            cout << "2. Listar Filmes\n";
            cout << "3. Editar Filme\n";
            cout << "4. Remover Filme\n";
            cout << "5. Buscar Filme\n";
            cout << "6. Salvar e Sair\n";
            cout << "Escolha uma opção: ";

            cin >> opcao;
            limparEntrada();

            switch (opcao) {
                case 1: adicionarFilme(); break;
                case 2: listarFilmes(); break;
                case 3: editarFilme(); break;
                case 4: removerFilme(); break;
                case 5: buscarFilme(); break;
                case 6:
                    salvarNoArquivo();
                    cout << "Dados salvos. Saindo...\n";
                    break;
                default:
                    cout << "Opção inválida. Tente novamente.\n";
            }
        } while (opcao != 6);
    }
};

/*-----------------------------------------------------------
  FUNÇÃO PRINCIPAL (main)
  Ponto de entrada do programa.
-----------------------------------------------------------*/
int main() {
    SistemaFilmes sistema; // Cria o objeto do sistema (carrega os dados automaticamente)
    sistema.menu();        // Inicia o menu principal
    return 0;
}
