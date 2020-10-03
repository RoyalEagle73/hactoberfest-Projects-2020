from math import acos, degrees, sqrt
AB = int(input())
BC = int(input())
AC = sqrt(AB*AB + BC*BC)
BM = AC / 2
angel = round(degrees(acos((BC * BC + BM * BM - BM * BM) / (2.0 * BM * BC))))
print(str(angel)+'°')