#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents; //creating cents variable
    do
    {
        cents = get_int("How many cents does the cashier owe the customer? ");//asking user for input
    }
    while (cents < 0);//checking user input for valid integer
    return cents;//returning the value to the variable calling the function
}

int calculate_quarters(int cents)
{
    int quarters = 0;//creating a variable for quarters
    while (cents >= 25)//creating the loop while cents is greater than or equal to 25 complete operation below
    {
        quarters++;
        cents = cents - 25;// cents substract 25 each time this ooperation is completed add 1 to quarters
    }
    return quarters;//returning the results of the operation to the variable calling the function
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)//creating the loop while cents is greater than or equal to 10 complete operation below
    {
        dimes++;
        cents = cents - 10;// cents substract 10 each time this ooperation is completed add 1 to dimes
    }
    return dimes;//returning the results of the operation to the variable calling the function
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)//creating the loop while cents is greater than or equal to 5 complete operation below
    {
        nickels++;
        cents = cents - 5;// cents substract 5 each time this ooperation is completed add 1 to nickels
    }
    return nickels;//returning the results of the operation to the variable calling the function
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)//creating the loop while cents is greater than or equal to 1 complete operation below
    {
        pennies++;
        cents = cents - 1;// cents substract 1 each time this ooperation is completed add 1 to quarters
    }
    return pennies;//returning the results of operation to the variable calling the function
}

