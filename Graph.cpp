#include <iostream>
#include <vector>
using namespace std;
//////////////////////
/////Introduction/////
// References: https://www.geeksforgeeks.org/graph-and-its-representations/
// Composition: vertices and edge
  // vertices(V): refer as nodes
  // edge(E): lines or arcs that connect two nodes in graph
  // Graph denotes as `G(V,E)`
// Applications: social network analysis, recommendation system, computer network, team and player interaction in sports area, roads and transportation, high frequency trading...
// Types:
  // Null graph: with no edge
  // Trivial graph: have only one vertex
  // Undirected graph: have no direction, nodes are unordered pairs
  // Directed graph: edge has direction, nodes are ordered pairs
  // Connected graph: from one node we can visit any other node
  // Disconnected graph: at least one node is not reachable
  // Regular graph: the degree of every vertex is equal to K 
  // Complete graph: from each node there is an edge to each other node
  // Cycle graph: the degree of each edge=2. The graph is a cycle in itself.
  // Cyclic graph: contains at least one cycle 
  // Directed acyclic graph: a directed graph doesn't contain any cycle
  // Bipartite graph: vertex can be divided into 2 disjoint sets. No two vertices in the same set are connected by an edge.
  // (Un)Weighted graph: edges have (no) weights or costs associated with them
  // Trees: a connected graph without any cycle
  // Dense graph: has many edges compared to the number of vertices.
  // Sparse graph: has relatively few edges compared to the number of vertices


/////////////////////
/////Terminology/////
// Adjacent vertices: a direct edge
// Degree of a node: number of edges go connect the vertex
// Path: a sequence of vertices that are connected by edges. A simple path doesn't contain repeated vertex or edge.
// Weight: can be assigned to edges, treated as the distance(d(A,B)) or cost between two vertices
// Cycle: a path starts and ends at the same vertex
// Connectedness: if there is a path between 2 vertices
// Connected component: in disconnected graph, the number of connected sub-graphs
// eccentricity of vertex: e(V), maximum distance from a vertex to all other vertices
// Radius of a connected graph: 
  // r(G), where G is the connected graph. 
  // The minimum value of eccentricity from all vertices
// Diameter of a connected graph: d(G), the maximum value of eccentricity from all vertices
// Central point: The vertex which has minimum eccentricity. If e(V)=r(G), v is the central point


////////////////////////
/////Implementation/////
// Three ways: 
  // 1. Edge list
    // create a vertices array and edges(in form of pair of elements) array
    // A bad way for implementation T=O(n^2)
  // 2. Adjacency list
    // each vertex will have a list to store its direct edges
    // T=O(N)
    // Optimization: Reduce the time complexity constant, maintain a hash map, using elements as keys, use T/F as values
  // 3. Adjacency matrix
    // create a matrix whose number of columns and rows=number of vertices, filled with T/F (boolean matrix). T: there exists an edge between specific nodes
    // Disadvantage: it consumes a lot of spaces, Space complexity will be large.(eg: for spare graph, major boxes filled with false value)
    // Advantage: very fast and easy to implement, small time complexity


//////////////////////////
/////Adjacency Matrix/////
// create a matrix with right size
// initialize it with false value
// use loop number of edge time to check edges exist or not
int main(){
  int vertices, edges;
  cin>>vertices>>edges;
  //create a matrix using static allocation
  vector<vector<int> > matrix(vertices, vector<int>(vertices,0)); //0 false, 1 true
  // create a matrix using dynamic allocation
  // int matrix[vertices][vertices];
  // loop for checking whether there exists an edge
  for(int i=1; i<=edges; i++){
    int firstVertex, secondVertex;
    cin>>firstVertex>>secondVertex;
    matrix[firstVertex][secondVertex]=1;
    matrix[secondVertex][firstVertex]=1;
  }
  return 0;
}
// return
// 4
// 3
// 0 1
// 0 2
// 1 3

