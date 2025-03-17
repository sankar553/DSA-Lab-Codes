#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int p,n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
        p = (rand() % (n / 20));
    printf("%d ", p);
}