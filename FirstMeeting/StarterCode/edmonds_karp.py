import queue

def get_input():
    """
        first line numV is the number of vertices of the graph
        second line contains the index of source and sink vertices
        next numV lines is the matrix representation of the graph
        """
    numV = int(input().strip())
    source, sink = map(int, input().split())
    graphMatrix = []
    # get matrix representation of graph:
    for i in range(numV):
        graphMatrix.append(list(map(int, input().split())))
    return (numV, source, sink, graphMatrix)

def process_bfs_backtrail(sink, backtrail):
    path = []
    cur = sink
    prev = backtrail[sink]
    while cur != -1:
        path.append(cur)
        cur = prev
        prev = backtrail[prev]
    path.reverse()
    return path

def find_path_bottleneck(path, graphMatrix):
    """
        Returns the lowest residual capacity of any edge in path
        """
    curMin = float("inf")
    for next in range(1, len(path)):
        cur = next-1
        curMin = min(curMin, graphMatrix[path[cur]][path[next]])
    return curMin

def bfs(numV, source, sink, graphMatrix):
    """
        Returns a tuple containing (bottleneck, augmentingPath)
        Bottleneck is the lowest residual capacity value of any edge in the path.
        If no augmenting path exists, returns (0, [])
        """
    notVisited = set(range(numV))
    q = queue.Queue()
    q.put((source, -1))
    # We will keep track of the shortest path from each node to the source
    # using backtrail. backtrail[node] points to the next node in the path
    # back to source
    backtrail = [0 for i in range(numV)]
    while not q.empty():
        curNode, prev = q.get()
        if curNode in notVisited:
            notVisited.remove(curNode)
            backtrail[curNode] = prev
            if curNode == sink:
                path = process_bfs_backtrail(sink, backtrail)
                return (find_path_bottleneck(path, graphMatrix), path)
            for otherNode in notVisited:
                if graphMatrix[curNode][otherNode] > 0:
                    q.put((otherNode, curNode))
    return (0, [])
##################################################
# Ignore code above this line
##################################################

def edmonds_karp(numV, source, sink, graphMatrix):
    """
    Returns the maximum flow value (an integer)
    """
    flow = 0
    while True:
        # Find an augmenting path:
        pathCapacity, path = bfs(numV, source, sink, graphMatrix)
        if pathCapacity == 0:
            # No augmenting path was found, which means we're done:
            break
        ##########################################
        # Your code here
        ##########################################
    return flow

def update_residual_graph(pathCapacity, path, graphMatrix):
    # For each edge on the path, subtract pathCapacity from the forward edge
    # and add it to the backwards edge in graphMatrix
    ###################################################
    # Your code here
    ###################################################
    return

def main():
    print(edmonds_karp(*get_input()))

if __name__ == "__main__":
    main()
