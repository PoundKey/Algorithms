# Graph Algorithm

## Djikstra’s Algorithm - Shortest Paths in a Graph
### Introduction
- An algorithm run on a weighted graph
- Starts with an initial node and a destination node
- Finds the least cost path to the destination node

### Steps
1. Assign to every node a tentative distance value: zero for initial node and infinity to all other nodes
2. Keep a set of visited nodes and unvisited nodes.
3. For current node, consider all of its unvisited neighbors and calculate:  
_e_ = __(distance_to_current_node + distance_from_current_to_neighbor)__
4. If _e_ is __less than__ current tentative distance, replace the tentative value with e.
5. After finishing considering all the neighbors of the current node, mark the current node as visited and remote it from the unvisited set.
6. Set the current node as the next unvisited node with the __smallest__ tentaive distance.
7. If the destination node has been marked visited, the algorithm finishes.
8. Else go back to step 3.

![Djikstra’s Algorithm](img/djikstra.gif)
### Pseudocode
```python
Input: Graph G = (V, E), directed or un directed 
			 Positive edge lengths l, vertex u ∈ V
Output: For all vertices u reachable from s, dist(u) is set to the distance from s to u

dist[s] ← 0												# (distance to source vertex is zero)
for all v ∈ V – {s}									#	(set all other distances to infinity)					
	do dist[v] ←∞ 										# 
S←0																# (S, the set of visited vertices is initially empty)
Q←V 																# (Q, the queue initially contains all vertices)
while Q != 0												# (while the queue is not empty)
	do u ← minDistance(Q,dist) 			# (select the element of Q with the min. distance)
	S←S∪{u}													# (add u to list of visited vertices)
	for all v ∈ neighbors[u]					#
		 if dist[v] > dist[u] + w(u, v) # (if new shortest path found)
				then d[v] ←d[u] + w(u, v)  # (set new value of shortest path) 
return dist													# (if desired, add traceback code)
```

__Runtime__: Using a binary heap, __O( |E| + |V|log|V| )__

__Space__: Using a binary heap, __O( |V| )__, up to |V| vertices may have to be stored.


## The Minimum Spanning Tree Problem

### Kruskal’s Algorithm 

### Prim’s Algorithm