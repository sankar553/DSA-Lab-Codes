#include <stdio.h>
static int comparisons = 0;

int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        comparisons++;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int number;
    printf("Enter a number of elements to store in the Array: ");
    scanf("%d", &number);
    int arr[number];

    printf("Enter %d numbers (in increasing order) to store in the Array: ", number);
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &arr[i]);
        if (i != 0 && arr[i - 1] > arr[i])
        {
            printf("Enter a larger number than %d\n", arr[i - 1]);
            i--;
            continue;
        }
    }
    printf("Enter a target number to search ");
    int target;
    scanf("%d", &target);
    int result = binarySearch(arr, 0, number - 1, target);
    if (result == -1)
        printf("Element not found\n");
    else
    {
        printf("Element found at index %d\n", result);
        printf("The number of comparisions made = %d\n", comparisons);
    }

    printf("The resulting array was: \n");
    for (int i = 0; i < number; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}