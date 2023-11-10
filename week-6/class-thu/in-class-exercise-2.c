#include <stdio.h>

#define N 3

void multi_vec (int v1[], int v2[], int v3[], int n);

int main(void)
{
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[3] = {0};

    multi_vec(a, b, c, N); 

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", c[i]);
    }
    
    return 0;
}

void multi_vec (int v1[], int v2[], int v3[], int n)
{
    for (int *p = &v1[0], *q = &v2[0], *r = &v3[0]; p < &v1[N]; p++, q++, r++)
    {
        int value = *p * *q;
        *r = value;
    }
}
