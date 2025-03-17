/* Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n.
If there exists such a pair,print the pair and If no such pair exists, Print "No such pair exists "*/

#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    // Now i need to sort this array first and then make a nested for loop to solve the Question
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The entered array elements are\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    sort(arr, n);
    printf("\nEnter the difference you want to check;\n");
    int key;
    scanf("%d", &key);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] - arr[i] > key)
            {
                break;
            }
            else if (arr[j] - arr[i] == key)
            {
                printf("Yes the difference with %d exists and the pair is %d and %d\n", key, arr[i], arr[j]);
                return 0;
            }
        }
    }
    printf("No such pair is possible with difference %d\n", key);
    return 0;
}