#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int* merge2(int* vetor_L, int* vetor_R,int tamanhoL, int tamanhoR);
int* merge_sort(int* vetor, int tamanho);

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i,z;

    for(i = m , z = 0; i < nums1Size , z < n ; i++, z++ ){

        nums1[i] = nums2[z];

    }

    int* resultado = merge_sort(nums1,6);

    for (int i = 0; i < nums1Size; i++) {
        nums1[i] = resultado[i];
    }
    
    free(resultado);
}

int* merge_sort(int* vetor, int tamanho){

    if ( tamanho <= 1 ) return vetor;

    int* vetor_L, *vetor_R,*resultado;

    int meio = tamanho / 2;
    
    vetor_L = (int*)malloc(meio * sizeof(int));

    vetor_R = (int*)malloc((tamanho - meio) * sizeof(int));

    for(int i = 0; i < meio; i ++){
        vetor_L[i] = vetor[i];
    }
    for(int j = meio , z = 0; j < tamanho ; j++ , z++){
        vetor_R[z] = vetor[j];
    }

    vetor_L = merge_sort(vetor_L,meio);
    vetor_R = merge_sort(vetor_R,tamanho - meio);
    resultado = merge2(vetor_L,vetor_R,meio, tamanho - meio);

    return resultado;
}

int* merge2(int* vetor_L, int* vetor_R,int tamanhoL, int tamanhoR){

    int* resultado = (int*)malloc((tamanhoL + tamanhoR) * sizeof(int));

    int i = 0, j = 0, z = 0;

    while(i < tamanhoL || j < tamanhoR){

        if(i < tamanhoL && j < tamanhoR){

            if(vetor_L[i] <= vetor_R[j]){
                resultado[z] = vetor_L[i];
                z++;
                i++;
            }else{
                resultado[z] = vetor_R[j];
                j++;
                z++;
            }

        }else if(i < tamanhoL){
            resultado[z] = vetor_L[i];
            z++;
            i++;
        }
        else if(j < tamanhoR){
            resultado[z] = vetor_R[j];
            j++;
            z++;
        }
    }

    return resultado;
}

int main(){
    int nums1[6] = {1,2,3,0,0,0};
    int m = 3;
    int nums2[3] = {2,5,6};
    int n = 3;
    
    merge(nums1,6,m,nums2,3,n);
}