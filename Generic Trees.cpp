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


//////////////////////////////
/////Take Input Recursive/////
TreeNode<int>* takeInput(){
  int rootData;
  cout<<"Enter data"<<endl;
  cin>>rootData;

  TreeNode<int>* root=new TreeNode<int>(rootData); //build the constructor
  //get the number of children
  int n;
  cout<<"Enter number of children of "<<rootData<<endl;
  cin>>n;
  // call the recursion, the leaf nodes are acting as base case
  for(int i=1;i<=n;i++){ //call the recursion as many as the number of children
    TreeNode<int>* child=takeInput(); //the takeInput function will return root pointer to the main, store the address of children
    root->children.push_back(child); //pass the address, make connection, store the address of children to root
  }
  return root;
}

int main(){
  TreeNode<int>* root=takeInput();
  printTree(root);
  return 0;
}
// return
// Enter data
// 1
// Enter number of children of 1
// 3
// Enter data
// 2
// Enter number of children of 2
// 2
// Enter data
// 5
// Enter number of children of 5
// 0
// Enter data
// 6
// Enter number of children of 6
// 0
// Enter data
// 3
// Enter number of children of 3
// 1
// Enter data
// 7
// Enter number of children of 7
// 0
// Enter data
// 4
// Enter number of children of 4
// 1
// Enter data
// 8
// Enter number of children of 8
// 0
// 1: 2 ,3 ,4 ,
// 2: 5 ,6 ,
// 5: 
// 6: 
// 3: 7 ,
// 7: 
// 4: 8 ,
// 8: 


///////////////////////////////
/////Take Input Level Wise/////
// with a Queue DS here, for constructing the tree, `create` the node->`push` the node whose value from queue->`connect` the node->remove the original element in queue
// iterative, but not recursive
#include <queue>

TreeNode<int>* takeInputLevelWise(){
  int rootData;
  cout<<"Enter root data"<<endl;
  cin>>rootData;

  // create node
  TreeNode<int>* root=new TreeNode<int>(rootData);
  // create the queue, which stores the complete nodes
  queue<TreeNode<int>*> q;
  q.push(root); //push inside queue
  while(!q.empty()){
    TreeNode<int>* f=q.front(); //store the front element in queue in f 
    q.pop(); //remove this element from queue

    // check how many children of its parent
    cout<<"Enter # of children of "<<f->data<<endl;
    int n;
    cin>>n; //type the # of children

    // use loop to take input of elements in the same level
    for(int i=1; i<=n;i++){
      int childData;
      cout<<"Enter "<<i<<" th child of "<<f->data<<endl;
      cin>>childData;

      // create the node
      TreeNode<int>* child=new TreeNode<int>(childData);
      // push
      q.push(child);
      // make the connection with its parent
      f->children.push_back(child);
    }
  }
  return root;
}

int main(){
  TreeNode<int>* root=takeInputLevelWise();
  printTree(root);
  return 0;
}
// return
// Enter root data
// 1
// Enter # of children of 1
// 3
// Enter 1 th child of 1
// 2
// Enter 2 th child of 1
// 3
// Enter 3 th child of 1
// 4
// Enter # of children of 2
// 2
// Enter 1 th child of 2
// 5
// Enter 2 th child of 2
// 6
// Enter # of children of 3
// 1
// Enter 1 th child of 3
// 7
// Enter # of children of 4
// 1
// Enter 1 th child of 4
// 8
// Enter # of children of 5
// 0
// Enter # of children of 6
// 0
// Enter # of children of 7
// 0
// Enter # of children of 8
// 0
// 1: 2 ,3 ,4 ,
// 2: 5 ,6 ,
// 5: 
// 6: 
// 3: 7 ,
// 7: 
// 4: 8 ,
// 8: 


///////////////////////////
/////Level Order Print/////
// create and connect the node process are not needed, push is the only need
void printTreeLevelWise(TreeNode<int>* root){
     queue<TreeNode<int>*> q;
     q.push(root);
     while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();

        cout<<f->data<<": ";
        for(int i=0;i<f->children.size();i++){
           cout<<f->children[i]->data<<" ,";
         }
        cout<<endl;

        for(int i=0;i<f->children.size();i++){
            q.push(f->children[i]);
        }
     }
}

int main(){
  TreeNode<int>* root=takeInputLevelWise();
  printTreeLevelWise(root);
  return 0;
}
// return
// Enter root data
// 1
// Enter # of children of 1
// 3
// Enter 1 th child of 1
// 2
// Enter 2 th child of 1
// 3
// Enter 3 th child of 1
// 4
// Enter # of children of 2
// 2
// Enter 1 th child of 2
// 5
// Enter 2 th child of 2
// 6
// Enter # of children of 3
// 1
// Enter 1 th child of 3
// 7
// Enter # of children of 4
// 1
// Enter 1 th child of 4
// 8
// Enter # of children of 5
// 0
// Enter # of children of 6
// 0
// Enter # of children of 7
// 0
// Enter # of children of 8
// 0
// 1: 2 ,3 ,4 ,
// 2: 5 ,6 ,
// 3: 7 ,
// 4: 8 ,
// 5: 
// 6: 
// 7: 
// 8: 


