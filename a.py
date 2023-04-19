import math
#Задача 1
R1=20.9*10**3
R2=297*10**3
С0=33.2*10**(-12)
print((1/R1 + 1/R2)/(2*math.pi*С0))
#Задача 2
CC=3*10**8
a=3.8
u=142.4*10**3
print(CC/(2*a*u))
#Задача 3
R=8.5*10**3
C=96.7*10**(-12)
k=25.1
c=2*math.pi*R*C
d=2*math.pi*R*C*(k+1)
A=0.5*(d**4) - (c**2)*(d**2)
B=c**2
CCC=-0.5
discr = B**2 - 4 * A * CCC
print(f"Дискриминант D = {discr}")
if discr > 0:
    x1 = (-B + math.sqrt(discr)) / (2 * A)
    x2 = (-B - math.sqrt(discr)) / (2 * A)
    print(f"x1 ={x1}, x2={x2}")
elif discr == 0:
    x = -B / (2 * A)
    print(f"x = {x}")
else:
    print("Корней нет")
print(math.sqrt(x1))