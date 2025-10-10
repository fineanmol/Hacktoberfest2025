import turtle

# Set up the screen
screen = turtle.Screen()
screen.bgcolor("white")
screen.title("Flower Pattern")

# Create the turtle
flower = turtle.Turtle()
flower.speed(10)
flower.color("red")

# Function to draw a petal
def petal():
    for _ in range(2):
        flower.circle(100, 60)  # radius, extent
        flower.left(120)

# Draw the flower
for _ in range(6):  # number of petals
    petal()
    flower.left(60)  # rotate for next petal

# Hide the turtle and display the window
flower.hideturtle()
turtle.done()
