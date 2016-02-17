#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "No.h"
class Lista{
public:
    Lista();
    ~Lista();
    void insereInicio(int val,int aresta);
    bool busca(int val);
    void Imprime();
    void InsereFim(int val, int aresta);
    void RemoveLista(int val);

private:
    No* primeiro;

};


#endif // LISTA_H_INCLUDED
