/*
 * A simple program that checks if a password fits some arbitrary requirements.
 */

#include <stdio.h>

int main(void)
{
    // Obtain the password from the user, counting the number of chars.
    int counter = 0;

    char c = ' ';
    c = getchar();

    while(c != '\n')
    {
        // Character must be alphanumeric.
        // long-ass if expression, but whatever.
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
        {
            printf("nah bro\n");
            return 1;
        }

        // Making sure that we know the number of characters that we have so far.
        counter++;

        c = getchar();
    }

    if (counter < 8)
    {
        printf("nah bro\n");
        return 1;
    }

    printf("you good\n");
    return 0;
}
