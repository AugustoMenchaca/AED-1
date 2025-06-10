#include <stdio.h>
#include <stdlib.h>

typedef struct {
    No* primeiro;
    No* ultimo;
}Fila;

typedef struct
{
    int dado;
    No* proximo;
}No;

void filaPOP(Fila* fila);
void filaPUSH(Fila* fila, int dado);

int tamanho_fila = 0;

Fila* filacraete(){
    Fila* novaFila = (Fila*)malloc(sizeof(Fila));

    if(novaFila == NULL) return NULL;

    novaFila->primeiro = NULL;
    novaFila -> ultimo = NULL;

    return novaFila;
}

void filaPUSH(Fila* fila, int dado){

    No* novoNo = (No*)malloc(sizeof(No));

    novoNo -> dado = dado;
    novoNo -> proximo = NULL;

    if(tamanho_fila == 0){
        fila -> primeiro = novoNo;
        fila -> ultimo = novoNo;
        novoNo -> proximo = NULL;
    }else{
        fila -> ultimo -> proximo = novoNo;
        fila -> ultimo = novoNo;
        novoNo -> proximo = NULL;
    }
}

void filaPOP(Fila* fila){

    Fila* temp;
    
    if(tamanho_fila == 0){
        printf("Lista Vazia\n");
    }

    
}
