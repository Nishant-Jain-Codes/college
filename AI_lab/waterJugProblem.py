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
def solvebfs(n,m,d):
    visited = [[0]*(m+1) for i in range(n+1)]
    queue = []
    queue.append([0,0,1])
    goalAchieved = False
    while(len(queue)):
        front = queue.pop(0)
        x,y,level=front[0],front[1],front[2]
        # if(x==0 and y ==0):
            # print("Starting  ! ! ! ! ! ! ")
        print(f"({x},{y}) @{level}")
        visited[x][y]=1
        if(x == d or y==d):
            # print("goal achieved ! ! ! ! ! ! ")
            goalAchieved = True
            return level
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
        return -1
def dfs(idx,path,x,y,d,j1,j2):
    if(idx>=len(path)):
        return False
    if(idx==len(path)-1 and (x==d or y ==d) ):
        newVal = [x,y]
        path[idx]=newVal
        return True
    prevVal = path[idx]
    newVal = [x,y]
    path[idx]=newVal
    possiblePaths = givePossibleMoves(x,y,j1,j2)
    for possiblity in possiblePaths:
        nextX , nextY = possiblity
        if dfs(idx+1,path,nextX,nextY,d,j1,j2):
            return True
    path[idx]=prevVal
    return False 

def backtrackingSol(j1,j2,d,maxSteps):
    if maxSteps == -1:
        print("not possible to find output")
        return
    path = [[0]*2 for x in range(maxSteps)]
    print("max steps -> ",maxSteps)
    ans = dfs(0,path,0,0,d,j1,j2)
    for step in path:
        print(step)


# logical error giving wrong order of steps taken as it is bfs
j1,j2,d = map(int , input("enter j1 , j2 , d\n").split())
print("BFS output ")
maxSteps = solvebfs(j1,j2,d)
print("DFS + Backtracking output")
backtrackingSol(j1,j2,d,maxSteps)
