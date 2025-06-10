#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int minNumberOfFrogs(char* croakOfFrogs) {
    int i,conta=0,conta_k = 0, temp=0, conta_frogs = 0;

    bool v_o,v_r,v_a;

    int tamanho = strlen(croakOfFrogs);

    for(i = 0;i < tamanho; i++ ){
        if(croakOfFrogs[i] == 'k' ) conta_k++;

        if(croakOfFrogs[i] == 'c') conta++;
    }

    while(conta_k>0){
        v_o = false;

        v_r = false;

        v_a = false;

        for(i = temp;i < tamanho; i++){
            if(croakOfFrogs[i] == 'k') break;

            if(croakOfFrogs[i] == 'o') v_o = true;

            if(croakOfFrogs[i] == 'a') v_a = true;

            if(croakOfFrogs[i] == 'r') v_r = true;

        }
        if(v_o && v_a && v_r && (conta == conta_k)){
            conta_frogs++;
        }
        temp = i + 1;

        conta_k--;
    }
    if(conta_frogs > 0) return conta_frogs;

    return -1;
}

int main(){
    minNumberOfFrogs("crcoakroak");
}