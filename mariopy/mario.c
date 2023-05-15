#include <stdio.h>
#include <cs50.h>
int get_height(void);
void print_grid(int size);

int main(void)
{
    int height = get_height();//calling created function

    print_grid(height);//calling created function
}










int get_height(void)// a function created to promts the user for an integer
{
    int height;
    do
    {
        height = get_int("Please enter a number between 1 and 8... ");//asking the user for a integer
    }
    while (height < 1 || height > 8);//checking if the integer is between 1 and 8

    return height;//return the value of the given integer to the variable calling function get_height

}

void print_grid(int size)//a function created to print the grid of the integer returned from the get_height function
{
    for (int i = 0; i < size; i++)//creating the loop
    {
        for (int space = size - i; space > 1; space--)//creating spaces to decrease by one as long as its greater than size
        {
            printf(" ");//printing space
        }
        for (int hash = 0; hash <= i; hash++)//creating hash to increase by one while hash is less than or equal to i
        {
            printf("#");//print hashes
        }
        printf("\n");//making sure the "#" stack correctly
    }

}