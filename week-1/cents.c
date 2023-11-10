/*
Given an amount of quarters, pennies, nickels, and dimes, computes the total
amount of money in dollars of those coins combined.
*/

#include <stdio.h>

#define QUARTERS 25
#define PENNIES 1
#define NICKELS 5
#define DIMES 10

int main(void)
{
	// Getting user input for the number of coins
	printf("Enter the number of quarters: ");
	int num_q;
	scanf("%d", &num_q);

	printf("Enter the number of pennies: ");
	int num_p;
	scanf("%d", &num_p);

	printf("Enter the number of nickels: ");
	int num_n;
	scanf("%d", &num_n);

	printf("Enter the number of dimes: ");
	int num_d;
	scanf("%d", &num_d);
	
	// Actually calculating the total amount of dollars in those coins
	int cents = num_q*QUARTERS + num_d*DIMES + num_n*NICKELS + num_p*PENNIES;
	double dollars = cents / 100.0;
	printf("The combined amount in dollars of these coins is $%.2lf\n", dollars);
	return 0;

	
}
