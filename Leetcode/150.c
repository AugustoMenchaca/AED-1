#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    int pilha[6];
    int i, posicao = 0, a, b;

    for (i = 0; i < tokensSize; i++) {
        if (strcmp(tokens[i],"+") == 0 || strcmp(tokens[i],"-") == 0 || strcmp(tokens[i],"*") == 0 ||
            strcmp(tokens[i],"/") == 0) {
            if (strcmp(tokens[i],"+") == 0) {
                a = pilha[posicao - 1];
                b = pilha[posicao - 2];
                pilha[posicao - 1] = 0;
                pilha[posicao - 2] = a + b;
                posicao = posicao - 1;
                continue;
            }
            if (strcmp(tokens[i],"-") == 0) {
                a = pilha[posicao - 1];
                b = pilha[posicao - 2];
                pilha[posicao - 1] = 0;
                pilha[posicao - 2]= a - b;
                posicao = posicao - 1;
                continue;
            }
            if (strcmp(tokens[i],"*") == 0 ) {
                a = pilha[posicao - 1];
                b = pilha[posicao - 2];
                pilha[posicao - 1] = 0;
                pilha[posicao - 2] = a * b;
                posicao = posicao - 1;
                continue;
            }
            if (strcmp(tokens[i],"/") == 0) {
                a = pilha[posicao - 1];
                b = pilha[posicao - 2];
                pilha[posicao - 1] = 0;
                pilha[posicao - 2] = b / a;
                posicao = posicao - 1;
                continue;
            }
        }else{
            pilha[posicao] = atoi(tokens[i]);
            posicao++;
        }
    }
    return pilha[0];
}

int main(){
    static char* tokens[] = {"4","13","5","/","+"};

    evalRPN(tokens,5);
}