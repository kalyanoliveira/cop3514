#include <stdio.h>

void selection_sort(int a[], int n);

int main(void)
{
    // Open the numbers.txt file.
    FILE *fp = fopen("numbers.txt", "r");
    // Check for any errors during that process.
    if (fp == NULL) return 1;
    
    // Count the numbers of integers in it.
    int buffer;
    int count = 0;
    while(!(feof(fp)) && !(ferror(fp)))
    {
        if (fscanf(fp, "%d", &buffer) == 1) count++;
    }

    // Create an array to store those numbers.
    int a[count];
    
    // Reset the file.
    rewind(fp);

    // Count all of those numbers again, but instead save them into the array.
    int *p = a;
    while(!(feof(fp)) && !(ferror(fp)))
    {
        if (fscanf(fp, "%d", &buffer) == 1) *p++ = buffer;
    }

    // Sort them using this function.
    selection_sort(a, 37);
        
    // Write them to a new file.
    FILE *new = fopen("new.txt", "w");
    if (new == NULL) return 2;
    for (int i = 0; i < count; i++) fprintf(new, "%d\n", a[i]);

    return 0;
}

void selection_sort(int a[], int n)
{
    int i, largest = 0, temp;
    if (n == 1)
        return;
    for (i = 1; i < n; i++)
        if (a[i] > a[largest])
            largest = i;
        if (largest < n - 1) {
            temp = a[n-1];
            a[n-1] = a[largest];
            a[largest] = temp;
        }
    selection_sort(a, n - 1);
}
