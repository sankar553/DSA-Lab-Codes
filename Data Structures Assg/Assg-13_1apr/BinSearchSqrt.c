#include <stdio.h>

int BinSearchSqroot(int n) {
    if (n == 0 || n == 1) return n; 
    
    int left = 1, right = n, result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int square = mid * mid;
        
        if (square == n) {
            return mid; 
        } else if (square < n) {
            result = mid; 
            left = mid + 1;
        } else {
            right = mid - 1; 
        }
    }
    return result; 
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Invalid input! Enter a positive integer.\n");
        return 1;
    }
    
    int sqrtN = BinSearchSqroot(n);
    if (sqrtN * sqrtN == n) {
        printf("The number %d is a perfect Square and the it's square root is: %d\n", n, sqrtN);
    } else if (n-sqrtN*sqrtN <(sqrtN +1)*(sqrtN+1)-n) {
        printf("The number %d is not a perfect Square and the it's square root is: %d\n", n, sqrtN);
    } else {
        sqrtN++;
        printf("The number %d is not a perfect Square and the it's square root is: %d\n", n, sqrtN);
    }
    
    return 0;
}
