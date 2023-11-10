#include <stdio.h>
#include <ctype.h>

// The number of letters in the alphabet.
#define N 26

int main(void)
{
    // Read the first word and update the first array.
    int first[N] = {0};
    char ch = tolower(getchar());
    while (ch != '\n')
    {
        first[ch - 'a']++;
        ch = tolower(getchar());
    }

    // Read the second word and update the second array.
    int second[N] = {0};
    ch = tolower(getchar());
    while (ch != '\n')
    {
        second[ch - 'a']++;
        ch = tolower(getchar());
    }

    // Compare the two arrays.
    for (int i = 0; i < N; i++)
    {
        if (first[i] != second[i])
        {
            printf("The entered words are not anagrams.\n");
            return 1; 
        }
    }
    
    printf("The entered words are anagrams.\n");
    return 0;
}
