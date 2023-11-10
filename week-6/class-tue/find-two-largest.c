#include <stdio.h>

#define N 5

void find_two_largest(int a[], int n, int *max0, int *max1);

int main(void)
{
    int a[] = {34, 78, 3889, 89, 244};
    int first_maximum, second_maximum;

    find_two_largest(a, N, &first_maximum, &second_maximum);
    
    printf("%d %d\n", first_maximum, second_maximum);

    return 0;
}

void find_two_largest(int a[], int n, int *max0, int *max1)
{
    // Check the first two elements
    if (a[0] > a[1])
    {
        *max0 = a[0];
        *max1 = a[1];
    }
    else
    {
        *max0 = a[1];
        *max1 = a[0];
    }

    // For each elements after the first two elements.
    for (int i = 2; i < n; i++)
    {
        int curr = a[i];
        // If the current element is larger than max0...
        if (curr > *max0)
        {
            // max1 gets max0, and max0 gets curr.
            *max1 = *max0;
            *max0 = curr;
        }
        else 
        {
            // If the current element is less than max0 AND it is larger than
            // max1...
            if (curr > *max1)
            {
                // max1 gets the current element.
                *max1 = curr; 
            }
        }
    }
}
