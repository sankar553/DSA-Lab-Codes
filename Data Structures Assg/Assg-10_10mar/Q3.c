#include <stdio.h>

unsigned long long factorial(int num)
{
    unsigned long long result = 1;
    for (int i = 2; i <= num; i++)
    {
        result *= i;
    }
    return result;
}

unsigned long long catalan(int n)
{
    unsigned long long Nr = factorial(2 * n);
    unsigned long long Dr = factorial(n) * factorial(n + 1);

    return Nr / Dr;
}

int countBST(int n)
{
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid input. n must be non-negative.\n");
        return 1;
    }

    if (n > 12)
    {
        printf("Total number of unique BSTs with %d nodes: %d\n", n, countBST(n));
    }
    else
        printf("Total number of unique BSTs with %d nodes: %ld\n", n, catalan(n));

    return 0;
}
