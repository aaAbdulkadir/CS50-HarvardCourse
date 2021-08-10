# User input ------------------------------------------
while True:
    userInput = input("Enter text: ")
    if userInput.isdigit():
        print("Emter text only!")
    else:
        break

# Count the number of letters, words and sentences ----
letters_count = 0
words_count = 1
sentences_count = 0

for i in range(len(userInput)):
    if userInput[i].isalpha():
        letters_count += 1

    if userInput[i] == ' ':
        words_count += 1

    if userInput[i] == '.' or userInput[i] == '!' or userInput[i] == '?':
        sentences_count += 1

# Grade count ----------------------------------------
L = (letters_count * 100)/words_count
S = (sentences_count * 100)/words_count

# The index calculation
index = round(0.0588 * L - 0.296 * S - 15.8)

# Grade print
if index < 16 and index >= 1:
    print(f"Grade {index}")

elif rounded_index < 1:
    print("Grade < 1")

else:
    print("Grade is 16+")
