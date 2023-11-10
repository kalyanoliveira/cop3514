#include <stdio.h>
    
#define N 5

int *find_largest(int a[], int n);

int main(void)
{
    int a[] = {3, 4, 1, 2, 5};
    int *p;

    p = find_largest(a, N); 

    printf("%d\n", *p);
}

int *find_largest(int a[], int n)
{
    int *p = &a[0];
    for (int i = 0; i < n; i++)
    {
        if (*p < a[i])
        {
            p = &a[i];
        }
    }

    return p;
}
