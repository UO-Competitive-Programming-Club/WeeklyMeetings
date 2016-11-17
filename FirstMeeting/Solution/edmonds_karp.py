graph,V,int_max = list(),6,999999

def bfs(s,t,parent):
    global V,graph
    vis =[False for i in range(V)] #to keep track of visited nodes
    q = list() #this is our queue to traverse the dfs
    q.insert(0,s)
    vis[s]=True
    parent[s]=-1
    while len(q)!=0:
        u = q.pop()
        for i in range(V):
            if not vis[i] and graph[u][i]>0:
                q.insert(0,i)
                parent[i]=u
                vis[i]=True
    return vis[t] #Start from source and if we reach the sink, then sink(t) should
                  # be visited , it returns the same.


def fordFulkerson(s,t):
    global graph,V,int_max
    parent, max_flow = [0 for i in range(V)],0
    #There is an augumented path from src to sink(s to t) if bfs returns true
    while bfs(s,t,parent):
        path_flow = int_max
        v = t
        while v!=s:
            u = parent[v]
            path_flow = min(path_flow,graph[u][v])#choose flow for this augumented path.
            v = parent[v] #to trace the path (child->parent)
        v = t
        while v!=s: #to update residual capacity
            u = parent[v]
            graph[u][v]-= path_flow #update the min. path flow on traced path edge
            graph[v][u]+= path_flow #update the same on backedge
            v = parent[v]
        max_flow += path_flow #adding all the min. path flows to get final max flow
    return max_flow


if __name__=='__main__':
    graph = [[0,16,13,0,0,0],
             [0,0,10,12,0,0],
             [0,4,0,0,14,0],
             [0,0,9,0,0,20],
             [0,0,0,7,0,4],
             [0,0,0,0,0,0]
             ]
    src = 0 #source node
    sink = 5 #sinking node
    print("The maximum possible flow is",fordFulkerson(src,sink))
