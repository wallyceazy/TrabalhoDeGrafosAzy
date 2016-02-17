#include <iostream>
#include "NosDeAdjacencia.h"
#include "ListaAdjacencia.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

ListaAdjacencia::ListaAdjacencia(string val)
{
    primeiro = NULL;
    string linha;// variavel para guardar o conteudo lido da linha
    string conteudo;
    stringstream valor;
    int inteiro;
    const char * nome = val.c_str();// converte o nome do arquivo para const char para ser aberto pelo ifstream
    ifstream arquivo(nome);// abre o arquivocout <<" este eh o inteiro " + inteiro;
    getline(arquivo,linha);// lê a primeira linha
    valor.str(linha);// joga a variavel strin na stringstream
    valor >> inteiro;//converte o valor da stringstrem para inteiro
    valor.str("");
    int No_1,No_2,ValorAresta;
    NumNos = inteiro;
    for(int i=0; i<=inteiro; i++)
    {
        insereNo(i);

    }


    while(!arquivo.eof())
    {

        int i = 0;
        getline(arquivo,linha);//pega a linha e joga na string

        while(linha[i]!=' ')
        {
            conteudo = conteudo + linha[i];

            i++;
        }
        valor.clear();
        valor.str(conteudo); // mudo conteudo da string para a stringstream
        valor >> No_1; // converto para int

        conteudo.clear();
        i++;

        while(linha[i]!=' ')
        {
            conteudo = conteudo + linha[i];
            i++;
        }
        valor.clear();
        valor.str(conteudo); // mudo conteudo da string para a stringstream
        valor >> No_2; // converto para int
        conteudo.clear();
        i++;

        while(linha[i]!='\0')
        {
            conteudo = conteudo + linha[i];
            i++;
        }
        valor.clear();
        valor.str(conteudo); // mudo conteudo da string para a stringstream
        valor >> ValorAresta; // converto para int
        conteudo.clear();
        i++;


        insereAresta(No_1,No_2,ValorAresta);
        insereAresta(No_2,No_1,ValorAresta);
    }

    arquivo.close();



}


void ListaAdjacencia::VerificaNulo()
{
    NosDeAdjacencia* p = primeiro;
    if(p==NULL)
    {
        cout<<"O Grafo eh Nulo."<<endl;

    }
    else
    {
        cout<<"O Grafo nao eh Nulo."<<endl;
    }
}

int ListaAdjacencia::getGrauNo(int val)
{
    NosDeAdjacencia* p = primeiro;
    if(busca(val))
    {
    while(p->getInfo()!=val)
    {
        p = p->getProx();

    }
     return p->getGrau();
    }
    else{
        cout<<"Erro No nao encontrado!!"<<endl;
        return -1;
    }

}
void ListaAdjacencia::VerificaTrivial()
{
    int contador=0;
    NosDeAdjacencia * p = primeiro;

    while(p!=NULL)
    {
        contador++;
        p = p->getProx();
    }
    if(contador == 1)
    {
        cout<<"O Grafo eh Trivial."<<endl;

    }
    else
    {
        cout<<"O Grafo nao eh Trivial."<<endl;
    }


}
void ListaAdjacencia::insereAresta(int Inicio, int Destino, int Aresta)
{

    NosDeAdjacencia* p = primeiro;


    if(busca(Inicio) && busca(Destino)) // busca os nos pra ver se os mesmos existem no grafo
    {
        while(p->getInfo()!=Inicio)// se existirem faz a busca onde sera inserido a aresta
        {
            p = p->getProx();

        }

            p->addGrau();//adiciona um no grau do no
            p->getListaDeLigacoes()->InsereFim(Destino,Aresta);//insere na lista de ligacoes

   }

    else
    {
        if(!busca(Inicio))
        {
            cout<<"O No de valor "<<Inicio<<" nao existe no grafo!! Ensira o No e refaca a operacao"<<endl;
        }
    }

}



bool ListaAdjacencia::VerificaSelfLoop(NosDeAdjacencia *p)
{
    return p->getListaDeLigacoes()->busca(p->getInfo());
}

