import math
def sqrt_bs(no):
    if no < 0:
        return None
    if no==0:
        return 0.0
    start = 1.0
    end = float(no)
    epsilon = 1.0e-10
    while end-start > epsilon:
        mid = (start + end) / 2
        if mid * mid < no:
            start = mid
        else:
            end = mid 
    return start

def sqrt_newton(no):
    if no==0:
        return 0.0
    epsilon = 1.0e-10
    x = 1.0
    while abs(x*x - no) > epsilon:
        x = (x + no/x) / 2
    return x
print('using newton method',sqrt_newton(0))
print('using binary search',sqrt_bs(0))
print('using inbuilt function',math.sqrt(0))