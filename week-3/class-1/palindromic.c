/*
 * Prints the first 50 palindromes.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    // This is the number that we'll check for a palindrome.
    int number = 0;
    
    // This will be the counter variable that caps the number of displayed
    // palindromes to 50.
    int counter = 0;
    
    // Keep running until we find 50 palindromes.
    for (; counter < 50; number++)
    {
        // Since we'll be manipulating the value of number, we need to save
        // its original value.
        int original = number;

        // Integer to save the reversed number.
        int reverse = 0;

        // This will be the variable where we save each succesive digit
        // of "number".
        int next_digit;

        // This will help us keep track of the power of 10 that we should
        // be using.
        int digit_counter = 0;

        // Iterate through each digit of "number", 
        // and add it to "reverse" as a power of 10.
        do 
        {
            next_digit = number % 10; 
            number /= 10;
            reverse += next_digit * pow(10, digit_counter);
            digit_counter++;
        }
        while (number != 0);

        if (reverse == original)
        {
            counter++;
            continue;
        }
        else
        {
            continue;
        }
    }
}
