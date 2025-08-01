#include <stdio.h>
#include <stdlib.h>


// Sua definição da struct TreeNode
typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int* preorderTraversal(struct TreeNode* root, int* returnSize);
int* value_vetor(struct TreeNode* root,int* vetor,int* posicao);

TreeNode* criarNo(int val) {
    TreeNode* novoNo = (TreeNode*)malloc(sizeof(TreeNode));
    if (novoNo == NULL) {
        perror("Falha ao alocar memória para o nó");
        exit(EXIT_FAILURE);
    }
    novoNo->val = val;
    novoNo->left = NULL;
    novoNo->right = NULL;
    return novoNo;
}
int main() {

    // 1. Criar os nós individuais
    TreeNode* raiz = criarNo(10);
    TreeNode* no5  = criarNo(5);
    TreeNode* no20 = criarNo(20);
    TreeNode* no3  = criarNo(3);
    TreeNode* no7  = criarNo(7);
    TreeNode* no15 = criarNo(15);

    // 2. Ligar os nós para montar a estrutura da árvore
    raiz->left = no5;
    raiz->right = no20;

    no5->left = no3;
    no5->right = no7;

    no20->left = no15;
    
    int* returnsize = 0;
    int* vetor = preorderTraversal(raiz,returnsize);
    free(raiz);
    free(no5);
    free(no20);
    free(no3);
    free(no7);
    free(no15);


    return 0;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    int* vetor = NULL;
    int* posicao = (int*)malloc(sizeof(int));
    *posicao = 0;

    vetor = value_vetor(root, vetor, posicao);

    *returnSize = *posicao;

    free(posicao);

    return vetor;
}


int* value_vetor(struct TreeNode* root,int* vetor,int* posicao){
    if(root == NULL) return vetor;

    vetor = (int*)realloc(vetor, (*posicao + 1) * sizeof(int));

    vetor[*posicao] = root -> val;
    (*posicao)++;

    vetor = value_vetor(root -> left,vetor,posicao);
    vetor = value_vetor(root -> right,vetor,posicao);

    return vetor;
}