#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        printf("Error whilst opening test.txt\n");
        return 1;
    }

    char buffer[2];

    FILE *fp2;
    fp2 = fopen("out.txt", "w");
    if (fp2 == NULL)
    {
        printf("Could not open out.txt\n");
        fclose(fp);
        return 1;
    }

    while (fgets(buffer, 2, fp) != NULL)
    {
        if (buffer[0] == '\n') buffer[0] = ' ';
        printf("%s", buffer);
        fputs(buffer, fp2);
    }

    fclose(fp);
    fclose(fp2);
    return 0;
}
