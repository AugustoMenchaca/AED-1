#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo{
    int lugarFila;
    struct Nodo* pNext;
} Nodo;

typedef struct {
    int tamanho;
    int capacidade;

    struct Nodo* primeiro;
    struct Nodo* ultimo;

} MyCircularQueue;



MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *cabecaFila = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

    if(!cabecaFila){
        printf("Erro ao alocar");
        return NULL;
    }

    cabecaFila->capacidade = k;
    cabecaFila ->primeiro = NULL;
    cabecaFila ->ultimo = NULL;
    cabecaFila -> tamanho = 0;

    return cabecaFila;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj -> tamanho < obj -> capacidade){
        Nodo *insert = (Nodo*)malloc(sizeof(Nodo));

        if(!insert){
            printf("Erro ao alocar");
            return NULL;
        }

        if(obj -> tamanho == 0){
            obj -> primeiro = insert;
            obj -> ultimo = insert;
            obj -> tamanho++;
            
            insert -> lugarFila = value;
            insert -> pNext = NULL;
            
            return true;
        }
        
        insert -> lugarFila = value;
        
        obj -> tamanho++;
        obj -> ultimo -> pNext = insert;
        obj -> ultimo = insert;  

        insert -> pNext = obj -> primeiro;
        return true;
    }else{
        return false;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    Nodo* pTemp;

    if(obj -> tamanho > 0){

        if(obj -> tamanho == 1){
            free(obj ->primeiro);

            obj -> primeiro = NULL;
            obj -> ultimo = NULL;
            obj -> tamanho--;

            return true;
        }

        pTemp = obj -> primeiro -> pNext;
    
        free(obj ->primeiro);

        obj -> primeiro = pTemp;
        obj -> tamanho--;
        
        return true;
    }else{
        printf("Fila vazia");
        return false;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj -> tamanho == 0){
        return -1;
    }else{
        return obj -> primeiro -> lugarFila;
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj -> tamanho == 0){
        return -1;
    }else{
        return obj -> ultimo -> lugarFila;
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj -> tamanho == 0){
        return true;
    }else{
        return false;
    }
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(obj -> tamanho == obj ->  capacidade){
        return true;
    }else{
        return false;
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {

    bool verifica = true;

    while(verifica){
        verifica = myCircularQueueDeQueue(obj);
    }
}