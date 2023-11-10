#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // We are given a bunch of integers that we need to sort in the argv.
    // Let's read them into an array, and then apply some kind of sorting
    // algorithm. 
    
    const int ARRAY_LENGTH = argc - 1;

    int sorted[ARRAY_LENGTH];

    for (int i = 1; i < argc; i++)
    {
        sorted[i - 1] = atoi(argv[i]);
    }

    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        for (int j = i; j < a:
    }

    return 0;
}
