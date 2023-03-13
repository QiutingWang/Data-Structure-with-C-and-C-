#include <iostream>
using namespace std;
///////////////////////////
/////Tree Introduction/////
// reference: https://www.geeksforgeeks.org/generic-treesn-array-trees/   https://www.programiz.com/dsa/trees
// generic tree also called N-ary trees
// Definition: 
  // a collection of nodes where each node consists of records and a list of references to its children
  // parent:child relationship. If a node has no children is called `leaf node` or `external node`.
  // `siblings`: their parent should be same.
  // `Ancestor` and `Descendent`
  // `Edge`: the link between any two nodes
  // height of a node: the longest path from the node to a leaf node
  // Depth of a node: number of edges from the root to the node
  // Degree of a node: total number of branches of that node.
  // reference duplicates is not allowed
  // many children  @ every node,which is the biggest difference between tree and linked list that only stores next node's address.
  // the very `first node’s address` will be stored in a individual pointer called `root node`.
// Example in reality: file system, organization structure


////////////////////////
/////Vectors Review/////
// Advantages of using vector:
  // inbuilt dynamic array 
  // do not need to give a size
  // we can insert as much elements as we want, since as soon as the vector is full, the size automatically doubles
// The related content created previously: https://github.com/QiutingWang/Data-Structure-with-Cpp/blob/main/Vectors.cpp
#include <vector>

int main(){
  vector<int> *vp=new vector<int>(); //create vector dynamically, we have to delete ourselves
  vector<int> v; //create vector statically, it will be deleted automatically
  vector<int> v2(10,-2); //create a vector given size and initialized value
  vector<int> v3(101); 
  //insert elements
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  //change the value
  v[1]=100; //if we use it to insert element, the size of vector will not increase with a non-belonging element
  // wrong method to add elements
  v[4]=2007;
  v[5]=1999;

  v.push_back(22);
  v.push_back(29);
  cout<<v[0]<<endl;
  cout<<v[1]<<endl;
  cout<<v[2]<<endl;
  cout<<v[3]<<endl;
  cout<<v[4]<<endl;
  cout<<v[5]<<endl;
  cout<<v[6]<<endl;
  //check the elements in corresponding position
  cout<<v.at(4)<<endl; //valid index
  cout<<v.at(6)<<endl; //invalid index
   
  v.pop_back();//remove the last element
  //another way, use for loop to print
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<endl;
  }

  // use for loop to insert elements 
  for(int i=0;i<100;i++){
    cout<<"Capacity: "<<v.capacity()<<endl; //increasing doubly as soon as the size=capacity
    cout<<"Size: "<<v.size()<<endl; //the size will give us 1 to 100 increasing linearly.
    v.push_back(i+1);
  }
  //sort vector
  sort(v2.begin(),v2.end());
  // print out
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<endl;
  } //as results, it will print from 1 to 100.

  return 0;
}
// return:
// 10
// 100
// 30
// 22
// 29
// 0
// 0

// 29
// 'std::out_of_range'

// 10
// 100
// 30
// 22

// Capacity: 0
// Size: 0
// Capacity: 1
// Size: 1
// Capacity: 2
// Size: 2
// Capacity: 4
// Size: 3
// Capacity: 4
// Size: 4
// Capacity: 8
// Size: 5
// Capacity: 8
// Size: 6
// Capacity: 8
// Size: 7
// Capacity: 8
// Size: 8
// Capacity: 16
// Size: 9.....


/////////////////////////
/////Tree Node Class/////
// Problems of using linked list and array to create TreeNode:
  // linked list: access issue
  // array: size issue, we do not know the numbers of children in advance, hence, we can not properly define an array.
// We use vector DS to store tree node value and children address with root pointer
// make connection: put the children address to parent's node
template<typename T>
class TreeNode{
  public:
    T data;
    vector<TreeNode<T>*> children; //constructor create node dynamically
    TreeNode(T data){
      this->data=data;
    }
};

int main(){
  // create node
  TreeNode<int>* root=new TreeNode<int>(1);
  TreeNode<int>* n1=new TreeNode<int>(2);
  TreeNode<int>* n2=new TreeNode<int>(3);
  // make connection
  root->children.push_back(n1);
  root->children.push_back(n2);

  return 0;
}


//////////////////////////////////////
/////Print the Tree use Recursion/////
// print the root first
// call the recursion to print nodes for each children in the same level(ie:have the same parent) whose address are stored in the same position
template<typename T>
class TreeNode{
  public:
    T data;
    vector<TreeNode<T>*> children; //constructor create node dynamically
    TreeNode(T data){
      this->data=data;
    }
};

void printTree(TreeNode<int>* root){
  // check whether the tree/root is null
  if(root==NULL){
    return ;
  }
  cout<<root->data<<": "; //separate the children and parent
  /////the optimization part/////
  for(int i=0;i<root->children.size();i++){ 
    cout<<root->children[i]->data<<" ,"; //separate for multiple children sharing the same parent
  }
  ////////////////////////////////
  cout<<endl;
  
  //recursive case:
  for(int i=0;i<root->children.size();i++){ //traverse the children address storage in parent node
    printTree(root->children[i]);
  } //the leaf nodes are acted as base case automatically, because of its children size=0
}

int main(){
  // create node
  TreeNode<int>* root=new TreeNode<int>(1);
  TreeNode<int>* n1=new TreeNode<int>(2);
  TreeNode<int>* n2=new TreeNode<int>(3);
  // make connection
  root->children.push_back(n1);
  root->children.push_back(n2);

  printTree(root); //call the function

  return 0;
}
// return
// 1
// 2
// 3

// However, it is not a good way to print tree, owing to the output indicates that the tree structure can be 1-2,3  or 1-2-3
// optimization:
  // 1:2,3  
  // 2:  
  // 3:  

// return:
// 1: 2 ,3 ,
// 2: 
// 3:

