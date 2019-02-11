# Prolog
# Author:  Chase Perry
# Section: A
# Date:   04/4/17
# Purpose:
#  Program to create four different coloured polygons (triangles) using the
#   users input to create the points while simultaneously creating circles at
#   these points
# Preconditions: (input)
#       User supplies the various points of the vertices of the polygons.
# Postconditions:  (output)
#       A small, red circle is created wherever the user clicks
#       After the user had clicked three times a polygon will appear (of various
#           colours) using these three points as its vertices.
#### Design
#   1. Import graphics library
#   2. Create graphics window
#   3. Create list of colours
#   4. For colour in the list of colours
#       4.1. Get first point from user
#       4.2. Create red circle at point
#       4.3. Get second point from user
#       4.4. Create red circle at point
#       4.5. Get third point from user
#       4.6. Create red circle at point
#       4.7. Create polygon at these points
#       4.8. Set polygon's fill colour
#       4.9. Draw the polygon
#   5. The user is prompted to click again to close the window.
#   6. The window is closed after the user has clicked one more time
