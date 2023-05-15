#include <stdio.h> //adding in libraries
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? ");//Prompting user for name
    printf("Hello! %s\n", name);//printing out a greeting to the user with there name
}