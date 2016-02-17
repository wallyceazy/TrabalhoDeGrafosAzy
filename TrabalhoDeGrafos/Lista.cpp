#include "Lista.h"
#include "No.h"
#include <iostream>
using namespace std;
Lista::Lista()
{
    primeiro = NULL ;
}

void Lista::insereInicio(int val, int aresta)
{
    No *p = new No();
    p->setInfo(val);
    p->setAresta(aresta);
    p->setProx(primeiro);
    primeiro = p;
}

bool Lista::busca(int val)
{
    No* p = primeiro;
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

Lista::~Lista()
{
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p=t;
    }
}

void Lista::Imprime()
{
    No* p = primeiro;
    while(p!=NULL)
    {
        cout << p->getInfo()<<" ";
        p = p->getProx();
    }
    cout<<endl;
}




void Lista::RemoveLista(int val)
{
    No* p = primeiro;
    No* ant = NULL;
    No*aux;
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


}

