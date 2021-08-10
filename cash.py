# I am going to do this the way it is meant to be done i.e. using american currency

# User input ---------------------------------
while True:
    try:
        userInput = float(input("Change owed (in dollars): "))
        if userInput <=0:
            ValueError
            print("Has to be greater than zero")
            continue
    except ValueError:
        print("Please enter your change")
        continue
    else:
        break

# Greedys algorithm --------------------------

# once amount is input (in dollars), iterate through a penny 1, a nickel 5, a dime 10, quarter 25
# if the amount is greater than what we want, add one to the counter

# multiply by 100 to get accurate float
quarter = 0.25 * 100
dime = 0.1 * 100
nickel = 0.05 * 100
penny = 0.01 * 100

amount_left = userInput * 100

quarter_count = 0
dime_count = 0
nickel_count = 0
penny_count = 0

# Quarter - 25cents

while amount_left >= 25:
    amount_left = amount_left - 25
    quarter_count+=1

# Dime - 10cents

while amount_left >= 10:
    amount_left = amount_left - 10
    dime_count+=1

# Nickel - 5cents

while amount_left >= 5:
    amount_left = amount_left - 5
    nickel_count+=1

# Penny - 1cent

while amount_left >= 1:
    amount_left = amount_left - 1
    penny_count+=1

#converting to dollars
quarter = quarter / 100
dime = dime / 100
nickel = nickel / 100
penny = penny / 100

# Printing final amount

total = quarter_count + dime_count + nickel_count + penny_count

print(f"{total}")

