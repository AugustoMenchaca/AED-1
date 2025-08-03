#include <stdio.h>
#include <stdlib.h>

int fatorial(int fator);
int comb(int sub_l, int tamanho);

int numOfWays(int *nums, int numsSize)
{

    if (numsSize < 3)
    {
        return 1;
    }
    int i;
    int *left_tree = (int *)malloc(sizeof(int) * numsSize);
    int *right_tree = (int *)malloc(sizeof(int) * numsSize);
    int contadorL = 0, contadorR = 0;

    for (i = 1; i < numsSize; i++)
    {
        if (nums[0] > nums[i])
        {
            left_tree[contadorL] = nums[i];
            contadorL++;
        }
        else
        {
            right_tree[contadorR] = nums[i];
            contadorR++;
        }
    }

    int comb_L = numOfWays(left_tree, contadorL);
    int comb_R = numOfWays(right_tree, contadorR);

    int atual_comb = comb(contadorL, numsSize);

    free(left_tree);
    free(right_tree);

    return (atual_comb * comb_L * comb_R) - 1;
}

int comb(int sub_l, int tamanho)
{

    int fat_sub = fatorial(sub_l);

    int fat_tamanho = fatorial(tamanho - 1);

    int fat_divisao = fatorial(tamanho - 1 - sub_l);

    return fat_tamanho / ((fat_sub) * (fat_divisao));
}

int fatorial(int fator)
{
    if (fator < 1)
        return 1;

    return fator * fatorial(fator - 1);
}

int main()
{
    int nums[] = {3, 1, 2, 5, 4, 6};

    int numsSize = 6;

    int resposta = numOfWays(nums, numsSize);
}