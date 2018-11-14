import sys

def encrypt(key):
    result_text = ""
    key = int(sys.argv[1])

    while not key:
        key = int(input("Please enter your Ceasar Key number (larger than 0): "))

    plain_text = input("Please enter the plain text you need encyphered: ")

    for i in range(len(plain_text)):
        if plain_text[i].isalpha():
            char = plain_text[i]
            if char.isupper():
                char = chr((ord(char) + key - 65) % 26 + 65)
            else:
                char = chr((ord(char) + key - 97) % 26 + 97)

            result_text += char
        else:
            result_text += plain_text[i]

    print(f"ciphertext: {result_text}\n")

encrypt(sys.argv)