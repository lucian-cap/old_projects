# Prolog
# Authors: 
# Date: 
# Purpose: 

from math import *

def main():
    nr_terms = eval(input("Please enter the number of terms in s: "))

    s = 0
    
    # calculate s from a sequence
    for x in range(2, nr_terms+1):
        # each iteration adds a fraction to s
        s = s + (1 / ((x)**2))
        # please ensure you indent the body of the for loop
    
    # final calculation of the approximate value of pi
    approx_pi = (((6 * (1 + (s)))**(.5)))    
    # Print the results
    print("The approximate value of pi for", nr_terms, "terms, is", approx_pi)
main()
