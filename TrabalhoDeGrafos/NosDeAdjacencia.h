#ifndef NOSDEADJACENCIA_H_INCLUDED
#define NOSDEADJACENCIA_H_INCLUDED
#include "Lista.h"
class NosDeAdjacencia{
public:
    NosDeAdjacencia();
    ~NosDeAdjacencia();
    int getInfo();
    NosDeAdjacencia* getProx();
    void setInfo(int val);
    void setProx(NosDeAdjacencia *p);
    int getGrau();
    void addGrau();
    Lista* getListaDeLigacoes();


private:
    int info;
    int Grau;
    NosDeAdjacencia *prox;
    Lista *ListaDeLigacoes;

};


#endif // NOSDEADJACENCIA_H_INCLUDED
