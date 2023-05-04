#TODO : Paint Houses  logic not working 

# Problem statement: There are N houses. The amount to color each house with Red, Green, Blue colors is
# given. Write a program to find the minimum amount to paint all houses such that no 2 adjacent houses
# have the same color.
# Input:
# N = 3
# Red = [6, 5, 3]
# Green = [3, 1, 6]
# Blue = [9, 4, 2]

# solution:
def solution(tookRed,tookGreen,tookBlue,houseNo,totalhouse):
    if houseNo == totalhouse:
        return 0
    if tookRed:
        return min(solution(False,True,False,houseNo+1,totalhouse),solution(False,False,True,houseNo+1,totalhouse))+Red[houseNo]
    elif tookGreen:
        return min(solution(True,False,False,houseNo+1,totalhouse),solution(False,False,True,houseNo+1,totalhouse))+Green[houseNo]    
    elif tookBlue:
        return min(solution(True,False,False,houseNo+1,totalhouse),solution(False,True,False,houseNo+1,totalhouse))+Blue[houseNo] 


N = 3
Red = [5,50,0]
Green = [10,100,10]
Blue = [1,0,60]
ansifRed = solution(True,False,False,1,N) + Red[0]
ansifGreen = solution(False,True,False,1,N) + Green[0]
ansifBlue = solution(False,False,True,1,N) + Blue[0]
print(Red)
print(Green)
print(Blue)
print("The minimum amount to paint all houses such that no 2 adjacent houses have the same color is: ", min(ansifRed,ansifGreen,ansifBlue))



# Red = []
# Green = []
# Blue = []
# N = int(input("Enter the number of houses: "))
# for i in range(N):
#     Red.append(int(input(f"Enter the amount to color house {i+1} with Red: ")))
#     Green.append(int(input(f"Enter the amount to color house {i+1} with Green: ")))
#     Blue.append(int(input(f"Enter the amount to color house {i+1} with Blue: ")))