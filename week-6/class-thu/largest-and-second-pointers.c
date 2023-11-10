#include <stdio.h>

#define N 10

int largest_and_second(int a[], int n, int *max0, int *max1);

int main(void)
{
    // Change this initialization to use just pointers lol.
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int big;
    int less_big;

    largest_and_second(a, N, &big, &less_big);

    printf("%d %d\n", big, less_big);
}

int largest_and_second(int a[], int n, int *max0, int *max1);
{    
    // TODO with pointers only.
}
