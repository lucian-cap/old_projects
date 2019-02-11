# Prolog
# Author:  Chase Perry
# Section: A
# Date:   26/4/17
# Email: chaperry@valdosta.edu
# Purpose:
#  Program to find the average word length in a
#   sentence entered by the user.
# Preconditions: (input)
#       User supplies the sentence that is analyzed for
#       the average word length
#Postconditions:  (output)
#       User greeted with a message
#       Average word length is displayed 






def main():

    # 1. Get sentence from user
    sent = input("Please enter a sentence: ")


    #removes special characters from the user's sentence

    for ix in sent:
        x = ord(ix)
        if x == 33:
            sent = sent.replace("!", " ")
        else:
            if x == 36:
                sent = sent.replace("$", " ")
            else:
                if x == 37:
                    sent = sent.replace("%", " ")
                else:
                    if x == 40:
                        sent = sent.replace("(", " ")
                    else:
                        if x == 41:
                            sent = sent.replace(")", " ")
                        else:
                            if x == 59:
                                sent = sent.replace(";", " ")
                            else:
                                if x == 58:
                                    sent = sent.replace(":", " ")
                                else:
                                    if x == 39:
                                        sent = sent.replace("'", "")
                                    else:
                                        if x == 34:
                                            sent = sent.replace('"', " ")
                                        else:
                                            if x == 46:
                                                sent = sent.replace(".", " ")
                                            else:
                                                if x == 44:
                                                    sent = sent.replace(",", " ")
                                                else:
                                                    if x == 63:
                                                        sent = sent.replace("?", " ")
                                                    else:
                                                        if x == 47:
                                                            sent = sent.replace("/", " ")
                                                        else:
                                                            if x == 60:
                                                                sent = sent.replace("<", " ")
                                                            else:
                                                                if x == 62:
                                                                    sent = sent.replace(">", " ")
                                                                else:
                                                                    if x == 45:
                                                                        sent = sent.replace("-", "")
                                                                    else:
                                                                        if x == 42:
                                                                            sent = sent.replace("*", " ")
                                                                        else:
                                                                            if x == 64:
                                                                                sent = sent.replace("@", " ")
                                                                            else:
                                                                                if x == 35:
                                                                                    sent = sent.replace("#", " ")
                                                                                else:
                                                                                    if x == 94:
                                                                                        sent = sent.replace("^", "")
                                                                            
                                                    
                                        
                                
                            
          
    

    #Find periods if they exist in the string and removes them
    #x = sent.find(".")
    #if x != -1:
     #   sent = sent.replace(".", " ")
        
    #Finds commas in the string if there are any and removes them
    #x = sent.find(",")
    #if x != -1:
     #   sent = sent.replace(",", " ")


    # 2. Turn the string received from the user into a list
    wordlist = sent.split( )

    # 3. Assign variable ("x") to equal 0
    # 4. Create for loop that goes through the list created
    x = 0
    for ix in wordlist:

        #   4.1. Create accumulator that adds the length of
        #each word in the list together
        x = len(ix) + x
    
    # 5. Divide the accumulated length of the words in the list by the length
    #       of the list overall    
    x = x / len(wordlist)

    # 6. Print result
    print(x)







main()
