#include <stdio.h>

int main(void)
{
    // Open text.txt for reading
    FILE *fp = fopen("text.txt", "r");
    // Check for any errors during that process.
    if (fp == NULL)
    {
        printf("Error whilst opening text.txt\n");
        return 1;
    } 

    int n;
    
    // Keep reading integers from that file using feof and ferror, and print
    // them.
    // If feof returns non-zero, we have an error.
    // So we don't want that, we want ! of that.
    // The same logic applies to ferror.
    while (!(feof(fp)) && !(ferror(fp)))
    {
        if (fscanf (fp, "%d", &n) != 1)
        {
            printf("Could not read integer\n");
            return 2;
        } 
        printf("%d\n", n);
    }
        
    return 0;
}
