#include <iostream>
#include "ListaAdjacencia.h"
#include "sstream"

using namespace std;

int main()
{
    string nome_arquivo_entrada;
    cout<<"Digite o nome do arquivo para leitura:"<<endl;
    nome_arquivo_entrada = "grafo_125";
    nome_arquivo_entrada = nome_arquivo_entrada+".txt";
    ListaAdjacencia *novo = new ListaAdjacencia(nome_arquivo_entrada);

    for(int i=0; i<=8; i++)
    {
        novo->ImprimeNos(i);
    }

    return 0;
}
