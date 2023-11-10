#include <stdio.h>
#include <ctype.h>

// The number of letters in the alphabet.
#define N 26

int main(void)
{
    int arr[N] = {0};

    // Read the first word and update the array.
    char ch = tolower(getchar());
    while (ch != '\n')
    {
        arr[ch - 'a']++;
        ch = tolower(getchar());
    }

    // Read the second word and update the array.
    ch = tolower(getchar());
    while (ch != '\n')
    {
        arr[ch - 'a']--;
        ch = tolower(getchar());
    }

    // Compare the two arrays.
    for (int i = 0; i < N; i++)
    {
        if (arr[i] != 0)
        {
            printf("The entered words are not anagrams.\n");
            return 1; 
        }
    }
    
    printf("The entered words are anagrams.\n");
    return 0;
}
