#include <stdio.h>

int main(void)
{

    // Open the test file.
    FILE *fp = fopen("text.txt", "r");
    // Check if that was successful.
    if (fp == NULL) return -1;

    // Integers to save the numbers in the file into.
    int n1, n2, n3, n4;
    
    // Actually reading those integers into the variables.
    if (fscanf(fp, "%d %d %d %d", &n1, &n2, &n3, &n4) != 4) return -2;

    printf("%d %d %d %d\n", n1, n2, n3, n4);
    
    return 0;
}

