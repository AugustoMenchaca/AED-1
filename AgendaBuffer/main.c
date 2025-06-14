#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu(void* pBuffer);
void* Adicionar(void* pBuffer);
void* Remover(void* pBuffer);
void Listar(void* pBuffer);
void* Buscar(void* pBuffer);
void* Buscar_Nome(void* pBuffer);
void* Buscar_Email(void* pBuffer);
void* Remover_Nome(void* pBuffer);
void* Remover_Email(void* pBuffer);

int main(){
    void* pBuffer = NULL;

    pBuffer = malloc(sizeof(int) * 4);
    int* pMenu = (int*) pBuffer;
    int* pTamanho_buffer = (int*)((char*) pBuffer + sizeof(int));
    int* pQuantidade_pessoas = (int*)((char*) pBuffer + sizeof(int) * 2);
    int* pVariavel = (int*)((char*) pBuffer + sizeof(int) * 3);

    *pMenu = 0;
    *pTamanho_buffer = sizeof(int) * 4;
    *pQuantidade_pessoas = 0;
    *pVariavel = 0;


    while(*pMenu != 5){

        *pMenu = Menu(pBuffer);

        switch(*pMenu){
            case 1:
            pBuffer = Adicionar(pBuffer);
            break;
            
            case 2:
            Listar(pBuffer);
            break;
            
            case 3:
            pBuffer = Buscar(pBuffer);
            break;

            case 4:
            pBuffer = Remover(pBuffer);
            break;

            case 5:
            free(pBuffer);
            exit(0);
        }
        pMenu = (int*) pBuffer;
    }
    free(pBuffer);
    return 0;
}

int Menu(void* pBuffer){

    int* escolha =(int*) pBuffer;

    printf("\t---------------------\n");
    printf("\tEscolha sua opcao:\n");
    printf("\t1 - Adicionar pessoa\n");
    printf("\t2 - Listar pessoas\n");
    printf("\t3 - Buscar pessoa\n");
    printf("\t4 - Remover pessoa\n");
    printf("\t5 - Sair\n");
    printf("\t---------------------\n");
    scanf("\t%d",escolha);

    return *escolha;
}

void* Adicionar(void* pBuffer) {
    int* pTamanho_buffer = (int*)((char*)pBuffer + sizeof(int));
    int* pQuantidade_pessoas = (int*)((char*)pBuffer + sizeof(int) * 2);

    pBuffer = realloc(pBuffer, *pTamanho_buffer + 50);
    pTamanho_buffer = (int*)((char*)pBuffer + sizeof(int));
    pQuantidade_pessoas = (int*)((char*)pBuffer + sizeof(int) * 2);

    char* pNome = (char*)pBuffer + *pTamanho_buffer;

    printf("\tDigite seu nome: \n");
    scanf(" \t%[^\n]", pNome);

    pBuffer = realloc(pBuffer, *pTamanho_buffer + strlen(pNome) + 1 + 100);
    pTamanho_buffer = (int*)((char*)pBuffer + sizeof(int));
    char* pEmail = (char*)pBuffer + *pTamanho_buffer + strlen(pNome) + 1;

    printf("\tDigite seu email: \n");
    scanf(" \t%[^\n]", pEmail);

    pBuffer = realloc(pBuffer, *pTamanho_buffer + strlen(pNome) + 1 + strlen(pEmail) + 1 + sizeof(int));
    pTamanho_buffer = (int*)((char*)pBuffer + sizeof(int));
    pQuantidade_pessoas = (int*)((char*)pBuffer + sizeof(int) * 2);
    int* pIdade = (int*)((char*)pBuffer + *pTamanho_buffer + strlen(pNome) + 1 + strlen(pEmail) + 1);

    printf("\tDigite sua idade: \n");
    scanf("\t%d", pIdade);

    (*pQuantidade_pessoas)++;
    *pTamanho_buffer += strlen(pNome) + 1 + strlen(pEmail) + 1 + sizeof(int);

    return pBuffer;
}

void* Remover(void* pBuffer){

    int* escolha = (int*)pBuffer;
    int* pQuantidade_pessoas = (int*)((char*) pBuffer + sizeof(int) * 2);
    
    if(*pQuantidade_pessoas <=0){
        printf("\tAgenda vazia.\n");
        return pBuffer;
    }

    printf("\tDeseja remover por nome ou email: \n");
    printf("\t1 - Por nome \n");
    printf("\t2 - Por email \n");
    scanf("\t%d",escolha);

    if(*escolha == 1)pBuffer = Remover_Nome(pBuffer);else{
        pBuffer = Remover_Email(pBuffer);
    }

    return pBuffer;
}

