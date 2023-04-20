#find gcd of 2 no

def gcd(a,b):
    if a==b :
        return a
    if(a>b) :
        return gcd(a-b,b)
    else :
        return gcd(a,b-a) 
x = int(input("enter a :"))
y = int(input("enter b "))
print("gcd is : ",gcd(x,y))