//////////////////////
/////Count Nodes/////
// call the recursion on the trees which start from the child of root, then return the nodes numbers to the root, then sum up the sub-trees' nodes' amount+1(root node)
// only the extra codes are shown below
int countNodes(TreeNode<int>* root){ //create a pointer node
  if(root==NULL){ //special case
    return 0;
  }
  int ans=1; //root number
  for(int i=0;i<root->children.size();i++){ //call the recursion
    ans+=countNodes(root->children[i]);
  } 
  return ans;
}

int main(){
  TreeNode<int>* root=takeInputLevelWise();
  cout<<countNodes(root)<<endl;
  return 0;
}
// return(the type and input are the same as ahead)
// 8


/////////////////////////
/////Hight of a Tree/////
// ie: find the number of level
// find the height of all the children, get the maximum  +1(root)
int height(TreeNode<int>* root){
  if(root==NULL){ //special case
    return 0;
  }

  int maxHeight=0; //initialization
  for(int i=0;i<root->children.size();i++){ //call the recursion with loop
    /*int childHeight=height(root->children[i]);

    if(childHeight>maxHeight){
      maxHeight=childHeight; //update the maxHeight
    }*/
    // optimization, use max inbuilt function
    maxHeight=max(maxHeight,height(root->children[i]));
  }
  return maxHeight+1;
}

int main(){
  TreeNode<int>* root=takeInputLevelWise();
  cout<<height(root)<<endl;
  return 0;
}
// return:
// Enter root data
// 1
// Enter # of children of 1
// 3
// Enter 1 th child of 1
// 2
// Enter 2 th child of 1
// 3
// Enter 3 th child of 1
// 4
// Enter # of children of 2
// 0
// Enter # of children of 3
// 1
// Enter 1 th child of 3
// 5
// Enter # of children of 4
// 0
// Enter # of children of 5
// 1
// Enter 1 th child of 5
// 6
// Enter # of children of 6
// 0
// 4


////////////////////////////////////
/////Print all Nodes at Level K/////
// level 1,2,... counts from the child nodes' nearest distance from the root node to furthest from the root node
void printNodeAtLevelK(TreeNode<int>* root, int K){
  if(root==NULL){ //special case
    return;
  }
  if(K==0){
    cout<<root->data<<endl; //only print root and return, no children nodes
    return;
  }
  for(int i=0;i<root->children.size();i++){ //call the recursion
    printNodeAtLevelK(root->children[i], K-1);
  }
}

int main(){
  TreeNode<int>* root=takeInputLevelWise();
  printNodeAtLevelK(root,2);
  return 0;
}
//return
// Enter root data
// 1
// Enter # of children of 1
// 3
// Enter 1 th child of 1
// 2
// Enter 2 th child of 1
// 3
// Enter 3 th child of 1
// 4
// Enter # of children of 2
// 2
// Enter 1 th child of 2
// 5
// Enter 2 th child of 2
// 6
// Enter # of children of 3
// 1
// Enter 1 th child of 3
// 7
// Enter # of children of 4
// 0
// Enter # of children of 5
// 0
// Enter # of children of 6
// 0
// Enter # of children of 7
// 0
// 5
// 6
// 7 


/////////////////////////
/////Count Leaf Node/////
// call the recursion count the leaf nodes in the sub-trees, then add up together
int countLeafNodes(TreeNode<int>* root){
  if(root==NULL){ //special case
    return 0;
  }
  if(root->children.size()==0){ //with no children,only the root node
    return 1;
  }
  int ans=0; //initialization
  for(int i=0;i<root->children.size();i++){ //call the recursion
    ans+=countLeafNodes(root->children[i]); //update the answer
  }
  return ans;
}

int main(){
  TreeNode<int>* root=takeInputLevelWise();
  printTreeLevelWise(root);
  countLeafNodes(root);
  cout<<"Total Nodes "<<countNodes(root)<<endl;
  cout<<"Height "<<height(root)<<endl;
  cout<<"Nodes at Level 2"<<endl;
  printNodeAtLevelK(root,2);
  cout<<"Numbers of leaf nodes "<<countLeafNodes(root)<<endl;
  return 0;
}
// return
// Enter root data
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

// Enter # of children of 1
// Enter 1 th child of 1
// Enter 2 th child of 1
// Enter 3 th child of 1
// Enter # of children of 2
// Enter 1 th child of 2
// Enter 2 th child of 2
// Enter # of children of 3
// Enter 1 th child of 3
// Enter 2 th child of 3
// Enter # of children of 4
// Enter # of children of 5
// Enter # of children of 6
// Enter # of children of 7
// Enter # of children of 8
// Enter 1 th child of 8
// Enter # of children of 9
// 1: 2 ,3 ,4 ,
// 2: 5 ,6 ,
// 3: 7 ,8 ,
// 4: 
// 5: 
// 6: 
// 7: 
// 8: 9 ,
// 9: 
// Total Nodes 9
// Height 4
// Nodes at Level 2
// 5
// 6
// 7
// 8
// Numbers of leaf nodes 5
