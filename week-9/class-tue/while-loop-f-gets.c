#include <stdio.h>

#define STR_LEN 3

int main(void)
{
    FILE *fp;
    fp = fopen("b.txt", "r");
    if (fp == NULL)
    {
        printf("Could not open b.txt\n");
        return 1;
    }
    
    char buffer[STR_LEN + 1];

    // fgets return a char * if succesfull, and NULL if not.
    // So we can use that as a condition in a while loop.
    while (fgets(buffer, STR_LEN + 1, fp) != NULL)
    {
        printf("%s-", buffer);
    }

    fclose(fp);
    
    return 0;
}
