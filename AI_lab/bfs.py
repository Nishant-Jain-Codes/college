from tabulate import tabulate

def bfsOfGraph( V, adj):
    # code here
    tableData = []
    colNames = ["Current Node","Queue","Processed Nodes" , "Status"]
    visited = {}
    for v in V: 
        visited[v] = 1
    q = []
    answer = []
    q.append(next(iter(adj)))
    while(len(q)):
        frontNode = q.pop(0)
        answer.append(frontNode)
        visited[frontNode]=3
        curAdj = adj[frontNode]
        for adjNode in curAdj:
            if visited[adjNode]==1:
                q.append(adjNode)
                visited[adjNode] = 2
        tableData.append([frontNode , q.copy() , answer.copy() ,visited.copy()])
    print(tabulate(tableData, headers=colNames))

#taking edge list in input 
V= int(input(""))
vertices = []
adj = {}
for i in range (0,V):
    curNode = input()
    curAdj = [x for x in input().split()]
    adj[curNode] = curAdj
    vertices.append(curNode)
bfsOfGraph(vertices,adj)


#input
# 9
# a
# f c b
# b
# a c g
# c
# a b d e f g
# d
# c f e j
# e
# c d g j k
# f
# a c d
# g
# b c e k
# j
# d c j
# k
# e g j