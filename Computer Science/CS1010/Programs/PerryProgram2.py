# Prolog
# Author:  Chase Perry
# Email: chaperry@yahoo.com
# Section: A
# Date:   05/03/2017
# Purpose:
#  Program creates a multiplication table per the given input from the user.
# Preconditions: (input)
#       User supplies the maximum term being multiplied across the table.
# Postconditions:  (output)
#       User is greeted and asked for maximum term
#       Multiplication table is printed



from math import *



def main():

#    1. Greet user and ask for input
    print ("Hello!")
    n = eval(input("Enter n for the multiplication table n x n: "))

#    2. Take absolute value of input and turn it into
#        an integer (it it is not already)
    n = abs(n)
    n = int(n)

#    3. loop from 1 to n
#	4. Set accumulator to 0
    for a in range (1, (n+1)):
        c = 0

#        5. Loop from 1 to n
#		6. Add index of first counter to accumulator
#		7. Print result
        for a2 in range (1, (n+1)):
            c = c + a
            print(a, " * ", a2, " = ", c)
            
    
        
    



















main()
