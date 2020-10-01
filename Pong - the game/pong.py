# Simple Pong - freeCodeCamp tutorial
# By @keivalya
# MY FIRST TURTLE PROJECT!!! :D

import turtle
import winsound
from tkinter import *

# import os

player1='Player A'
player2='Player B'

def startGame():
    top.destroy()
    if p1.get():
        player1=p1.get()
    if p2.get():
        player2=p2.get()
    wn = turtle.Screen()
    wn.title("Pong by @keivalya")
    wn.bgcolor("black")
    wn.setup(width = 800, height = 600)
    wn.tracer(0)
    
    # Score
    score_a = 0
    score_b = 0
    
    # Paddle A
    paddle_a = turtle.Turtle()
    paddle_a.speed(0)
    paddle_a.shape("square")
    paddle_a.color("yellow")
    paddle_a.shapesize(stretch_wid= 5, stretch_len= 1)
    paddle_a.penup()
    paddle_a.goto(-350, 0)
    
    # Paddle B
    paddle_b = turtle.Turtle()
    paddle_b.speed(0)
    paddle_b.shape("square")
    paddle_b.color("purple")
    paddle_b.shapesize(stretch_wid= 5, stretch_len= 1)
    paddle_b.penup()
    paddle_b.goto(350, 0)
    
    # Ball
    ball = turtle.Turtle()
    ball.speed(0)
    ball.shape("circle")
    ball.color("white")
    ball.penup()
    ball.goto(0, 0)
    ball.dx = 0.25
    ball.dy = 0.25
    
    # Pen
    pen = turtle.Turtle()
    pen.speed(0)
    pen.shape("square")
    pen.color("white")
    pen.penup()
    pen.hideturtle()
    pen.goto(0, 260)
    pen.write("{}: 0  {}: 0".format(player1, player2), align="center", font=("Courier", 24, "normal"))
    
    # Function
    def paddle_a_up():
        y = paddle_a.ycor()
        y += 20
        paddle_a.sety(y)
    
    def paddle_a_down():
        y = paddle_a.ycor()
        y -= 20
        paddle_a.sety(y)
    
    def paddle_b_up():
        y = paddle_b.ycor()
        y += 20
        paddle_b.sety(y)
    
    def paddle_b_down():
        y = paddle_b.ycor()
        y -= 20
        paddle_b.sety(y)
    
    # Keyboard binding
    wn.listen()
    wn.onkeypress(paddle_a_up, "w")
    wn.onkeypress(paddle_a_down, "s")
    wn.onkeypress(paddle_b_up, "Up")
    wn.onkeypress(paddle_b_down, "Down")
    
    # Main game loop
    try:
        while True:
            wn.update()
            
            # Move the ball
            ball.setx(ball.xcor() + ball.dx)
            ball.sety(ball.ycor() + ball.dy)
        
            # Border checking
        
            # Top and bottom
            if ball.ycor() > 290:
                ball.sety(290)
                ball.dy *= -1
                winsound.PlaySound("dong.wav", winsound.SND_ASYNC) # for windows
                #os.system("afplay dong.wav&")    ~ for Mac
                #os.system("aplay dong.wav&")     ~ for Linux
            
            elif ball.ycor() < -290:
                ball.sety(-290)
                ball.dy *= -1
                winsound.PlaySound("dong.wav", winsound.SND_ASYNC) # for windows
                #os.system("afplay dong.wav&")    ~ for Mac
                #os.system("aplay dong.wav&")     ~ for Linux
        
            # Left and right
            if ball.xcor() > 350:
                score_a += 1
                pen.clear()
                pen.write("{}: {}  {}: {}".format(player1, score_a, player2, score_b), align="center", font=("Courier", 24, "normal"))
                ball.goto(0, 0)
                ball.dx *= -1
        
            elif ball.xcor() < -350:
                score_b += 1
                pen.clear()
                pen.write("{}: {}  {}: {}".format(player1, score_a, player2, score_b), align="center", font=("Courier", 24, "normal"))
                ball.goto(0, 0)
                ball.dx *= -1
        
            # Paddle and ball collisions
            if ball.xcor() < -340 and ball.ycor() < paddle_a.ycor() + 50 and ball.ycor() > paddle_a.ycor() - 50:
                ball.dx *= -1 
                winsound.PlaySound("pinn.wav", winsound.SND_ASYNC) # for windows
                #os.system("afplay pinn.wav&")    ~ for Mac
                #os.system("aplay pinn.wav&")     ~ for Linux
            
            elif ball.xcor() > 340 and ball.ycor() < paddle_b.ycor() + 50 and ball.ycor() > paddle_b.ycor() - 50:
                ball.dx *= -1
                winsound.PlaySound("pinn.wav", winsound.SND_ASYNC) # for windows
                #os.system("afplay pinn.wav&")    ~ for Mac
                #os.system("aplay pinn.wav&")     ~ for Linux
    except TclError:
        pass

# To disable the evaluate button till all the fields have been updated
def validateentry(*args):
    x = p1.get()
    y = p2.get() 
    if x and y:
        C.config(state='normal', text='Start')
    else:
        C.config(state='disabled', text='Enter Player Names')    

top = Tk()
#top.overrideredirect(True)

p1 = StringVar(top)
p2 = StringVar(top)

p1.trace("w", validateentry)
p2.trace("w", validateentry)

# Function for close button
L1 = Label(top, text="Player 1 name: ",).grid(row=0,column=0)
L2 = Label(top, text="Player 2 name: ",).grid(row=1,column=0)
E1 = Entry(top, bd =5, textvariable=p1, width=67)
E1.grid(row=0,column=1)
E2 = Entry(top, bd =5, textvariable=p2, width=67)
E2.grid(row=1,column=1)
C=Button(top, text ="Ok",command = startGame, width=10, state='disabled')
C.grid(row=2,column=1,)

top.mainloop()