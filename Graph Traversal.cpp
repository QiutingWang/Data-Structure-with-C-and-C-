#include <iostream>
#include <queue>
#include <vector>
using namespace std;
///////////////////////////////////////////
/////DFS(Depth First Search) Traversal/////Only for Connected Graph
// Procedure: 
  // 1. print the starting vertex(a pointer)
  // 2. call the recursion on adjacent vertices
  // Notes: we should not repeatedly print the pairs(eg: print A-B then B-A is incorrect).
    // Solution: 
      // maintain a visited array(or hash map) whose size=numbers of vertices present, initially filled with True/False boolean values.
      // once the element has been already called, the value set to be True.
      // if it is already visited, the value cannot be called and printed again.
// Printing logic: once we go along one direction(normally start with the smallest value), we keep going along this direction until we can go along another direction.
// Reference: https://www.programiz.com/dsa/graph-dfs
void DFSPrint(vector<vector<int> > v, int startVertex, vector<bool> &visited){ //v represent the graph
  cout<<startVertex<<endl; //print the start vertex
  visited[startVertex]=true;

  int vertices=v.size();
  for(int i=0; i<vertices; i++){
    if(v[startVertex][i]==1 && visited[i]==false){ //if there exists an adjacent vertex, print it
      DFSPrint(v, i, visited); //call the recursion
    }
  }
}

int main(){
  int vertices, edges;
  cin>>vertices>>edges; // input the numbers of vertex and edge
  
  vector<vector<int> > matrix(vertices, vector<int>(vertices,0)); 
  
  for(int i=1; i<=edges; i++){
    int firstVertex, secondVertex;
    cin>>firstVertex>>secondVertex;
    matrix[firstVertex][secondVertex]=1;
    matrix[secondVertex][firstVertex]=1;
  }
  vector<bool> visited(vertices, false);
  DFSPrint(matrix, 0, visited);
  return 0;
}
// return
// 7
// 7
// 0 1
// 0 2
// 1 5
// 5 4
// 3 4
// 2 3
// 2 6

// 0
// 1
// 5
// 4
// 3
// 2
// 6


/////////////////////////////////////////////
/////BFS(Breadth First Search) Traversal/////Only for Connected Graph
// References: https://www.programiz.com/dsa/graph-bfs
// Printing Logic: 
  // print the smaller elements which located in the same level first.
  // a kind of `level-order traversal`
// Procedure:
  // maintain a queue which store start vertex's adjacent vertices, push value into queue then print and pop it
  // we need to use a `visited array` for avoiding repeated printing
void BFSPrint(vector<vector<int> > v, int startVertex){
  int vertices=v.size();
  vector<bool> visited(vertices, false); //size=vertices, filled with false value initially
  queue<int> q; //use queue to print it
  // start from startVertex
  q.push(startVertex);
  visited[startVertex]=true;
  // iteration
  while(!q.empty()){
    int currentVertex=q.front(); 
    cout<<currentVertex<<endl;
    q.pop();
    for(int i=0; i<vertices; i++){
      if(v[currentVertex][i] && !visited[i]){
        q.push(i); // put its adjacent vertices into queue
        visited[i]=true;
      }
    }
  }
}

int main(){
  int vertices, edges;
  cin>>vertices>>edges; 
  
  vector<vector<int> > matrix(vertices, vector<int>(vertices,0)); 
  
  for(int i=1; i<=edges; i++){
    int firstVertex, secondVertex;
    cin>>firstVertex>>secondVertex;
    matrix[firstVertex][secondVertex]=1;
    matrix[secondVertex][firstVertex]=1;
  }
  BFSPrint(matrix, 0);
  return 0;
}
// return 
// 7
// 7
// 0 1
// 0 2
// 1 5
// 5 4
// 3 4
// 2 3
// 2 6

// 0
// 1
// 2
// 5
// 3
// 6
// 4


