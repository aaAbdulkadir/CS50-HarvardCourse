# User input credit card number. Must be 16 digits long and numbers
while True:
    try:
        userInput=int(input("Input your credit card number: "))
        if userInput <=0:
            ValueError
            print("Has to be greater than zero")
            continue
    except ValueError:
        print("Enter a valid number please.")
        continue
    else:
        break

# Luhns algorithm: Disclaimer, do not take my even and odd as good variable names
# I should have really kept it as last digit and second to last digit.

# Sorting the odd numbers in CC ----------------------

# Takes user input an puts it into an array which I can then slice
cc_number_list = [int(i) for i in str(userInput)]

# Takes the list and only use the second last number and evey other number i.e. odd from the second last
odd_numbers = cc_number_list[-2::-2]

# Multiply the numbers by 2
x2_odd_numbers = [element * 2 for element in odd_numbers]

sum_of_greater = 0
sum_of_less = 0

# If odd numbers are greater than 9 then add the two integers
for i in range(len(x2_odd_numbers)):
    if x2_odd_numbers[i] > 9:
        greater_than_9_sorted = (int(x2_odd_numbers[i]/10) + x2_odd_numbers[i]%10)
        sum_of_greater = sum_of_greater + greater_than_9_sorted
    else:
        sum_of_less = sum_of_less + x2_odd_numbers[i]

# Sum the odd numbers after sorting the integers
sum_of_odd = sum_of_greater + sum_of_less

# Sorting the even numbers -----------------------------

# Takes the list and only use the last number and evey other number i.e. even from the last
even_numbers = cc_number_list[::-2]
even_sum = sum(even_numbers)

# Sum all calculations --------------------------------

final_sum = even_sum + sum_of_odd

# Determining the CC type -----------------------------

for i in range(len(cc_number_list[0:2:1])):
    #AMEX
    if (cc_number_list[0] == 3 and (cc_number_list[1] == 4 or cc_number_list[1] == 7)):
        if (len(str(userInput)) == 15):
            print("AMEX")
            break

    # Mastercard
    elif (cc_number_list[0] == 5 and (cc_number_list[1] == 1 or cc_number_list[1] == 2 or cc_number_list[1] == 3 or cc_number_list[1] == 4 or cc_number_list[1] == 5)):
        if (len(str(userInput)) == 16):
            print("MASTERCARD")
            break

    # VISA
    elif (cc_number_list[0] == 4):
        if (len(str(userInput)) == 13 or len(str(userInput)) == 16):
            print("VISA")
            break

    else:
        print("INVALID")
        break
