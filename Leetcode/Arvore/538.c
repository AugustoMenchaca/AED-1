#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

struct TreeNode* convertBST(struct TreeNode* root);
int calculate(struct TreeNode* tree, int soma_esq);

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
    TreeNode* raiz = criarNo(4);
    TreeNode* no1  = criarNo(1);
    TreeNode* no6  = criarNo(6);
    TreeNode* no0  = criarNo(0);
    TreeNode* no2  = criarNo(2);
    TreeNode* no5  = criarNo(5);
    TreeNode* no7  = criarNo(7);
    TreeNode* no3  = criarNo(3);
    TreeNode* no8  = criarNo(8);

    // --- Passo 2: Ligar os nós para montar a estrutura da árvore ---
    
    // Liga os filhos da raiz (nível 1)
    raiz->left = no1;
    raiz->right = no6;

    // Liga os filhos do nó 1 e do nó 6 (nível 2)
    no1->left = no0;
    no1->right = no2;
    no6->left = no5;
    no6->right = no7;

    // Liga os filhos do nó 2 e do nó 7 (nível 3)
    // Os filhos esquerdos de 'no2' e 'no7' já são NULL por padrão
    no2->right = no3;
    no7->right = no8;

    convertBST(raiz);

    liberar_arvore(raiz);

    return 0;
}

struct TreeNode* convertBST(struct TreeNode* root) {
    calculate( root, 0 );
    
    return root;
}

int calculate(struct TreeNode* tree, int soma_acumulada){
    if (tree == NULL) return soma_acumulada;

    soma_acumulada = calculate(tree -> right, soma_acumulada );
    
    tree -> val = tree -> val + soma_acumulada;

    soma_acumulada = tree->val;

    return calculate(tree->left, soma_acumulada);
}

