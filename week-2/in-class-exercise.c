/*
 * A simple program that compares dates given by the user, outputting the
 * earlier date.
 */

#include <stdio.h>

int main(void)
{
    // Creating the variables to store the dates.
    int m1, d1, y1, m2, d2, y2; 

    // A bool to store the "first earlier condition".
    // "0" means the second date is earlier, "1" means the first date 
    // is earlier.
    int first_earlier = 0;
    
    // Getting the first date from the user.
    printf("Enter first date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m1, &d1, &y1);

    printf("Enter second date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m2, &d2, &y2);

    // Just for debugging.
    printf("%d %d %d %d %d %d\n", m1, d1, y1, m2, d2, y2);

    // Compare the years first, if needed compare the months, and if needed 
    // compare the days. There's also the possibility that both dates are
    // equal, but we assuming the user does not provide us which such 
    // circumstances.
    if (y1 != y2)
    {
        if (y1 < y2)
            first_earlier = 1;
    }
    else if (m1 != m2)
    {
        if (m1 < m2)
            first_earlier = 1;
    }
    else if (d1 != d2)
    {
        if (d1 < d2)
            first_earlier = 1;
    }

    if (first_earlier)
    {
        printf("The first date is earlier\n");
    }
    else
    {
        printf("The second date is earlier\n");
    }
    
    return 0;
}
