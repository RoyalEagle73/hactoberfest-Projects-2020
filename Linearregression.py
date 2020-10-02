import numpy as np
import matplotlib.pyplot as plt
x=[17,13,12,15,16,14,16,16,18,19]
y=[94,73,59,80,93,85,66,79,77,91]
xm=np.mean(x)
ym=np.mean(y)
dx=[]
dy=[]
dxdy=[]
dx2=[]
dy2=[]
for i in range(0,10):
    dx.append(x[i]-xm)
    dy.append(y[i]-ym)
for i in range(0,10):
    dxdy.append(dx[i]*dy[i])
    dx2.append(dx[i]*dx[i])
    dy2.append(dy[i]*dy[i])
num=np.sum(dxdy)
t1=np.sum(dx2)
t2=np.sum(dy2)
t=t1*t2
den=t**0.5
r=num/den
sx=((np.sum(dx2))**0.5)/3
sy=((np.sum(dy2))**0.5)/3
b=r*sy/sx
a=ym-(b*xm)
x2=[i*b for i in x]
y2=a+x2
print(y2)
x1=int(input('Enter x'))
y1=a+b*x1

plt.plot(x,y2,'r--',x1,y1,'b^')
plt.grid()
plt.xlabel('x')
plt.ylabel('y=a+bx')
plt.title('Linear Regression')
plt.show()

