#ifndef LISTAADJACENCIA_H_INCLUDED
#define LISTAADJACENCIA_H_INCLUDED
#include "NosDeAdjacencia.h"
#include <string>
using namespace std;


class ListaAdjacencia{
public:
    ListaAdjacencia(string val);
    ~ListaAdjacencia();
    void insereNo(int val);
    bool busca(int val);
    void ImprimeNos(int No);
    void insereAresta(int Inicio, int Destino, int Aresta);
    void VerificaTrivial();
    void VerificaNulo();
    int getGrauNo(int No);
    void RemoveNo(int val);
    void OrdemGrafo();
    bool VerificaSelfLoop(NosDeAdjacencia *p);
    void menorCaminho_Grafo(int ini, int fim);
    void imprimevetor();
    void criaVetores();


private:
    NosDeAdjacencia* primeiro;
    int NumNos;
};

#endif // LISTAADJACENCIA_H_INCLUDED
