#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long fatorial(int fator);
long long comb(int sub_l, int tamanho);
long long calc_rec(int* nums, int numsSize);

int numOfWays(int *nums, int numsSize)
{
    return (calc_rec(nums, numsSize) - 1 + MOD) % MOD;
}

long long calc_rec(int* nums, int numsSize)
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

    long long comb_L = calc_rec(left_tree, contadorL);
    long long comb_R = calc_rec(right_tree, contadorR);

    long long atual_comb = comb(contadorL, contadorL + contadorR);

    free(left_tree);
    free(right_tree);

    return (((atual_comb * comb_L) % MOD) * comb_R) % MOD;
}

long long comb(int sub_l, int tamanho)
{
    long long fat_sub = fatorial(sub_l);
    long long fat_tamanho = fatorial(tamanho);
    long long fat_divisao = fatorial(tamanho - sub_l);

    long long denominador = (fat_sub * fat_divisao) % MOD;

    long long inv_denom = 1, base = denominador, expo = MOD - 2;
    while (expo > 0) {
        if (expo % 2 == 1) inv_denom = (inv_denom * base) % MOD;
        base = (base * base) % MOD;
        expo /= 2;
    }

    return (fat_tamanho * inv_denom) % MOD;
}
long long fatorial(int fator)
{
    if (fator < 1)
        return 1;
    return (fator * fatorial(fator - 1)) % MOD;
}

int main()
{
    int nums[] = {3, 1, 2, 5, 4, 6};

    int numsSize = 6;

    int resposta = numOfWays(nums, numsSize);
}