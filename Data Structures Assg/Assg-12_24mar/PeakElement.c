#include<stdio.h>

void peakAmong(int * arr, int n) {
    int peak = 0;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            peak = arr[i];
            break;
        }
    }
    if (peak == 0) {
        printf("No peak element found\n");
    } else {
        printf("The peak element is %d\n", peak);
    }
}
int main() {
    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        }
        peakAmong(arr, n);
        
    return 0;
}