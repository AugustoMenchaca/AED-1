#include <stdlib.h>
#include <stdio.h>

int findTheWinner(int n, int k) {
    int posicao = 0, count = 0, ultima_posicao = 0, i, posicao_vivos = 0 ,proximo = 0;
    int *numeros = (int*)malloc(sizeof(int) * n);

    for(i = 0; i < n; i++){
        numeros[i] = i + 1;
    }
    int total = n;
    i = 0;
    while(n > 1){
        ultima_posicao = k - 1 + i;
        if(ultima_posicao >= n ){
            for(ultima_posicao; ultima_posicao >= n; ultima_posicao -= n);
        }
        n--;
        
        for(i = ultima_posicao; i < n;i++){
            numeros[i] = numeros[i + 1];
        }
        numeros[i] = 0;
        i = ultima_posicao;
    }
    return numeros[0];
}

int main(){
    findTheWinner(6,5);
}