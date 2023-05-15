def main():
    h = getHeight()  # calling the get height function to get input from user
    for i in range(0, h, 1):
        for j in range(0, h, 1):
            if (i + j < h - 1):
                print(" ", end="")  # printing spaces
            else:
                print("#", end="")  # printing hashes
        print()


def getHeight():  # creating a function that will get an integer from the user
    while True:  # creating a loop to ask the user for a integer
        try:
            height = int(input("enter a positive number: "))
            if height > 0 and height <= 8:  # checking if the integer is between 1 and 8
                return height
        except ValueError:
            print("not a number")  # if the user types in a string or something else thats not a integer


main()
