#include "bonus.h"
#include <cstring>

typedef unsigned long long BIG;

bool* PrimeSieve(unsigned int N)
{
    cout << N;

    bool* is_prime = new bool[N];
    BIG* prime = new BIG[N];
    memset(is_prime, 0, sizeof(bool) * N);
    memset(prime, 0, sizeof(BIG) * N);

    for (BIG i = 2; i <= N; i++)
    {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (BIG j = 1; j <= prime[0] && i * prime[j] <= N; j++)
        {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }

    delete[] prime;
    return is_prime;
}

void GoldBachBonus(BIG* input)
{
    
}