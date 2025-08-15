#include <stdlib.h>
#include <stdio.h>

int *organiza_vetor(int *vetor, ListNode *no, int contador);
int compara_int(const void *a, const void *b);

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode *sortList(struct ListNode *head)
{
    int *dados = (int *)malloc(sizeof(int));

    dados = organiza_vetor(dados, head, 0);

    ListNode *passador = head;

    while (passador != NULL)
    {

        passador->val = *dados;

        dados++;
        passador = passador->next;
    }

    free(dados);

    return head;
}

int *organiza_vetor(int *vetor, ListNode *no, int contador)
{
    if (no == NULL)
    {
        qsort(vetor, contador, sizeof(int), compara_int);

        return vetor;
    }

    vetor = realloc(vetor, (contador + 1) * sizeof(int));
    vetor[contador] = no->val;

    return organiza_vetor(vetor, no->next, (contador + 1));
}

int compara_int(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
