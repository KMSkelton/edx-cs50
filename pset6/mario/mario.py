def build(n = 0, c = 1, end = 2):
    while (n > 24 or n < 1):
        try:
            n = int(input("How tall do you want the tower? Enter a number between 1 and 23  ")) + 1
        except ValueError:
            print("Please enter an integer. ")
    result = ""
    if c < n:
        for space in range(n-end):
            result += " "
        for octothorpe in range(end):
            result += "#"
        print(result)
        build(n, c = c + 1, end = end + 1)
build()