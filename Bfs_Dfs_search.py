class Graph:
    def __init__(self,v):
        self.v = v
        self.l = [[] for _ in range(self.v)]
    
    def addEdge(self, x, y):
        self.l[x].append(y)
        self.l[y].append(x)

    def printEdge(self):
        for i in range(self.v):
            print("Vertex {} -> ".format(i), end = " ")
            for j in self.l[i]:
                print(j, end= " ")
            print()

    def bfs(self, src):
        q = []
        visited = {}
        for i in range(len(self.l)):
            visited[i] = False
        q.append(src)
        print("BFS Traversal with Source Node {}".format(src))
        visited[src] = True
        while q:
            node = q[0]
            print(q.pop(0), end= " ")
            for i in self.l[node]:
                if not visited[i]:
                    q.append(i)
                    visited[i] = True
    
    def dfs_helper(self, source, visited):
        print(source, end= " ")
        visited[source] = True
        for i in self.l[source]:
            if not visited[i]:
                self.dfs_helper(i, visited)

    def dfs(self, source):
        visited = {}
        print("DFS Traversal with Source Node {}".format(source))
        for i in range(len(self.l)):
            visited[i] = False
        self.dfs_helper(source, visited)

if __name__ == "__main__":
    g = Graph(4)
    g.addEdge(0,1)
    g.addEdge(0,2)
    g.addEdge(1,2)
    g.addEdge(2,0)
    g.addEdge(2,3)
    g.addEdge(3,3)
    g.printEdge()
    g.bfs(2)
    print()
    g.dfs(0)
    print()
