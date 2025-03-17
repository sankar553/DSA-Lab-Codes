/*Given an array of time intervals where arr[i] = [starti, endi], the task is to merge all the overlapping intervals into one and output the result, which should only have mutually exclusive intervals. Hint: Input: arr[] = [[7, 8], [1, 5], [2, 4], [4, 6]] Output: [[1, 6], [7, 8]]*/

#include <stdio.h>
#include <stdlib.h>

void sortByStart(int arr[][2], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i][0] > arr[j][0])
            {
                temp = arr[i][0];
                arr[i][0] = arr[j][0];
                arr[j][0] = temp;
                temp = arr[i][1];
                arr[i][1] = arr[j][1];
                arr[j][1] = temp;
            }
        }
    }
}

void mergeIntervals(int arr[][2], int n)
{
    
    int i, j;
    int merged[n][2];
    int k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i][1] >= arr[j][0])
            {
                arr[i][1] = arr[j][1];
            }
            else
            {
                merged[k][0] = arr[i][0];
                merged[k][1] = arr[i][1];
                k++;
                break;
            }
        }
    }
    
    printf("\n\n[ ");
    for (i = 0; i < k; i++)
    {
        printf("[%d %d] ", merged[i][0], merged[i][1]);
    }
    printf("]\n");
}
int main()
{
    int n;
    printf("Enter the number of intervals\n");
    scanf("%d", &n);
    int arr[n][2];

    printf("Enter the intervals\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the interval %d\n", i + 1);
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    printf("The intervals before sorting are:\n");
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("[%d, %d] ", arr[i][0], arr[i][1]);
    }
    printf("]\n");

    sortByStart(arr, n);
    printf("The intervals after sorting are:\n");
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("[%d, %d] ", arr[i][0], arr[i][1]);
    }
    printf(" ]");

    mergeIntervals(arr, n);
    return 0;
}