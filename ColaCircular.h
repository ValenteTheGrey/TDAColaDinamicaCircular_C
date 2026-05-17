#ifndef COLACIRCULAR_H_INCLUDED
#define COLACIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define SIN_MEMORIA 1
#define COLA_VACIA 2

#define MINIMO(a,b)     ((a) < (b) ? (a) : (b))

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tColaC;

void crearColaC(tColaC* pc);
int ponerEnColaC(tColaC* pc, const void* pd, unsigned tam);
int sacarDeColaC(tColaC* pc, void* pd, unsigned tam);
int esColaCVacia(tColaC* pc);
int esColaCLlena(tColaC* pc, const void* pd, unsigned tam);

#endif // COLACIRCULAR_H_INCLUDED
