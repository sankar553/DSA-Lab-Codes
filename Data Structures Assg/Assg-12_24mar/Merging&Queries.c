#include <stdio.h>
#include <stdlib.h>

void merge(int arr[][2], int n, int *final, int *size)
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i][0]; j <= arr[i][1]; j++)
        {
            final[index++] = j;
        }
    }
    *size = index;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int arr[n][2];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the range %d (start and end): ", i + 1);
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    int final[1000];
    int size = 0;
    int k[q], result;

    merge(arr, n, final, &size);

    printf("Enter queries : ");
    for (int j = 0; j < q; j++)
    {
        scanf("%d", &k[j]);
    }
    printf("The Queries are recorded as\n");
    for (int j = 0; j < q; j++)
    {
        printf("%d, ", k[j]);
    }

    for (int i = 0; i < q; i++)
    {

        if (k[i] > size)
        {
            result = -1;
        }
        else
        {
            int key = k[i] - 1;
            result = final[key];
        }
        printf("%d, ", result);
    }

    return 0;
}