////////////////////////////////////
/////DFS for Disconnected Graph/////
// Phenomena: after iterate the first connected component once, other connected components are not taken into consideration.
// Solution: take advantage of visited array, iterating the visited array from the first left unvisited vertex to right again and again until all the vertices come true in visited array.

//copy DFSPrint function code above
void DFSPrint(vector<vector<int> > v, int startVertex, vector<bool> &visited){ 
  cout<<startVertex<<endl; 
  visited[startVertex]=true;

  int vertices=v.size();
  for(int i=0; i<vertices; i++){
    if(v[startVertex][i]==1 && visited[i]==false){ 
      DFSPrint(v, i, visited); 
    }
  }
}
// fix the code to work for disconnected graph
void DFSDisconnected(vector<vector<int> >matrix){ // take graph as input
  int vertices=matrix.size();
  vector<bool> visited(vertices, false);
  // iterate the array to identify the unvisited vertices
  for(int i=0; i<vertices; i++){
    if(!visited[i]){
      DFSPrint(matrix, i, visited); // use `i` as startVertex now
    }
  }
}

int main(){
  int vertices, edges;
  cin>>vertices>>edges; // input the numbers of vertex and edge
  
  vector<vector<int> > matrix(vertices, vector<int>(vertices,0)); 
  
  for(int i=1; i<=edges; i++){
    int firstVertex, secondVertex;
    cin>>firstVertex>>secondVertex;
    matrix[firstVertex][secondVertex]=1;
    matrix[secondVertex][firstVertex]=1;
  }
  DFSDisconnected(matrix);
  return 0;
}
// return
// 7
// 7
// 0 1
// 1 6
// 1 3
// 6 3
// 2 4
// 2 5
// 4 5

// 0
// 1
// 3
// 6
// 2
// 4
// 5


////////////////////////////////////
/////BFS for Disconnected Graph/////
void BFSPrint(vector<vector<int> > v, int startVertex, vector<bool> &visited){ //since we change it, we need to pass by reference
  int vertices=v.size();
  queue<int> q; 

  q.push(startVertex);
  visited[startVertex]=true;
  // iteration
  while(!q.empty()){
    int currentVertex=q.front(); 
    cout<<currentVertex<<endl;
    q.pop();
    for(int i=0; i<vertices; i++){
      if(v[currentVertex][i] && !visited[i]){
        q.push(i); 
        visited[i]=true;
      }
    }
  }
}

void BFSDisconnect(vector<vector<int> >matrix){
  int vertices=matrix.size();
  vector<bool> visited(vertices, false);
  // iterate the array to identify the unvisited vertices
  for(int i=0; i<vertices; i++){
    if(!visited[i]){
      BFSPrint(matrix, i, visited); // use `i` as startVertex now
    }
  }
}


int main(){
  int vertices, edges;
  cin>>vertices>>edges; 
  
  vector<vector<int> > matrix(vertices, vector<int>(vertices,0)); 
  
  for(int i=1; i<=edges; i++){
    int firstVertex, secondVertex;
    cin>>firstVertex>>secondVertex;
    matrix[firstVertex][secondVertex]=1;
    matrix[secondVertex][firstVertex]=1;
  }
  BFSDisconnect(matrix);
  return 0;
}
// return 
// 8
// 6
// 0 2
// 0 4
// 2 4
// 2 3
// 1 5
// 6 7

// 0
// 2
// 4
// 3
// 1
// 5
// 6
// 7


/////////////////////////////////////////////////////
/////DFS(BFS) to Find No. of Connected Component/////
void DFSConnected(vector<vector<int> > matrix){    /////void BFSConnected(vector<vector<int> > matrix){
  int vertices=matrix.size();
  vector<bool> visited(vertices, false);
  int count=0;
  for(int i=0; i<vertices; i++){
    if(visited[i]==false){ 
      count++;  // the number of time we call the DFSPrint=number of connected components
      DFSPrint(matrix, i, visited); // call the recursion  /////BFSPrint(matrix, i, visited);
    }
  }
  cout<<"Number of Connected Components is "<<count<<endl;
}
