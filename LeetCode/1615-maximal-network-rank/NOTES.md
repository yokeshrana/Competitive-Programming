Build the graph (adjacency list).
Compute network rank of all pairs of cities.
Simply compute the sum of neighbors (connected cities) of both cities.
Decrement 1 from the computed sum if the cities under consideration are connected to each other.
(Otherwise the road between those 2 cities will be double counted)
Update the maximal network rank if the network rank computed is greater than the current value.