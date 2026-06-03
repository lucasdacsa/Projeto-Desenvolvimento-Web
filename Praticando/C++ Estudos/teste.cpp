
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Produto {
private:
    int id;
    string nome;
    double preco;

public:
    Produto(int id, string nome, double preco) {
        this->id = id;
        this->nome = nome;
        this->preco = preco;
    }

    int getId() { return id; }
    string getNome() { return nome; }
    double getPreco() { return preco; }

    void setNome(string novoNome) { nome = novoNome; }
    void setPreco(double novoPreco) { preco = novoPreco; }

    void mostrar() {
        cout << "ID: " << id << " | Nome: " << nome << " | Preço: " << preco << endl;
    }

    string toFile() {
        return to_string(id) + ";" + nome + ";" + to_string(preco);
    }
};

vector<Produto> produtos;

// --- Funções auxiliares ---
void salvarEmArquivo() {
    ofstream arquivo("produtos.txt");
    for (auto &p : produtos) {
        arquivo << p.toFile() << endl;
    }
    arquivo.close();
}

void carregarDoArquivo() {
    ifstream arquivo("produtos.txt");
    if (!arquivo.is_open()) return;

    produtos.clear();
    string linha;
    while (getline(arquivo, linha)) {
        int id;
        string nome;
        double preco;

        size_t pos1 = linha.find(";");
        size_t pos2 = linha.find(";", pos1 + 1);

        id = stoi(linha.substr(0, pos1));
        nome = linha.substr(pos1 + 1, pos2 - pos1 - 1);
        preco = stod(linha.substr(pos2 + 1));

        produtos.push_back(Produto(id, nome, preco));
    }
    arquivo.close();
}

// --- CRUD ---
void criarProduto() {
    int id;
    string nome;
    double preco;

    cout << "ID: ";
    cin >> id;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Preço: ";
    cin >> preco;

    produtos.push_back(Produto(id, nome, preco));
    salvarEmArquivo();
}

void listarProdutos() {
    for (auto &p : produtos) {
        p.mostrar();
    }
}

void atualizarProduto() {
    int id;
    cout << "Digite o ID do produto para atualizar: ";
    cin >> id;

    for (auto &p : produtos) {
        if (p.getId() == id) {
            string nome;
            double preco;
            cout << "Novo nome: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Novo preço: ";
            cin >> preco;

            p.setNome(nome);
            p.setPreco(preco);
            salvarEmArquivo();
            return;
        }
    }
    cout << "Produto não encontrado!" << endl;
}

void deletarProduto() {
    int id;
    cout << "Digite o ID do produto para deletar: ";
    cin >> id;

    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->getId() == id) {
            produtos.erase(it);
            salvarEmArquivo();
            return;
        }
    }
    cout << "Produto não encontrado!" << endl;
}

// --- Menu ---
void menu() {
    int opcao;
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Criar produto" << endl;
        cout << "2. Listar produtos" << endl;
        cout << "3. Atualizar produto" << endl;
        cout << "4. Deletar produto" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: criarProduto(); break;
            case 2: listarProdutos(); break;
            case 3: atualizarProduto(); break;
            case 4: deletarProduto(); break;
            case 0: cout << "Saindo..." << endl; break;
            default: cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);
}

int main() {
    carregarDoArquivo();
    menu();
    return 0;
}
