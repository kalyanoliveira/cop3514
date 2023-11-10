/*
 * Prints the upper case version of a message (string of characters) entered
 * by a user.
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;
    
    printf("Enter a message: ");

    do
    {
        c = getchar();        
        printf("%c", toupper(c));
    }
    while (c != '\n');

    return 0;
}
