/*
 * Reads sentences from the user, then displays them in order.
 * TODO:
 * 1. Read the sentences from the user, save them into an array of char
 * pointers.
 * 2. Iterate through that array with some sort of sorting algorithm.
 * 3. Display the sorted array to the user.
 */

// For standard input and output.
#include <stdio.h>
// For malloc (and realloc).
#include <stdlib.h>

// Adds the next character in stdin to a string.
// Returns non-zero if next character is not a newline character.
// If next character is a newline, returns 0 and terminates string.
int add_next_char(char *sentence, int *n);

// Frees the sentences stored in our array of sentences given the number of
// actually completed sentences.
void free_sentences(char *ss[], int n);

int main(void)
{
    // Let's first get the number of sentences that the user wants to type.
    int n_sentences;
    printf("Enter the number of sentences to be typed: ");
    scanf(" %d", &n_sentences);

    // Let's create an array of char pointers, with the size specified above by
    // the user.
    char *sentences[n_sentences];

    int sentences_completed = 0;

    for (int i = 0; i < n_sentences; i++)
    { 
        // Let's create a dynamically allocated string: a pointer to the first
        // character of a dynamically allocated array of chars.
        char *sentence;
        int size_of_current_sentence = 2;
        sentence = malloc(size_of_current_sentence);
        if (sentence == NULL)
        {
            printf("Could not allocate 2 bytes of memory for the first two characters of current sentence. Returned 1.\n");
            free_sentences(sentences, sentences_completed);
            return 1;
        }

        printf("Start typing sentence %d: ", i);
        
        // Assign the first two characters of the current sentence.
        sentence[0] = getchar();
        sentence[1] = '\0';

        // While the next character in stdin is not a newline, let's keep
        // adding characters from stdin to our buffer.
        int condition;
        while ((condition = add_next_char(sentence, &size_of_current_sentence)));
    
        sentences[i] = sentence;
        sentences_completed++;
    }

    // All we have to do now is print our sentences in order.
    // We can use bubble sort, remembering that strcmp allows us to compare two
    // strings.
    // strcmp will return > 0 if the first string is larger than the second
    // string (if it comes after)
    // strcmp will return < 0 if the first string is less than the second
    // string (if it comes before)
    // strcmp will return 0 if the two strings are equal

    return 0;
}

int add_next_char(char *sentence, int *n)
{
    // Reallocate enough space in our sentence to keep adding characters to it.
    char *temp = realloc(sentence, (*n + 1));
    // If we run out of space for the current string, let's return 0. This
    // makes it such that we stop adding characters for the current sentence.
    if (temp == NULL)
    {
        printf("Could not allocate enough space for the next character.\n");
        printf("Previous state of string unaltered, but sentence is now terminated\n");
        return 0;
    }

    // This means that the realloc was successful, we can now assign the new
    // pointer to the old one.
    sentence = temp;

    // And we can also increase the size variable.
    (*n)++;

    // Now let's add a char to the sentence.
    // If the next char in stdin is a newline, we'll add a null character, and
    // return 0
    char next = getchar();
    if (next == '\n')
    {
        sentence[*n - 1] = '\0';
        return 0;
    } 
    sentence[*n - 2] = next;
    sentence[*n - 1] = '\0';

    return *n;
}

void free_sentences(char *ss[], int n)
{
    for (int i = 0; i < n; i++)
    {
        free(ss[i]);
    }

    return;
}
