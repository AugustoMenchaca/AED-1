#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int* dailyTemperatures(int temperaturesSize) {
    int* resultado = (int*)calloc(temperaturesSize, sizeof(int));
    int pilha[8];
    int topo = -1;
    int temperatures[] = {73,74,75,71,69,72,76,73};

    for (int i = 0; i < temperaturesSize; i++) {
        while (topo >= 0 && temperatures[i] > temperatures[pilha[topo]]) {
            int indice = pilha[topo--];
            resultado[indice] = i - indice;
        }
        pilha[++topo] = i;
    }

    return resultado;
}

int main(){

    dailyTemperatures( 8);

}

