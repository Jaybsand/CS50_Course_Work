passage = input("Text: ")  # Gathering text from user

# Declaring Variables letters, words and sentences
letters = 0
words = 1
sentences = 0

for i in passage:  # Loop to count letters, words, and sentences
    if i.isalpha():
        letters += 1
    elif i == " ":
        words += 1
    elif i == "." or i == "!" or i == "?":
        sentences += 1

let = letters / words * 100
sent = sentences / words * 100

# initializing Coleman-Liau Index
index = (0.0588 * let - 0.296 * sent - 15.8)

# Print results
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print("Grade ", round(index))

