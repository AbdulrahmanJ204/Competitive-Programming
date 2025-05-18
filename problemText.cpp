Given a simple undirected graph of {$n$} nodes and {$m$} edges, each edge has time {$t$}, which represents the edge's valid time. 
crossing an edge costs 2 seconds.
some nodes have a generator of {$G$} units, gives $G_i$ units every time you visit the node

with one unit of $G$, you lose 1 unit of G and can:

1- go from node $A$ to node $B$ if there is a node $C$ connected with both $A$ and $B$, and the cost is 2.

2- go from node $A$ to node $B$ with cost 2 if they are connected directly.

Notes:

1- When using $G$ units no need for the edge to be valid.

2- you can not carry more than 10 $G$ units.

calculate the minimum time needed to go from node $1$ to $n$ , if it is impossible print -1.
 