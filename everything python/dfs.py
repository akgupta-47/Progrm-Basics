graphNet = {
   "A":["D","C","B"],
   "B":["E"],
   "C":["G","F"],
   "D":["H"],
   "E":["I"],
   "F":["J"],
   "I":[],
   "J":[],
   "G":[],
   "H":[]
}

def DFS(graph, source):
    if source is None or source not in graph:
        return "Please respect the graph and enter a legitimate input"
        
    route = []
    stk = [source]
    while(len(stk)!= 0):
        temp = stk.pop()
        if temp not in route:
            route.append(temp)
        if temp not in graph:
            print(temp)
            continue
        for child in graph[temp]:
            stk.append(child)
    return "->".join(route)

print(DFS(graphNet, "A"))
