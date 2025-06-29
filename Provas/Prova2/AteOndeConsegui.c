#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Stack
{

    int topo;
    char* string;
    int score;

} Stack;

Stack* incializa(char* s) {

    Stack* stack_string = (Stack*)malloc(sizeof(Stack));
    stack_string -> string = (char*)malloc(sizeof(char) * strlen(s));

    stack_string -> topo = 1;
    stack_string -> score = 0;
    stack_string -> score = 0;

    stack_string -> string[0] = s[strlen(s) - 1];

    return stack_string;
}

int maximumGain(char* s, int x, int y) {

    Stack* stack_string = incializa(s);
    int tamanho = strlen(s);

    for (int i = tamanho - 2; i >= 0; i--) {

        if (s[i] == 'b' || s[i] == 'a') {
            if ( x > y ) {

                if( s[i] == 'b'){

                    stack_string -> string[stack_string  ->  topo] = s[i];
                    stack_string -> topo++;
                    continue;

                }else{
                    if (stack_string -> string[stack_string -> topo - 1] == 'b' && s[i] == 'a') { 
                        // Se ab vale mais da prioridade para ab
    
                        stack_string -> score += x;
                        stack_string -> topo--;
                        stack_string -> string[stack_string -> topo] = 'c';
    
                    }else{
                        if (stack_string -> string[stack_string -> topo - 1] == 'a' && s[i - 1] != 'a' && s[i] == 'b') { 
                            // Se nao formar um ba testa se a proxima letra sera um b para realizar um ba
                            
                            stack_string -> score += y;
                            stack_string -> topo--;
                            stack_string -> string[stack_string -> topo] = 'c';
    
                        } else {
    
                            stack_string -> string[stack_string  ->  topo] = s[i];
                            stack_string -> topo++;
                            continue;
    
                        }
                    }
                }

            } else {

                if(s[i] == 'a'){

                    stack_string -> string[stack_string  ->  topo] = s[i];
                    stack_string -> topo++;
                    continue;

                }else{

                    if (s[i] == 'b' && stack_string -> string[stack_string -> topo - 1] == 'a' ) {  
                        // Se ba valer mais q ab prioridade para ba.
    
                        stack_string -> score += y;
                        stack_string -> topo--;
                        stack_string -> string[stack_string -> topo] = 'c';
    
                    } else {
                        if (stack_string -> string[stack_string -> topo - 1] == 'b' && s[i - 1] != 'b' && s[i] == 'a') { 
                            // Se nao formar um ba testa se a proxima letra sera um b para realizar um ba
                            
                            stack_string -> score += x;
                            stack_string -> topo--;
                            stack_string -> string[stack_string -> topo] = 'c';
    
                        } else {
    
                            stack_string -> string[stack_string  ->  topo] = s[i];
                            stack_string -> topo++;
                            continue;
    
                        }
                    }

                }
            }
        } else {
            stack_string  ->  string[stack_string  ->  topo] = s[i];
            stack_string  ->  topo++;
        }
    }

    //Rodar pilha de novo para ver se passou algo
    for( int i = stack_string -> topo; i >= 0; i-- ){

        if(stack_string -> string[i] == 'b' || stack_string -> string[i] == 'a'){
            
            if(stack_string -> string[i] == 'b' && stack_string -> string[i - 1] == 'a'){
    
                stack_string -> score += y;
                stack_string -> topo--;

            }else{
    
                if(stack_string -> string[i - 1] == 'b' && stack_string -> string[i] == 'a'){

                    stack_string -> score += x;
                    stack_string -> topo--;

                }else{
                    stack_string -> topo--;
                }
            }

        }else{
            stack_string -> topo--;
        }
    }

    return stack_string -> score;
}

int main() {
    char string[13] = {"babaa\0"};

    maximumGain(string, 4, 5);
}