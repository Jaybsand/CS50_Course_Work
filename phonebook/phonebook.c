#include <stdio.h>
#include <cs50.h>

       // course week 1 Phonebook exersice

int main(void)
    {
        string name = get_string("What's your name? ");
        string age = get_string("How old are you? ");
        string cell = get_string("whats's your cell number? ");

        printf(" Hello %s\n You are %s\n Your cell number is %s\n", name, age, cell);
        printf("\n");


    }




