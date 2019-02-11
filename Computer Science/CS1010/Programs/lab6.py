# Prolog
# Author:
# Class: 
# Section: 
# Date:   
# Purpose:
#  Program to draw a house
# Preconditions: (input)
#       Graphics library 
# Postconditions:  (output)
#       House displayed


from graphics import *


def main():
    win = GraphWin("House", 500, 600)
    # the lines below create a rectangle object, set its fill color to brown and draw it in the window
    r = Rectangle(Point(75, 300), Point(425, 525)) # the two points specify the top left and bottom right corners
    r.setFill('brown')
    r.draw(win)
    # draw a circle
    c = Circle(Point(155, 375), 50) # the point is the center and 50 is the radius
    c.setFill('white')
    c.draw(win)

    c = Circle(Point(405, 370), 50) # the point is the center and 50 is the radius
    c.setFill('white')
    c.draw(win)
    
    # draw a triangle
    t = Polygon(Point(100, 100), Point(200, 100), Point(150, 200))
    t.setFill('green')
    t.draw(win)
    
    # write the rest of the proram below

    # these two lines wait for the user to click before program exits and window closes
    win.getMouse()
    win.close()
main()
