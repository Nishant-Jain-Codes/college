import math

def pow(x,n):
    if(n==0):
        return 1.0
    return x*pow(x,n-1)

print('power, using pow function',pow(2,3))
print('power, using inbuilt function',math.pow(2,3))