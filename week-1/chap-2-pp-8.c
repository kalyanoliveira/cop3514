#include <stdio.h>

int main(void)
{
    // Getting the user input for loan, annual interest rate, and monthly 
    // payment.
    float loan;
    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    float rate;
    printf("Enter interest rate: ");
    scanf("%f", &rate);

    float pay;
    printf("Enter monthly payment: ");
    scanf("%f", &pay);

    printf("%f %f %f\n", loan, rate, pay);

    // Calculating the first month remaining balance.
    float remaining_balance = (loan - pay) + (loan * ((rate / 100) / 12.0));
    printf("Balance remaining after first payment: %.2f\n", remaining_balance);

    remaining_balance = (remaining_balance - pay) + (loan * ((rate / 100) / 12.0));
    printf("Balance remaining after second payment: %.2f\n", remaining_balance);

    remaining_balance = (remaining_balance - pay) + (loan * ((rate / 100) / 12.0));
    printf("Balance remaining after third payment: %.2f\n", remaining_balance);

    return 0;
}
