import random
rn = random.randint(1, 100)
c = 0
while True:
    c += 1
    n = int( input("Enter your guess (1-100) >> "))
    if n > rn:
        print("Your guess is higher\nPlease enter lower")
    elif n < rn:
        print("Your guess is lower\nPlease enter higher")
    else:
        print("\nCorrect the number was", rn)
        break
    
print("Total tries :", c)