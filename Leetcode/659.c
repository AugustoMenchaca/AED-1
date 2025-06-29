// --- ESTRUTURA E FUNÇÕES DA MIN-HEAP ---

#include <stdlib.h>
#include <stdbool.h>

// Estrutura para a Min-Heap
typedef struct {
    int* arr;       // Array de elementos
    int size;       // Número atual de elementos
    int capacity;   // Capacidade máxima do array
} MinHeap;

// Cria uma nova Min-Heap
MinHeap* create_heap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->arr = (int*)malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

// Libera a memória da heap
void free_heap(MinHeap* h) {
    if (h) {
        free(h->arr);
        free(h);
    }
}

// Função para trocar dois inteiros
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Mantém a propriedade da heap "puxando" o elemento para baixo
void heapify_down(MinHeap* h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->arr[left] < h->arr[smallest])
        smallest = left;
    if (right < h->size && h->arr[right] < h->arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify_down(h, smallest);
    }
}

// Extrai o elemento mínimo (raiz) da heap
int extract_min(MinHeap* h) {
    if (h->size <= 0) return -1; // Ou algum erro
    if (h->size == 1) {
        h->size--;
        return h->arr[0];
    }

    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapify_down(h, 0);

    return root;
}

// Insere um novo elemento na heap
void insert_heap(MinHeap* h, int value) {
    if (h->size == h->capacity) {
        // Redimensionamento (simplificado, poderia ser mais robusto)
        h->capacity *= 2;
        h->arr = (int*)realloc(h->arr, h->capacity * sizeof(int));
    }

    h->size++;
    int i = h->size - 1;
    h->arr[i] = value;

    // Mantém a propriedade da heap "puxando" o elemento para cima
    while (i != 0 && h->arr[(i - 1) / 2] > h->arr[i]) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}





int main(){
    int nums[6] = {3,1,2,0,4,5};

    isPossible( nums, 6 );
}