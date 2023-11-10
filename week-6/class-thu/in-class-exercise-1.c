#include <stdio.h>

#define N 5

int compare_array(int a[], int n, int value);

int main(void)
{
    int a[N] = {1, 2, 3, 4, 5};

    int returned = compare_array(a, N, 3);

    printf("%d\n", returned);

    return 0;
}

int compare_array(int a[], int n, int value)
{
    int count = 0;
    for (int *p = &a[0]; p < &a[N]; p++)
    {
        if (*p > value) count ++;
    }

    return count;
}
