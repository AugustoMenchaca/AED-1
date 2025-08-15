#include <stdlib.h>
#include <stdio.h>

#define MAX 100000

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

int* organiza_vetor(int *vetor, ListNode *no, int contador);
int compara_int(const void *a, const void *b);


struct ListNode *sortList(struct ListNode *head)
{
    int *dados = (int *)malloc(MAX * sizeof(int));
    int *dadosOriginal = dados;

    dados = organiza_vetor(dados, head, 0);

    ListNode *passador = head;
    while (passador != NULL)
    {
        passador->val = *dados;
        dados++;
        passador = passador->next;
    }

    free(dadosOriginal);
    return head;
}

int *organiza_vetor(int *vetor, ListNode *no, int contador)
{
    if (no == NULL)
    {
        qsort(vetor, contador, sizeof(int), compara_int);

        return vetor;
    }
    vetor[contador] = no->val;

    return organiza_vetor(vetor, no->next, (contador + 1));
}

int compara_int(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}


ListNode* criarNo(int valor) {
    ListNode* novoNo = (ListNode*)malloc(sizeof(ListNode));
    novoNo->val = valor;
    novoNo->next = NULL;
    return novoNo;
}

int main() {
    ListNode* head = criarNo(4);
    head->next = criarNo(2);
    head->next->next = criarNo(1);
    head->next->next->next = criarNo(3);

    head = sortList(head);

    ListNode* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}