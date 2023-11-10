#include <stdio.h>

int main(void)
{
    FILE *file;
    file = fopen("text.txt", "r");
    // Every time you open a file, make sure to add a conditional for NULL.
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    return 0;
}
