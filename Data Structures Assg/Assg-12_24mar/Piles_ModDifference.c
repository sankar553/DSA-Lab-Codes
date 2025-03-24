
#include <stdio.h>

int main()
{
    int N, K;
    printf("Enter the number of piles and the maximum difference allowed between the piles : ");
    scanf("%d %d", &N, &K);
    int arr[N];
    int min = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        if (i == 0)
        {
            min = arr[i];
        }
        else
        {
            min = min < arr[i] ? min : arr[i];
        }
    }
    printf("The entered array is :\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The minimum element in the array is : %d\n", min); // Here the logic was that if the difference is more than K then i will remove those specific number of coins from the respective piles to satisfy the condition.
    for (int i = 0; i < N; i++)
    {
        if (arr[i] - min > K)
        {
            count += arr[i] - min - K;
        }
    }
    printf("The minimum number of coins to be removed is : %d\n", count);
    return 0;
}