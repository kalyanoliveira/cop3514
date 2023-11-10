#include <stdio.h>

#define N 5

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
    int arr[] = {3, 4, 2, 1, 5};
    int maximum = arr[0];
    int minimum = arr[0];

    max_min(arr, N, &maximum, &minimum);

    printf("%d %d\n", maximum, minimum);
    
    return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
    for (int i = 0; i < n; i++)
    {
        // If the dereference of max is less than the current element, the
        // current element must be the new max.
        if (*max < a[i])
        {
            *max = a[i];
        }

        // If the dereference of min is more than the current element, the
        // current element must be the new min.
        if (*min > a[i])
        {
            *min = a[i];
        }
    } 
}