void Listar(void* pBuffer){
    
    int* pVariavel = (int*)((char*) pBuffer + sizeof(int) * 3);
    int* pQuantidade_pessoas = (int*)((char*) pBuffer + sizeof(int) * 2);

    if(*pQuantidade_pessoas <=0){
        printf("\tAgenda vazia.\n");
        return;
    }
    
    printf("\tListando...\n");
    char* Lista_nome = (char*)pBuffer + sizeof(int) * 4;
    for(*pVariavel = 0; *pVariavel < *pQuantidade_pessoas; (*pVariavel)++){

        char* Lista_email = Lista_nome + strlen(Lista_nome) + 1;
        int* Lista_idade = (int*)(Lista_email + strlen(Lista_email) + 1);

        printf("\t---------------------\n");
        printf("\tNome: %s\n",Lista_nome);
        printf("\tEmail: %s\n",Lista_email);
        printf("\tIdade: %d\n",*Lista_idade);
        printf("\t---------------------\n");

        Lista_nome =(char*)(Lista_idade + 1);
    }
}

void* Buscar(void* pBuffer){

    int* escolha = (int*)pBuffer;

    int* pQuantidade_pessoas = (int*)((char*) pBuffer + sizeof(int) * 2);
    
    if(*pQuantidade_pessoas <=0){
        printf("\tAgenda vazia.\n");
        return pBuffer;
    }
    
    printf("\tDeseja buscar por nome ou email:\n");
    printf("\t1 - Buscar por nome\n");
    printf("\t2 - Buscar por email\n");
    scanf("%d",escolha);

    if(*escolha == 1) return Buscar_Nome(pBuffer);else{
        return Buscar_Email(pBuffer);
    }
}

void* Buscar_Nome(void* pBuffer){
    int* pTamanho_buffer = (int*)((char*) pBuffer + sizeof(int));
    
    pBuffer = realloc(pBuffer,*pTamanho_buffer + 50);
    pTamanho_buffer = (int*)((char*) pBuffer + sizeof(int));
    int* pQuantidade_pessoas = (int*)((char*)pBuffer + sizeof(int) * 2);
    
    char* nome = (char*)pBuffer + *pTamanho_buffer;
    
    printf("Qual o nome voce desejar buscar: \n");
    scanf(" %[^\n]",nome);
    
    int* pVariavel = (int*) ((char*)pBuffer + sizeof(int) * 3);
    
    char* Busca_nomes = (char*)pBuffer + sizeof(int) * 4;
    for(*pVariavel = 0; *pVariavel < *pQuantidade_pessoas; (*pVariavel)++){
        char* Busca_emails = Busca_nomes + strlen(Busca_nomes) + 1;
        int* Busca_idade = (int*)(Busca_emails + strlen(Busca_emails) + 1);
        
        if(strcmp(nome,Busca_nomes) == 0){
            printf("\t---------------------\n");
            printf("\tNome: %s\n",Busca_nomes);
            printf("\tEmail: %s\n",Busca_emails);
            printf("\tIdade: %d\n",*Busca_idade);
            printf("\t---------------------\n");
            pBuffer = realloc(pBuffer,*pTamanho_buffer);
            return pBuffer;
        }
        Busca_nomes =(char*)(Busca_idade + 1);
    }
    
    printf("Esse nome nao existe no Banco de dados");
    
    pBuffer = realloc(pBuffer,*pTamanho_buffer);

    return pBuffer;
}
void* Buscar_Email(void* pBuffer){
    int* pTamanho_buffer = (int*)((char*) pBuffer + sizeof(int));
    
    pBuffer = realloc(pBuffer,*pTamanho_buffer + 100);
    int* pQuantidade_pessoas = (int*)((char*)pBuffer + sizeof(int) * 2);
    pTamanho_buffer = (int*)((char*) pBuffer + sizeof(int));
    
    char* email = (char*)pBuffer + *pTamanho_buffer;
    
    printf("Qual o email voce desejar buscar: \n");
    scanf(" %[^\n]",email);
    
    int* pVariavel = (int*) ((char*)pBuffer + sizeof(int) * 3);
    
    char* Busca_nomes = (char*)pBuffer + sizeof(int) * 4;
    for(*pVariavel = 0; *pVariavel < *pQuantidade_pessoas; (*pVariavel)++){
        char* Busca_emails = Busca_nomes + strlen(Busca_nomes) + 1;
        int* Busca_idade = (int*)(Busca_emails + strlen(Busca_emails) + 1);
        
        if(strcmp(email,Busca_emails) == 0){
            printf("\t---------------------\n");
            printf("\tNome: %s\n",Busca_nomes);
            printf("\tEmail: %s\n",Busca_emails);
            printf("\tIdade: %d\n",*Busca_idade);
            printf("\t---------------------\n");
            
            pBuffer = realloc(pBuffer,*pTamanho_buffer);
            return pBuffer;
        }
        Busca_nomes =(char*)(Busca_idade + 1);
    }
    
    printf("Esse email nao existe no Banco de dados\n");
    pBuffer = realloc(pBuffer,*pTamanho_buffer);

    return pBuffer;
}

