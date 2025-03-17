#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int m, n, p;
    printf("Enter number of users (m): ");
    scanf("%d", &m);
    printf("Enter number of items (n): ");
    scanf("%d", &n);

    // Initialize random seed
    srand(time(0));

    // Calculate p (number of columns to fill)
    p = rand() % (n / 20 + 1);  // p between 0 and n/20 inclusive

    // Create arrays to store selected column indices
    int selected_columns[p];
    for (int i = 0; i < p; i++) {
        selected_columns[i] = rand() % n;
    }

    // Initialize matrices with zeros
    int A[m][n], B[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
            B[i][j] = 0;
        }
    }

    // Fill selected columns with random ratings
    for (int col = 0; col < p; col++) {
        int current_col = selected_columns[col];
        for (int row = 0; row < m; row++) {
            int rating = (rand() % 5) + 1;  // Rating between 1-5
            A[row][current_col] = rating;
            B[row][current_col] = rating;
        }
    }

    // Print matrices
    printf("\nMatrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
