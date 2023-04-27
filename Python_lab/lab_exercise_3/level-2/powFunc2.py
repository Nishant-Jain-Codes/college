#TODO fix the bug !there is an infinte loop at line 20 i think
import math 
factors={}
def printFactor():
    print('printing factors of given number in power format')
    for factor in factors.items():
        print(f"{factor[0]}^{factor[1]} ",end="")
def isPrime(no):
    if(no<=2):
        return True
    for i in range (2,int(math.sqrt(no))):
        if no%i == 0:
            return False
    return True
def giveFactorsMultiplication(no):
    if no<=3 :
        factors.update({no:1})
    else :
        i=2
        while(i<=no):
            if(not isPrime(i)):
                i=i+1
            else :
                while (no%i==0):
                    if i in factors:
                        factors[i]+=1
                    else:
                        factors.update({i:1})
                    no=no/i
            i+=1
    printFactor()
    print(factors)

giveFactorsMultiplication(int(input("Enter a number: ")))
