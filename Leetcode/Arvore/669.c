/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>
#include <stdio.h>
typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

struct TreeNode* trimBST(struct TreeNode* root, int low, int high) ;

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

void liberar_arvore(TreeNode* no) {
    if (no == NULL) {
        return;
    }
    liberar_arvore(no->left);
    liberar_arvore(no->right);
    free(no);
}


int main() {
    // --- Passo 1: Criar os nós individuais da árvore ---
    TreeNode* raiz = criarNo(3);
    TreeNode* no0  = criarNo(0);
    TreeNode* no4  = criarNo(4);
    TreeNode* no2  = criarNo(2);
    TreeNode* no1  = criarNo(1);

    // --- Passo 2: Ligar os nós para montar a estrutura ---
    raiz->left = no0;
    raiz->right = no4;

    no0->right = no2; // O filho esquerdo de 0 é NULL (padrão)

    no2->left = no1;

    trimBST(raiz,1,3);

    liberar_arvore(raiz);

    return 0;
}
struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    if(root == NULL) return NULL;

    if(root -> val < low){
        return trimBST(root -> right, low, high);
    }

    if(root -> val > high){
        return trimBST(root -> left, low, high);
    }

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    
    return root;
}