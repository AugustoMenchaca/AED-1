#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Stack{

    int topo;
    char *string;
    int score_ab;
    int score_ba;

}Stack;

Stack *incializa(char* s){

    Stack *stack_string = (Stack*) malloc (sizeof(Stack));
    stack_string -> string = (char*) malloc( sizeof(char) * strlen(s));

    stack_string -> topo = 0;
    stack_string -> score_ab = 0;
    stack_string -> score_ba = 0;

    stack_string -> string[stack_string -> topo] = s[strlen(s) - 1];

    return stack_string;
}

int maximumGain(char* s, int x, int y) {

    Stack *stack_string = incializa(s);
    int verifica = 1;
    int tamanho = strlen(s);

    while( verifica != 0 ){
        
        verifica = 0;

        for( int i = tamanho - 2; i >= 0 ; i-- ){

            if( s[i] == 'b' || s[i] == 'a'){
                if( stack_string -> string[stack_string -> topo] == 'b' ){
                    if( s[i] == 'a'){
                        stack_string -> score_ab += x;
                        verifica++;

                    }else{
                        stack_string -> string[stack_string -> topo++] = s[i];
                        continue;
                    }
                }
                if( s[i] == 'b' ){
                    stack_string -> score_ba += y;
                    verifica++;
                }else{
                    stack_string -> string[stack_string -> topo++] = s[i];
                    continue;
                }   
                
            }else{
                stack_string -> string[stack_string -> topo++] = s[i];
            }

        }

        strcpy(s,stack_string -> string);

        tamanho = strlen(s);
    }
}

int main(){
    char string[13] ={"cdbcbbaaabab\0"};

    maximumGain(string, 4 , 5);
}