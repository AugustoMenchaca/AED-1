#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
    int valor_mesa;
    struct No* pNext;
}No;


typedef struct {
    int tamanho;
    int capacidade;

    struct No* primeiro;
    struct No* ultimo;
} SeatManager;

No *alocaNodo(SeatManager *obj){

    if(obj -> tamanho < obj -> capacidade){
        No* insert = (No*)malloc(sizeof(No));

        if(!insert){
            printf("Erro ao alocar");
            return NULL;
        }

        
        if(obj -> tamanho == 0){
            obj -> primeiro = insert;
            obj -> ultimo = insert;
            
            obj -> tamanho++;

            insert -> pNext = NULL;
            insert -> valor_mesa = obj -> tamanho;
            
            return insert;
        }
        
        obj -> tamanho++;

        obj -> ultimo -> pNext = insert;
        obj -> ultimo = insert;
        insert -> pNext = NULL;

        insert -> valor_mesa = obj -> tamanho;

        return insert;
    }else{
        return NULL;
    }
}


SeatManager* seatManagerCreate(int n) {
    
    SeatManager* cabecaFila = (SeatManager*)malloc(sizeof(SeatManager));

    if(!cabecaFila){
        printf("Erro ao alocar");
        return NULL;
    }

    cabecaFila -> capacidade = n;
    cabecaFila -> tamanho = 0;

    for( int i = 0; i < n; i++){
        alocaNodo( cabecaFila);
    }

    return cabecaFila;
}


int seatManagerReserve(SeatManager* obj) {

    int valor;

    No* pTemp;

    if(obj -> tamanho > 0){

        if(obj -> tamanho == 1){
            valor = obj -> primeiro -> valor_mesa;
            free(obj ->primeiro);

            obj -> primeiro = NULL;
            obj -> ultimo = NULL;
            obj -> tamanho--;

            return valor;
        }

        valor = obj -> primeiro -> valor_mesa;
        pTemp = obj -> primeiro -> pNext;

        free(obj -> primeiro);

        obj -> primeiro = pTemp;
        obj -> tamanho--;

        return valor;
    }else{
        return -1;
    }
    
}

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {
    No* insert = (No*)malloc(sizeof(No));
    No* pTemp = obj->primeiro;
    No* pAnterior = NULL;

    if (!insert) {
        printf("Erro ao alocar");
        return;
    }

    insert -> valor_mesa = seatNumber;

    if (obj -> primeiro == NULL) {
        obj -> primeiro = insert;
        obj -> ultimo = insert;
        insert -> pNext = NULL;
        obj -> tamanho++;
        return;
    }

    if (seatNumber < obj -> primeiro -> valor_mesa) {
        insert -> pNext = obj -> primeiro;
        obj -> primeiro = insert;
        obj->tamanho++;
        return;
    }

    while (pTemp != NULL && seatNumber > pTemp->valor_mesa) {
        pAnterior = pTemp;
        pTemp = pTemp->pNext;
    }

    insert->pNext = pTemp;

    if (pAnterior == NULL) {
        obj->primeiro = insert;
    } else {
        pAnterior->pNext = insert;
    }

    if (insert->pNext == NULL) {
        obj->ultimo = insert;
    }

    obj->tamanho++;
}

void seatManagerFree(SeatManager* obj) {
    if (!obj) return;

    No *pTemp = obj->primeiro;

    while (pTemp != NULL) {
        No* prox = pTemp->pNext;
        free(pTemp);
        pTemp = prox;
    }

    obj->primeiro = NULL;
    obj->ultimo = NULL;

    free(obj);
}
