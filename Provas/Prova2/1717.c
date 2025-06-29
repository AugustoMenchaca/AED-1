
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
    int tamanho = strlen(s);
    stack_string -> string = (char*)malloc(sizeof(char) * strlen(s) + 1);

    stack_string -> topo = 1;
    stack_string -> score = 0;
    stack_string -> score = 0;

    stack_string -> string[0] = s[strlen(s) - 1];

    return stack_string;
}

int maximumGain(char* s, int x, int y) {

    Stack* stack_string = incializa(s);
    int tamanho = strlen(s);

    if( x > y ){
        // ab tem prioridade
        for(int i = tamanho - 2; i >= 0; i--){

            if ((s[i] == 'b' || s[i] == 'a') && stack_string -> topo > 0){

                if (stack_string -> string[stack_string -> topo - 1] == 'b' && s[i] == 'a') { 

                    stack_string -> score += x;
                    stack_string -> topo--;
                    stack_string -> string[stack_string -> topo] = '\r';

                }else{
                    stack_string -> string[stack_string -> topo] = s[i];
                    stack_string -> topo++;
                }

            }else{

                stack_string -> string[stack_string -> topo] = s[i];
                stack_string -> topo++;

            }
        }

        stack_string -> string[stack_string -> topo] ='\0';
        tamanho = strlen(stack_string -> string);

        if(tamanho == 0){
            return stack_string -> score;
        }
        
        Stack* stack_aux = incializa(stack_string -> string);

        for(int i = tamanho - 2; i >= 0; i--){
            if ((stack_string -> string[i] == 'b' || stack_string -> string[i] == 'a') && stack_aux -> topo > 0){

                if (stack_aux -> string[stack_aux -> topo - 1] == 'b' && stack_string -> string[i] == 'a') { 

                    stack_aux -> score += y;
                    stack_aux -> topo--;
                    stack_aux -> string[stack_aux -> topo] = '\r';

                }else{
                    stack_aux -> string[stack_aux -> topo] = stack_string -> string[i];
                    stack_aux -> topo++;
                }

            }else{

                stack_aux -> string[stack_aux -> topo] = stack_string -> string[i];
                stack_aux -> topo++;

            }
        }
        
        stack_string -> score += stack_aux -> score;

        free(stack_aux -> string);
        free(stack_aux);

    }else{
        // ba tem priridade
        for(int i = tamanho - 2; i >= 0; i--){

            if ((s[i] == 'b' || s[i] == 'a') && stack_string -> topo > 0){

                if ((stack_string -> string[stack_string -> topo - 1] == 'a') && s[i] == 'b' ) { 

                    stack_string -> score += y;
                    stack_string -> topo--;
                    stack_string -> string[stack_string -> topo] = '\r';

                }else{
                    stack_string -> string[stack_string -> topo] = s[i];
                    stack_string -> topo++;
                }

            }else{

                stack_string -> string[stack_string -> topo] = s[i];
                stack_string -> topo++;

            }
        }
        stack_string -> string[stack_string -> topo] ='\0';
        tamanho = strlen(stack_string -> string);

        if(tamanho == 0){
            return stack_string -> score;
        }

        Stack* stack_aux = incializa(stack_string -> string);

        for(int i = tamanho - 2; i >= 0; i--){
            if ( (stack_string -> string[i] == 'b' || stack_string -> string[i] == 'a') && stack_aux -> topo > 0){

                if (stack_aux -> string[stack_aux -> topo - 1] == 'a' && stack_string -> string[i] == 'b' && stack_aux -> topo > 0) { 

                    stack_aux -> score += x;
                    stack_aux -> topo--;
                    stack_aux -> string[stack_aux -> topo] = '\r';

                }else{
                    stack_aux -> string[stack_aux -> topo] = stack_string -> string[i];
                    stack_aux -> topo++;
                }

            }else{

                stack_aux -> string[stack_aux -> topo] = stack_string -> string[i];
                stack_aux -> topo++;

            }
        }
        stack_string -> score += stack_aux -> score;
        free(stack_aux -> string);
        free(stack_aux);
    }

    int score = stack_string -> score;

    free(stack_string -> string);
    free(stack_string);
    
    return score;
}

int main() {
    char s[] = "baab"; // x = 7, y = 6
    maximumGain(s, 5, 4);
}