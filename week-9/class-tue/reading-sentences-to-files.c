#include <stdio.h>

#define STR_LEN 3

int main(void)
{
    // Open a new file for reading, and check for any errors during that
    // process.
    FILE *file_pointer;
    file_pointer = fopen("a.txt", "r");
    if (file_pointer == NULL)
    {
        printf("Could not open file."); 
        return 1;
    }

    // Create a buffer to store the things we are going to read from the file.
    char buffer[STR_LEN + 1];

    // Let's read (STR_LEN + 1) chars from the file that file_pointer points
    // to, and store those into the char pointer buffer.
    fgets(buffer, STR_LEN + 1, file_pointer);

    printf("%s---", buffer);

    // Let's do that again, but for the next 3 characters.
    fgets(buffer, STR_LEN + 1, file_pointer);
    printf("%s---", buffer);

    // And once again as well.
    fgets(buffer, STR_LEN + 1, file_pointer);
    printf("%s---", buffer);

    // Then we free the memory used by the file.
    fclose(fp);

    return 0;
}
