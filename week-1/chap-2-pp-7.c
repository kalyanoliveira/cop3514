#include <stdio.h>

int main(void)
{
    // Get the number of dollars from the user.
    int dollars;
    printf("Enter a dollar amount: ");
    scanf("%d", &dollars);

    int twenty_bills = dollars / 20;
    dollars = dollars % 20;

    int ten_bills = dollars / 10;
    dollars = dollars % 10;

    int five_bills = dollars / 5;
    dollars = dollars % 5;

    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", 
           twenty_bills, ten_bills, five_bills, dollars);

    return 0; 
}
