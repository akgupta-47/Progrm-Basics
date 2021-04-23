from collections import defaultdict
class Graph:
	# Constructor
	def __init__(self):
		self.graph = defaultdict(list)

	def addEdge(self,u,v):
		self.graph[u].append(v)

	# Function to print a BFS of graph
	def BFS(self, s):

		# Mark all the vertices as not visited
		# max(self.graph) gives 3 the highest key value
		visited = [False] * (max(self.graph) + 1)

		# Create a queue for BFS
		queue = []
		queue.append(s)
		visited[s] = True

		while queue:
			s = queue.pop(0)
			print (s, end = " ")

			for i in self.graph[s]:
				if visited[i] == False:
					queue.append(i)
					visited[i] = True

g = Graph()
z = int(input("total edges"))
for i in range(0,z):
    x = int(input())
    y = int(input())
    g.addEdge(x,y)

print ("Following is Breadth First Traversal")
start = int(input(" enter starting point"))
g.BFS(start)

