import turtle, time, random

wn = turtle.Screen()
wn.title("Snake Game")
wn.bgcolor("black")
wn.setup(600, 600)
wn.tracer(0)

head = turtle.Turtle()
head.shape("square")
head.color("lime")
head.penup()
head.goto(0, 0)
head.direction = "stop"

segments = []

food = turtle.Turtle()
food.shape("circle")
food.color("red")
food.penup()
food.goto(0, 100)

pen = turtle.Turtle()
pen.hideturtle()
pen.color("white")
pen.penup()

game_over = False

def go_up():
    head.direction = "up"
def go_down():
    head.direction = "down"
def go_left():
    head.direction = "left"
def go_right():
    head.direction = "right"

def move():
    if head.direction == "up":
        head.sety(head.ycor() + 20)
    if head.direction == "down":
        head.sety(head.ycor() - 20)
    if head.direction == "left":
        head.setx(head.xcor() - 20)
    if head.direction == "right":
        head.setx(head.xcor() + 20)

wn.listen()
wn.onkeypress(go_up, "Up")
wn.onkeypress(go_down, "Down")
wn.onkeypress(go_left, "Left")
wn.onkeypress(go_right, "Right")

while True:
    wn.update()

    if not game_over:
        if abs(head.xcor()) > 290 \
        or abs(head.ycor()) > 290:
            pen.goto(0, 0)
            pen.write("GAME OVER",
              align="center",
              font=("Arial", 24, "bold"))
            game_over = True

        if head.distance(food) < 20:
            food.goto(
                random.randint(-14,14)*20,
                random.randint(-14,14)*20)
            
            seg = turtle.Turtle()
            seg.shape("square")
            seg.color("green")
            seg.penup()
            segments.append(seg)

        for i in range(len(segments)-1,0,-1):
            segments[i].goto(
                segments[i-1].xcor(),
                segments[i-1].ycor())
        if segments:
            segments[0].goto(head.xcor(),
                             head.ycor())

        move()

        for seg in segments:
            if head.distance(seg) < 20:
                pen.goto(0, 0)
                pen.write("GAME OVER",
                  align="center",
                  font=("Arial", 24, "bold"))
                game_over = True
                break

    time.sleep(0.1)