void* Remover_Nome(void* pBuffer){
    int* pTamanho_buffer = (int*)((char*) pBuffer + sizeof(int));
    
    pBuffer = realloc(pBuffer,*pTamanho_buffer + 50);
    pTamanho_buffer = (int*)((char*) pBuffer + sizeof(int));
    int* pQuantidade_pessoas = (int*)((char*)pBuffer + sizeof(int) * 2);
    
    char* nome = (char*)pBuffer + *pTamanho_buffer;
    
    printf("Qual o nome voce desejar buscar: \n");
    scanf(" %[^\n]",nome);
    
    int* pVariavel = (int*) ((char*)pBuffer + sizeof(int) * 3);
    
    char* Busca_nomes = (char*)pBuffer + sizeof(int) * 4;
    for(*pVariavel = 0; *pVariavel < *pQuantidade_pessoas; (*pVariavel)++){
        char* Busca_emails = Busca_nomes + strlen(Busca_nomes) + 1;
        int* Busca_idade = (int*)(Busca_emails + strlen(Busca_emails) + 1);
        
        if(strcmp(nome,Busca_nomes) == 0){
            char* src = (char*)(Busca_idade + 1);

            int* pTotal_pessoa =  (int*) pBuffer;

            *pTotal_pessoa = strlen(Busca_nomes) + 1 + strlen(Busca_emails) + 1 + sizeof(int);
            
            memmove(Busca_nomes, src, (*pTamanho_buffer) - (src - (char*)pBuffer));
            
            *pTamanho_buffer -= *pTotal_pessoa;
            (*pQuantidade_pessoas)--;
            
            pBuffer = realloc(pBuffer,*pTamanho_buffer);
            
            return pBuffer;
        }
        
        Busca_nomes =(char*)(Busca_idade + 1);
    }
    
    printf("Nao temos esse nome no banco de dados\n");
    return pBuffer;
}

void* Remover_Email(void* pBuffer){
    int* pTamanho_buffer = (int*)((char*) pBuffer + sizeof(int));
    
    pBuffer = realloc(pBuffer,*pTamanho_buffer + 100);
    pTamanho_buffer = (int*)((char*) pBuffer + sizeof(int));
    int* pQuantidade_pessoas = (int*)((char*)pBuffer + sizeof(int) * 2);

    char* pRemoveEmail = (char*)pBuffer + *pTamanho_buffer;

    printf("Qual o email voce desejar buscar: \n");
    scanf(" %[^\n]",pRemoveEmail);

    int* pVariavel = (int*) ((char*)pBuffer + sizeof(int) * 3);

    char* Busca_nomes = (char*)pBuffer + sizeof(int) * 4;
    for(*pVariavel = 0; *pVariavel < *pQuantidade_pessoas; (*pVariavel)++){
        char* Busca_emails = Busca_nomes + strlen(Busca_nomes) + 1;
        int* Busca_idade = (int*)(Busca_emails + strlen(Busca_emails) + 1);

        if(strcmp(pRemoveEmail,Busca_emails) == 0){

            char* src = (char*)(Busca_idade + 1);

            int* pTotal_pessoa =  (int*) pBuffer;

            *pTotal_pessoa = strlen(Busca_nomes) + 1 + strlen(Busca_emails) + 1 + sizeof(int);
            
            memmove(Busca_nomes, src, (*pTamanho_buffer) - (src - (char*)pBuffer));
            
            *pTamanho_buffer -= *pTotal_pessoa;
            (*pQuantidade_pessoas)--;
            
            pBuffer = realloc(pBuffer,*pTamanho_buffer);
            
            return pBuffer;
        }

        Busca_nomes =(char*)(Busca_idade + 1);
    }

    printf("Nao temos esse email no banco de dados\n");
    return pBuffer;
}