void ListaAdjacencia::OrdemGrafo()
{
    NosDeAdjacencia *p = primeiro;
    int ordem = 0;

    while(p!=NULL)
    {
        if(p->getGrau()>ordem)
        {
            ordem = p->getGrau();
        }
        p = p->getProx();
    }

    cout<<"A ordem do grafo e : "<<ordem<<" !!"<<endl;
}

void ListaAdjacencia::insereNo(int val)
{
    NosDeAdjacencia *p = new NosDeAdjacencia();
    p->setInfo(val);
    p->setProx(NULL);
    NosDeAdjacencia *auxiliar = primeiro;
    NosDeAdjacencia *anterior = NULL;

    if(auxiliar == NULL || auxiliar->getInfo()>val)//Lista vazia inserir no primeiro
    {
        p->setProx(auxiliar);
        primeiro = p;
    }
    else
    {
        while(auxiliar->getProx()!=NULL && auxiliar->getInfo()<=val)
        {
            anterior = auxiliar;
            auxiliar = auxiliar->getProx();
        }
        if(auxiliar->getInfo()<val)
        {
            auxiliar->setProx(p);
        }
        else
        {
            anterior->setProx(p);
            p->setProx(auxiliar);
        }

    }
}







bool ListaAdjacencia::busca(int val)
{
    NosDeAdjacencia* p = primeiro;
    while(p!=NULL)
    {
        if(p->getInfo() == val)
        {
            return true; // achou o valor  retorna true
        }
        p = p->getProx();
    }
    return false;
}

ListaAdjacencia::~ListaAdjacencia()
{
    NosDeAdjacencia *p = primeiro;
    while(p != NULL)
    {
        NosDeAdjacencia *t = p->getProx();
        delete p;
        p=t;
    }
}
void ListaAdjacencia::ImprimeNos(int No)
{
    NosDeAdjacencia* p = primeiro;
    while(p!=NULL && p->getInfo()!=No )
    {
        p = p->getProx();

    }
    if(p!=NULL)
    {
        cout<<No<<" ";
        p->getListaDeLigacoes()->Imprime();
    }
    else
    {
        cout<<"Este No nao existe."<<endl;
    }
}

void ListaAdjacencia::RemoveNo(int val)
{
    NosDeAdjacencia* p= primeiro;
    NosDeAdjacencia* ant = NULL;
    NosDeAdjacencia* aux;
    if(busca(val))
    {
    while(p!=NULL)
    {
        if(p->getInfo()==val)
        {
            if(p == primeiro)// primeiro no da lista faz a remoção
            {
                if(p->getProx() == NULL)
                {
                    delete p;
                    primeiro = NULL;
                }
                else
                {
                    aux = p;
                    p = p->getProx();
                    primeiro = p;
                    delete aux;
                }
            }
            else if(ant != NULL && p->getProx()!=NULL)//se for um no intermediario entre 2 nos
            {
                aux = p;
                p = p->getProx();
                ant->setProx(p);
                delete aux;
            }
            else if(ant != NULL && p->getProx()==NULL)// se for o ultimo no
            {
                aux = p;
                ant->setProx(NULL);
                delete aux;
            }
        }
        else// se nao encontrar valor vai para proximo no
        {
            ant = p;
            p = p->getProx();
        }
    }
    p = primeiro;
    while(p!=NULL)// passa removendo o no em toda lista de adjacencia
    {
        p->getListaDeLigacoes()->RemoveLista(val);
        p = p->getProx();
    }

    }
    else{

        cout<<"Falha na remocao do No: "<<val<<"!! O No nao existe no grafo."<<endl;
    }

}

void ListaAdjacencia::menorCaminho_Grafo(int ini, int fim)
{
    int Caminho[NumNos];
    int dist[NumNos];
    int visitado[NumNos];
    for(int i=0; i<=NumNos; i++)
    {
        visitado[i]= 0;
        dist[i] = -1;
        Caminho[i] = -1;
    }


}










