#include "NosDeAdjacencia.h"

NosDeAdjacencia::NosDeAdjacencia()
{
    ListaDeLigacoes = new Lista();    // cria um no com uma lista onde tera todas suas ligacoes
    Grau = 0;
}
NosDeAdjacencia::~NosDeAdjacencia() {} // destrutor
int NosDeAdjacencia::getInfo()
{
    return info;   // retorna indice do no
}
NosDeAdjacencia* NosDeAdjacencia::getProx()
{
    return prox;   // retorna o proximo no
}
void NosDeAdjacencia::setInfo(int val)
{
    info = val;   // atribui um valor ao no da lista
}
void NosDeAdjacencia::setProx(NosDeAdjacencia *p)
{
    prox =p;   //retorna o proximo
}
Lista* NosDeAdjacencia::getListaDeLigacoes()
{
    return ListaDeLigacoes;   // retorna a lista de ligações
}
void NosDeAdjacencia::addGrau()
{
    Grau = Grau+1;
}
int NosDeAdjacencia::getGrau()
{
    return Grau;
}
