/*
 * Fucking palindrome yeah.
 */

#include <stdio.h>

#define MAX 100

int main(void)
{
    // Read a message from the user.
    printf("Enter a message: ");
    char buffer[MAX + 1];

    char c;
    int n = 0;
    while ((c = getchar()) != '\n' && n < MAX)
    {
        if (c >= 'a' && c <= 'z')
        {
            buffer[n] = c; 
            n++;
        }

        if (c >= 'A' && c <= 'Z')
        {
            buffer[n] = 'a' + (c % 'A'); 
            n++;
        }
    }
    buffer[n + 1] = '\0';


    // Assume that we have a palindrome.
    int flag = 1;
    
    for (char *first = buffer, *last = &buffer[n - 1]; first < last; first++, last--)
    {
        if (*first != *last) 
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        printf("yeah\n");
    }
    else
    {
        printf("nay\n");
    }
    return 0;
}
