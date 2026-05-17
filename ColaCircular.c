#include "ColaCircular.h"

void crearColaC(tColaC* pc)
{
    *pc = NULL;
}

int ponerEnColaC(tColaC* pc, const void* pd, unsigned tam)
{
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEMORIA;

    nue->info = malloc(sizeof(tam));
    if(!nue->info)
    {
        free(nue);
        return SIN_MEMORIA;
    }

    nue->tamInfo = tam;
    memcpy(nue->info, pd, tam);

    if(!*pc)
        nue->sig = nue;
    else
    {
        nue->sig = (*pc)->sig;
        (*pc)->sig = nue;
    }
    *pc = nue;

    return TODO_OK;
}

int sacarDeColaC(tColaC* pc, void* pd, unsigned tam)
{
    tNodo* elim;

    if(!*pc)
        return COLA_VACIA;

    elim = (*pc)->sig;
    memcpy(pd, elim->info, MINIMO(elim->tamInfo, tam));

    if(elim->sig == elim)
        *pc =NULL;
    else
        (*pc)->sig = elim->sig;

    free(elim->info);
    free(elim);

    return TODO_OK;
}

int esColaCVacia(tColaC* pc)
{
    return !*pc;
}

int esColaCLlena(tColaC* pc, const void* pd, unsigned tam)
{
    void* nodo = malloc(sizeof(tNodo));
    void* info = malloc(tam);

    free(nodo);
    free(info);

    return (!nodo || !info);
}
