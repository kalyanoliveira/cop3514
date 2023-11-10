/*
 * Prints the upper case version of a message (string of characters) entered 
 * by a user.
 */

#include <stdio.h>

int main(void)
{
    printf("Enter a message: ");

    char c;
    c = getchar();
    
    int flag = 1;

    while (c != '\n')
    {
        if (flag)
        {
            printf("Output: ");
            flag = 0;
        }

        if (c >= 'a' && c <= 'z')
        {
            printf("%c", c - 'a' + 'A');
        }
        else
        {
            printf("%c", c); 
        }
        
        c = getchar();
    }
    
    printf("\n");

    return 0;
}
