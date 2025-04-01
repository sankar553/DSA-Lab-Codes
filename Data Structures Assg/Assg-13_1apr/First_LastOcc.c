#include <stdio.h>

int Firstindex(int arr[], int n, int target)
{
    int left = 0, right = n - 1, result = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            result = mid;
            right = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

int Lastindex(int arr[], int n, int target)
{
    int left = 0, right = n - 1, result = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            result = mid;
            left = mid + 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

int main()
{
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    int first = Firstindex(arr, n, target);
    int last = Lastindex(arr, n, target);

    if (first == -1 || last == -1)
    {
        printf("Element not found\n");
    }
    else if (first == last)
    {
        printf("Element found at index: %d (found only one time)\n", first);
    }
    else
    {
        printf("First occurrence at index: %d\n", first);
        printf("Last occurrence at index: %d\n", last);
    }

    return 0;
}
