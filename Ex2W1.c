#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void adicionar(char **p_nomes);
void remover(char **p_nomes);
void listar(char *p_nomes);
int Menu();

int main(){
    int opcao=0;
    char *nomes=NULL;

    do{
        opcao=Menu();

        switch(opcao){
            case 1 : 
            adicionar(&nomes);
            break;
            case 2 :
            remover(&nomes);
            break;
            case 3 :
            listar(nomes);
            break;
            case 4:
            exit(1);
            default:
            break;
        }   
    }while(opcao!=4);
    return 0;
}
int Menu(){
    int opcao;

    printf("Qual opcao voce deseja \n1 - Adicionar nome\n2 - Remover\n3 - Listar\n4 - Sair\n");
    scanf("%d",&opcao);
    getchar();

    return opcao;
}
void adicionar(char **nomes){
    char string[100];

    printf("Coloque os nomes:\n");
    scanf("%[^\n]",string);

    if(*nomes==NULL){
        *nomes=malloc(1);
        (*nomes)[0]='\0';
    }

    *nomes = realloc(*nomes, (strlen(*nomes) + strlen(string) + 2) * sizeof(char));

    strcat(*nomes,string);
    strcat(*nomes, " ");
}

void remover(char **p_nomes){
    char s_removido[100];
    printf("Qual nome deseja remover?\n");
    scanf("%[^\n]",s_removido);

    char *leitor = *p_nomes;
    char *escrito = *p_nomes;

    while(*leitor!='\0'){
        if(strstr(leitor,s_removido)==leitor){
            leitor+=strlen(s_removido) + 1;
        }else{
            *escrito=*leitor;
            escrito++;
            leitor++;
        }
    }
    *escrito='\0';

    *p_nomes=realloc(*p_nomes,strlen(*p_nomes)+1);
}

void listar(char *p_nomes){
    printf("%s\nTamnho da string:\n%d\n",p_nomes,sizeof(p_nomes));
    return;
}
