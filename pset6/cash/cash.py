quarters = 0
dimes = 0
nickels = 0
pennies = 0
change = 0

while change <= 0:
    try:
        change = float(input("How much change are you expecting back?  ")) * 100
    except ValueError:
        print("You must be expecting a positive number")

while change > 0:
    if change >= 25:
        change -= 25
        quarters += 1
    elif change >= 10:
        change -= 10
        dimes += 1
    elif change >= 5:
        change -= 5
        nickels += 1
    elif change >= 1:
        change -= 1
        pennies += 1

if quarters > 8:
    print("Sorry! The bank didn't bring us more bills. ")
print(f"You should receive {quarters} quarters, {dimes} dimes, {nickels} nickels and {pennies} pennies, for a total of {quarters+dimes+nickels+pennies} coins")