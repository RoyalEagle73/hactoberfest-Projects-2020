from tkinter import *

expression = ""

def btn(n):
    global expression
    expression += str(n)
    v.set(expression)

def calculate():
    global expression
    result = eval(expression)       # eval() funtion returns the value of string expression, >> eval("12+3") ---> o//p: 17
    v.set(result)
    
def clear():
    global expression
    expression = ""
    v.set(expression)
    
w = Tk()
w.configure(bg = "lightcyan")
w.title("Basic Calculator")

v = StringVar()

E = Entry(w, bd = 5, bg = "linen", font = ("arial", 40, "bold"), width = 15, textvariable = v)
# textvariable is an attribute which is used to set values in Entry. 

B_one = Button(w, text = "1", bd = 10, bg = "aquamarine", font = ("arial", 25, "bold"), command = lambda : btn(1))
B_two = Button(w, text = "2", bd = 10, bg = "aquamarine", font = ("arial", 25, "bold"), command = lambda : btn(2))
B_three = Button(w, text = "3", bd = 10, bg = "aquamarine", font = ("arial", 25, "bold"), command = lambda : btn(3))
B_four = Button(w, text = "4", bd = 10, bg = "aquamarine", font = ("arial", 25, "bold"), command = lambda : btn(4))
B_five = Button(w, text = "5", bd = 10, bg = "aquamarine", font = ("arial", 25, "bold"), command = lambda : btn(5))
B_six = Button(w, text = "6", bd = 10, bg = "aquamarine", font = ("arial", 25, "bold"), command = lambda : btn(6))
B_seven = Button(w, text = "7", bd = 10, bg = "aquamarine", font = ("arial", 25, "bold"), command = lambda : btn(7))
B_eight = Button(w, text = "8", bd = 10, bg = "aquamarine", font = ("arial", 25, "bold"), command = lambda : btn(8))
B_nine = Button(w, text = "9", bd = 10, bg = "aquamarine", font = ("arial", 25, "bold"), command = lambda : btn(9))
B_zero = Button(w, text = "0", bd = 10, bg = "aquamarine", font = ("arial", 25, "bold"), command = lambda : btn(0))
B_equal = Button(w, text = "=", bd = 10, bg = "khaki", font = ("arial", 30, "bold"), command = calculate)
B_clear = Button(w, text = "Cl", bd = 10, bg = "tomato", fg = "white", font = ("arial", 30, "bold"), command = clear)
B_plus = Button(w, text = "+", bd = 10, bg = "navy", fg = "white", font = ("arial", 25, "bold"), command = lambda : btn("+"))
B_minus = Button(w, text = "-", bd = 10, bg = "navy", fg = "white", font = ("arial", 25, "bold"), command = lambda : btn("-"))
B_mul = Button(w, text = "X", bd = 10, bg = "navy", fg = "white", font = ("arial", 25, "bold"), command = lambda : btn("X"))
B_div = Button(w, text = "/", bd = 10, bg = "navy", fg = "white", font = ("arial", 25, "bold"), command = lambda : btn("/"))

E.grid(row = 1, column = 1, columnspan = 4)
B_one.grid(row = 2, column = 1)
B_two.grid(row = 2, column = 2)
B_three.grid(row = 2, column = 3)
B_four.grid(row = 2, column = 4)
B_five.grid(row = 3, column = 1)
B_six.grid(row = 3, column = 2)
B_seven.grid(row = 3, column = 3)
B_eight.grid(row = 3, column = 4)
B_nine.grid(row = 4, column = 1)
B_zero.grid(row =4, column = 2)
B_equal.grid(row = 4, column = 3)
B_clear.grid(row = 4, column = 4)
B_plus.grid(row = 5, column = 1)
B_minus.grid(row = 5, column = 2)
B_mul.grid(row = 5, column = 3)
B_div.grid(row = 5, column = 4)

w.mainloop()
