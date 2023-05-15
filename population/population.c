#include <stdio.h>
#include <cs50.h>

// Course Week 1 Population exersice

int main(void)
    {
    int dogs;
    do
    {      // getting dogs integer from user
        dogs = get_long("How many dogs do you have on your ranch? ");
    }
    while (dogs <= 8); // checking if interger given by user is above 8


    int goal;
    do
    {        // getting goal integer from user
        goal = get_long("how many would you like to have next year? ");
     }
    while (goal < dogs); // checking goal int is greater than dogs int


    int years = 0;
    // creating the loop that will calculate how many years dogs integer would take to reach goal
    while (dogs < goal)
    {
        dogs = dogs + (dogs / 3) - (dogs / 4);
        years++;
    }
    printf("Years: %i\n", years); // print results

    }