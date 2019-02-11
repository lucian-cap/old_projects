# Prolog
# Author: Chase Perry
# Section: A
# Date: 5/2/2017
# Purpose: To find the distance between two planes given their distance
#    and angle to the operator's postition.
# Preconditions: (input)
#   User supplies the distances to either planes and the angle between
#   the planes (as numbers)
# Postconditions: (output)
#   User is asked for distance
#   User is asked for angle theta to the two planes
#   Distance between the two planes is dsiplayed.

import math

def main():

#### Main function

# 1. Display introductory message
    print("****ATC computation****")
    print("")

# 2. Ask the user for d1 and d2 (distance between plane 1 and plane 2 and operator)
    d1, d2 = eval(input ("Enter d1 and d2 (distances from the observer): "))

# 3. Ask the user for angle theta (angle between the planes)
    Ad = eval(input ("Enter angle theta between the two airplanes: "))

# 4. Convert angle theta from degrees to radians
    Ar = (Ad * math.pi) / 180

# 5. Compute the value of cosine(theta)
    ct = math.cos(Ar)

# 6. Use the cosine law to compute the desired answer squared
    D2 = (d1**2) + (d2**2) - (2*d1*d2*ct)

# 7. Square root the result 
    D = D2**.5

# 8. Output to the shell the variable
    print ("The distance between the two airplanes is:", D)

main()
