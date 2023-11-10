// Importing libraries.
// For standard input and output.
#include <stdio.h>
// For dynamic memory allocation.
#include <stdlib.h>
// For conversion from string to integer.
#include <string.h>

// Defining constants: Starting array size.
#define INITIAL_ARRAY_SIZE 7

// Function prototypes.
int change_size(int *a, int n, int delta);
void fill_array(int *a, int n);

int main(int argc, char *argv[])
{
    // Making sure the user understands what they have to do.
    if (argc != 2)
    {
        printf("Usage: ./a.out delta\n");
        return 2;
    }

    int *a;
    int n = INITIAL_ARRAY_SIZE;

    // a gets the pointer to the first element of a dynamically allocated
    // integer array.
    a = malloc(INITIAL_ARRAY_SIZE * sizeof(int));
    if (a == NULL) 
    {
        printf("Could not allocate space for initial array\n");
        return 1;
    }

    fill_array(a, n);

    n = change_size(a, n, atoi(argv[1]));

    fill_array(a, n);

    // Now we have to free the memory space that we were using. We are ending
    // the program right after, so I guess it doesn't really matter, but it's
    // good practice eitherway.
    free(a);

    return 0;
}

// Returns the new array size.
int change_size(int *a, int n, int delta)
{
    int new_size = n + delta;
    
    if (new_size <= 0)
    {
        printf("Could not change array size: size would be <= 0\n");
        printf("Old array was not affected\n");
        return n;
    }

    int *b = realloc(a, new_size * sizeof(int));

    if (b == NULL)
    {
        printf("Could not find space to reallocate array\n");
        printf("Old array was not affected\n");
        return n;
    }

    a = b;
    return new_size;
}

// Populates array with numbers from 0 to (array size - 1).
void fill_array(int *a, int n)
{
    // Populate array.
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    } 

    // Display it to the user.
    printf("New array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    } 
    printf("\n");
}
