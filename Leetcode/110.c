#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// SEU CÓDIGO ORIGINAL - NÃO ALTERADO
typedef struct TreeNode {
    int valor;
    struct TreeNode *left;
    struct TreeNode *right;
}Node;

int verifica(struct TreeNode* filho){
    if(filho == NULL) return 0;
    int RHigh = 0, LHigh = 0;

    LHigh += verifica(filho -> left);
    RHigh += verifica(filho -> right);

    if(RHigh - LHigh > 1 || LHigh - RHigh > 1){

        return -100;

    }else {

        if(LHigh > RHigh){
            return LHigh + 1;
        }else {
            return RHigh + 1;
        }

    }

}

bool isBalanced(struct TreeNode* root) {
    if(root == NULL) return true;
    
    int Resultado;

    Resultado = verifica(root);

    if(Resultado == -100){
        return false;
    }else {
        return true;
    }
}


// Função auxiliar para criar um novo nó
struct TreeNode* novoNo(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->valor = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função principal
int main() {
    // Montando a árvore baseada em [1,2,2,3,null,null,3,4,null,null,4]
    //
    //          1
    //        /   \
    //       2     2
    //      /       \
    //     3         3
    //    /           \
    //   4             4

    struct TreeNode* root = novoNo(1);
    root->left = novoNo(2);
    root->right = novoNo(2);
    root->left->left = novoNo(3);
    root->left->left->left = novoNo(4);
    root->right->right = novoNo(3);
    root->right->right->right = novoNo(4);

    if (isBalanced(root)) {
        printf("Árvore balanceada ✅\n");
    } else {
        printf("Árvore NÃO está balanceada ❌\n");
    }

    return 0;
}