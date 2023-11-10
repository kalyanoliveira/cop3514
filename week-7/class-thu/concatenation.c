#include <stdio.h>

void concatenate(char *s1, char *s2);

int main(void)
{
    char s1[9];
    printf("Enter a three-letter string: ");
    scanf("%s", s1);

    char s2[9];
    printf("Enter another three-letter string: ");
    scanf("%s", s2);

    concatenate(s1, s2);
    
    printf("Output: %s\n", s1); 
}

void concatenate(char *s1, char *s2)
{
    char *p;
    for (p = s1; *p != '\0'; p++);

    for (char *q = s2; *q != '\0'; q++)
    {
        *(p++) = *q;
    }

    *p = '\0';
}
