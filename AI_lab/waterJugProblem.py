def givePossibleMoves(curX,curY,maxX,maxY):
    moves = []
    if(curX<maxX): #Fill the x-gallon jug
        moves.append([maxX,curY])
    if(curY<maxY): #Fill the y-gallon jug
        moves.append([curX,maxY])
    if(curX>0): #emptying the x-gallon jug
        moves.append([0,curY])
    if(curY>0): #emptying the y-gallon jug
        moves.append([curX,0])
    diffX = maxX-curX #capacity of x left
    diffY = maxY-curY #capacity of y left
    overFlowX = curY-diffX # if x overflows
    overFlowY = curX-diffY # if y overflow
    if(diffX>=curY):#emptyting y in x
        moves.append([curX+curY,0])
    if(diffY>=curX): #emptying x in y
        moves.append([0,curY+curX])
    if(overFlowY>0):
        moves.append([overFlowY,maxY])
    if(overFlowX>0):
        moves.append([maxX,overFlowX])
        
    return moves
def solve(n,m,d):
    visited = [[0]*(m+1) for i in range(n+1)]
    queue = []
    queue.append([0,0,0])
    goalAchieved = False
    while(len(queue)):
        front = queue.pop(0)
        x,y,level=front[0],front[1],front[2]
        if(x==0 and y ==0):
            print("Starting  ! ! ! ! ! ! ")
        # if not visited[x][y]:
        print(f"({x},{y}) @{level}")
        visited[x][y]=1
        if(x == d or y==d):
            print("goal achieved ! ! ! ! ! ! ")
            goalAchieved = True
            break
        possibleMoves = givePossibleMoves(x,y,n,m)
        for move in possibleMoves:
            # print('move',move)
            moveX,moveY = move[0],move[1]
            if not visited[moveX][moveY]:
                queue.append([moveX,moveY,level+1])
                # visited[moveX][moveY] = 1
    if not goalAchieved:
        print("the goal cant be achieved ! ! ! ! ! ! ! ")

# logical error giving wrong order of steps taken as it is bfs
j1,j2,d = map(int , input("enter j1 , j2 , d\n").split())
solve(j1,j2,d)
