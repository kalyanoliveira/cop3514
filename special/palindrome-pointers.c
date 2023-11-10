#include <stdio.h>

#define MAX 100

int main(void)
{
    // Read the message from the user.
    printf("Enter a message: ");
    char message[MAX + 1];
    char *p = message;
    char c;
    while ((c = getchar()) != '\n' && p - message < MAX)
    {
        if (c >= 'a' && c <= 'z')
        {
            *p = c;
            p++;
        }
    
        if (c >= 'A' && c <= 'Z')
        {
            *p = 'a' + (c % 'A');
            p++;
        }
    
    }
    *(p) = '\0'; 

    // Check if it is a palindrome.
    char *first = message;
    int flag = 1;
    p--;
    while (first < p)
    {
        if (*first != *p) flag = 0;
        first++;
        p--;
    }
    
    (flag) ? printf("yeah\n") : printf("nay\n");    

}
