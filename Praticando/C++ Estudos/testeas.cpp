#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Classe Filme
class Filme {
    int id;
    string titulo;
public:
    Filme(int i=0, string t=""):id(i),titulo(t){}
    int getId(){return id;}
    string getTitulo(){return titulo;}
    void setTitulo(string t){titulo=t;}
    string serialize(){return to_string(id)+"|"+titulo;}
    static Filme deserialize(string linha){
        int pos=linha.find('|');
        return Filme(stoi(linha.substr(0,pos)), linha.substr(pos+1));
    }
    void print(){cout<<id<<" - "<<titulo<<"\n";}
};

vector<Filme> filmes;
int nextId=1;

// Persistência
void salvar(){ofstream arq("filmes.txt");for(auto &f:filmes)arq<<f.serialize()<<"\n";}
void carregar(){
    ifstream arq("filmes.txt"); string linha; filmes.clear(); int maxId=0;
    while(getline(arq,linha)){Filme f=Filme::deserialize(linha); filmes.push_back(f); if(f.getId()>maxId)maxId=f.getId();}
    nextId=maxId+1;
}

// CRUD
void criar(){string t;cout<<"Titulo: ";getline(cin,t);filmes.push_back(Filme(nextId++,t));salvar();}
void listar(){for(auto &f:filmes)f.print();}
void atualizar(){int id;cout<<"ID: ";cin>>id;cin.ignore();for(auto &f:filmes)if(f.getId()==id){string t;cout<<"Novo titulo: ";getline(cin,t);f.setTitulo(t);salvar();}}
void deletar(){int id;cout<<"ID: ";cin>>id;cin.ignore();for(size_t i=0;i<filmes.size();i++)if(filmes[i].getId()==id){filmes.erase(filmes.begin()+i);salvar();break;}}

// Menu
int main(){carregar();int op;do{
    cout<<"\n1-Criar 2-Listar 3-Atualizar 4-Deletar 0-Sair\nOp: ";cin>>op;cin.ignore();
    switch(op){case 1:criar();break;case 2:listar();break;case 3:atualizar();break;case 4:deletar();break;}
}while(op!=0);
}
