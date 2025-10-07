import turtle

# ----- Config -----
BG_COLOR = "black"
PETAL_OUTLINE = "magenta"
PETAL_FILL = "#8A2BE2"
CENTER_COLOR = "yellow"
STEM_COLOR = "green"
LEAF_FILL = "#9FE79F"

WINDOW_WIDTH = 800
WINDOW_HEIGHT = 700

NUM_PETALS = 6
PETAL_RADIUS = 120
PETAL_ANGLE = 60
CENTER_RADIUS = 24
STEM_LENGTH = 260
STEM_WIDTH = 10

# ----- Setup -----
screen = turtle.Screen()
screen.setup(WINDOW_WIDTH, WINDOW_HEIGHT)
screen.bgcolor(BG_COLOR)
screen.title("Flower Pattern (stem behind)")

t = turtle.Turtle()
t.hideturtle()
t.speed(0)
screen.tracer(0)

# ---- Helper Context ----
class SavedState:
    def __init__(self, t): self.t = t
    def __enter__(self):
        self.pos = self.t.position(); self.heading = self.t.heading(); self.pen = self.t.pen()
    def __exit__(self, a, b, c):
        self.t.penup(); self.t.setposition(self.pos); self.t.setheading(self.heading)
        self.t.pen(pencolor=self.pen["pencolor"], fillcolor=self.pen["fillcolor"],
                   pensize=self.pen["pensize"], pendown=self.pen["pendown"])

# ---- Drawing functions ----
def draw_stem():
    with SavedState(t):
        t.penup()
        t.goto(0, 0)
        t.setheading(-90)
        t.pencolor(STEM_COLOR)
        t.pensize(STEM_WIDTH)
        t.pendown()
        t.forward(STEM_LENGTH)

def draw_leaf(pos, side="left"):
    with SavedState(t):
        t.penup()
        t.goto(0, 0)
        t.setheading(-90)
        t.forward(pos)
        angle = 40 if side == "right" else 140
        t.setheading(angle)
        t.pencolor(STEM_COLOR)
        t.fillcolor(LEAF_FILL)
        t.begin_fill()
        for _ in range(2):
            t.circle(40, 90)
            t.left(90)
        t.end_fill()

def draw_petal(angle):
    with SavedState(t):
        t.penup()
        t.goto(0, 0)
        t.setheading(angle)
        t.pendown()
        t.pencolor(PETAL_OUTLINE)
        t.fillcolor(PETAL_FILL)
        t.begin_fill()
        for _ in range(2):
            t.circle(PETAL_RADIUS, PETAL_ANGLE)
            t.left(180 - PETAL_ANGLE)
        t.end_fill()

def draw_flower():
    for i in range(NUM_PETALS):
        draw_petal(i * (360 / NUM_PETALS))

def draw_center():
    with SavedState(t):
        t.penup()
        t.goto(0, -CENTER_RADIUS)
        t.setheading(0)
        t.pendown()
        t.pencolor("black")
        t.fillcolor(CENTER_COLOR)
        t.begin_fill()
        t.circle(CENTER_RADIUS)
        t.end_fill()

# ---- Draw Order (stem first, then flower) ----
draw_stem()
draw_leaf(100, "left")
draw_leaf(160, "right")
draw_flower()
draw_center()

screen.update()
screen.exitonclick()
