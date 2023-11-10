#include <stdio.h>

#define STRING_LENGTH 3

int read_line(char str[], int n);

int main(void)
{
    char s[STRING_LENGTH + 1];

    printf("Enter a three-character string: ");
    read_line(s, STRING_LENGTH);

    printf("%s", s);
    
    return 0;
}

int read_line(char str[], int n)
{
    char ch;
    int i = 0;
    
    while ((ch = getchar()) != '\n')
    {
        if (ch == ' ')
        {
            continue;
        }

        if (i < n)
        {
            str[i++] = ch;
        } 
    }
    str[i] = '\0';
    return i;
}
