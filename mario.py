# User input
while True:
    try:
        height = int(input("Height: "))
        if height <=0 or height > 8:
            ValueError
            print("Invalid")
            continue
    except ValueError:
        print("Invalid")
        continue
    else:
        break

# mario pyramid construction

# construct the column hash
i = 1
j = height - 1

while i <= height:
    print(" " * j, end="")
    print ("#" * i + "  " + "#" * i)
    i += 1
    j = j - 1
