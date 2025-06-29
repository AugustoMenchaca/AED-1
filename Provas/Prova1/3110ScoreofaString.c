
#include <stdio.h>

int scoreOfString(char* s) {
    int value_s=0,total=0,antecessor=0,teste=0;
    do{
        antecessor=*s;
        *s++;
        value_s=*s;
        if(value_s==0)
            break;
        teste=antecessor-value_s;
        if(teste<0)
            teste=-teste;
        total+=teste;
    }while(*s!='\0');
    printf("%d",total);
    return 0;
}