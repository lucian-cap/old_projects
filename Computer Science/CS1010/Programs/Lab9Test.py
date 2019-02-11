#Ask user for input
#Create list
#slice list using the users input
#Print the user's grade


def main():

    g = input("Enter the points earned: ")
    l = ["F", "D", "C", "B", "A"]
    g = int(g)
    g = g - 1
    
    x = l[g]
    print("The corresponding grade is:", x)
    
















main()
