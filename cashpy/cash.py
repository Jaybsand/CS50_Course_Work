def main():
    cents = getCents()

    Q = calQuarts(cents)
    cents = cents - Q * 25  # Calculate the number of quarters to give the customer

    D = calDimes(cents)
    cents = cents - D * 10  # Calculate the number of dimes to give the customer

    K = calKnicks(cents)
    cents = cents - K * 5  # Calculate the number of knickels to give the customer

    P = calPens(cents)
    cents = cents - P * 1  # Calculate the number of pennies to give the customer

    change = P + K + D + Q

    print(change)  # printing out change


def getCents():
    while True:
        try:
            cents = float(input("how many cents do we owe the customer? "))  # prompting user for input
            if cents > -1:
                cents = round(cents * 100)
                return cents  # returning the value the user types

        except ValueError:
            print("not a Number")


def calKnicks(cents):  # creating a function that calculates Knickels
    Knicks = 0
    while cents >= 5:  # creating a loop that subtracts 5 each time the loop runs
        Knicks += 1
        cents = cents - 5
    return Knicks


def calDimes(cents):  # creating a function that calculates Dimes
    Dimes = 0
    while cents >= 10:
        Dimes += 1
        cents = cents - 10  # creating a loop that subtracts 10 each time the loop runs
    return Dimes


def calQuarts(cents):  # creating a function that calculates Quarters
    Quarts = 0
    while cents >= 25:  # creating a loop that subtracts 25 each time the loop runs
        Quarts += 1
        cents = cents - 25
    return Quarts


def calPens(cents):  # creating a function that calculates Pennies
    Pens = 0
    while cents >= 1:  # creating a loop that subtracts 1 each time the loop runs
        Pens += 1
        cents = cents - 1
    return Pens


main()  # run main function
