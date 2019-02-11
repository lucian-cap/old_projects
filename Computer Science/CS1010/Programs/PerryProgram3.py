from graphics import *

def main():

    win = GraphWin("Triangles", 600, 600)
    #creates graphics window, 600 pixels by 600 pixels

    colours = ["red", "green", "blue", "orange",]
    for colour in colours:
        p1 = win.getMouse()
        #gets the (x,y) coordinates of the user's mouseclicks

        c1 = Circle(p1, 4)
        c1.setFill("red")
        c1.draw(win)
        #Creates the red circle of radius 4 pixels and draw it at the user's
        #   point

        p2 = win.getMouse()
        c2 = Circle(p2, 4)
        c2.setFill("red")
        c2.draw(win)
        
        p3 = win.getMouse()
        c3 = Circle(p3, 4)
        c3.setFill("red")
        c3.draw(win)
        
        t1 = Polygon(p1, p2, p3)
        t1.setFill(colour)
        t1.draw(win)
        #Creates and draws the polygon at the user's input

    print("Please click one more time to close this window.")
    close = win.getMouse()
    close = win.close()
    #Prints a message in the shell prompting the user to click again
    #   to close the graphics window.
    #Gets the user to click again and once this is done the program closes.
    
        
        


main()
