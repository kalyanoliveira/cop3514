#include <stdio.h>

#define N 8

void selection_sort(int arr[], int n);

int main(void)
{
    // Creating just a random array.
    int arr[] = {7, 6, 5, 4, 3, 2, 1, 0};

    selection_sort(arr, N);

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int arr[], int n)
{
    // If we are sorting an array of size 1 or less, we should be done.
    if (n <= 1)
    {
        return;
    }

    // Go through each pair of elements in the array, and swap them if
    // needed.
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int next = arr[i + 1];
        
        if (curr > next)
        {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp; 
        }
    }

    selection_sort(arr, n - 1);
}
