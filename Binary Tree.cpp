#include <iostream>
using namespace std;
//////////////////////
/////Introduction/////
//BT: every node has maximum two children. As a consequence, vector is not needed when constructing the BT
// We can realize it by Linked list, with `BTNode* left` and `BTNode* right` variables to store two children address
template<typename T>
class BTNode{
  public: 
    T data;
    BTNode* left;
    BTNode* right;
    // create the constructor
    BTNode(T data){
      this->data=data;
      // initialization
      left=NULL;
      right=NULL;
    }
    // recursive destructor:call the delete, delete the left child, delete the right child, then delete yourself
    ~BTNode(){
      delete left;
      delete right;
    }
};

int main(){
  // create nodes
  BTNode<int>* root=new BTNode<int>(1);
  BTNode<int>* n1=new BTNode<int>(2);
  BTNode<int>* n2=new BTNode<int>(3);
  // make connection
  root->left=n1;
  root->right=n2;
  // call the functions
  printTree(root);
  
  delete root;
  return 0;
}


//////////////////////////////
/////Print Tree Recursive/////
// Procedure: print the root, print the left sub-tree, print the right sub-tree recursively
void printTree(BTNode<int>* root){
  if(root==NULL){ //base case for binary tree
    return;
  }
  cout<<root->data<<": ";
  if(root->left!=NULL){
    cout<<"L"<<root->left->data;
  }
  if(root->right!=NULL){
    cout<<"R"<<root->right->data;
  }
  cout<<endl;

  printTree(root->left);
  printTree(root->right);
}
// return
// 1: L2R3
// 2: 
// 3:


//////////////////////////////
/////Take Input Recursive/////
// // Procedure: construct the root, construct the left sub-tree, construct the right sub-tree recursively
BTNode<int>* takeInput(){
  int rootData;
  cout<<"Enter Data: "<<endl;
  cin>>rootData;

  if(rootData==-1){ //for empty tree
    return NULL;
  }
  // create nodes
  BTNode<int>* root=new BTNode<int>(rootData);
  BTNode<int>* leftChild=takeInput(); //call takeInput function recursively for left tree
  BTNode<int>* rightChild=takeInput();
  // make connection
  root->left=leftChild;
  root->right=rightChild;
  return root;
}

int main(){
  BTNode<int>* root=takeInput();
  printTree(root);
  delete root;
  return 0;
}
// return
// Enter Data: 
// 1
// Enter Data: 
// 2
// Enter Data: 
// -1
// Enter Data: 
// -1
// Enter Data: 
// 3
// Enter Data: 
// -1
// Enter Data: 
// -1
// 1: L2R3
// 2: 
// 3:


///////////////////////////////
/////Take Input Level Wise/////
// use queue, create node, push inside queue, connect the node with its parent, then pop it from queue
#include <queue>
BTNode<int>* takeInputLevelWise(){
  // root data
  int rootData;
  cout<<"Enter Root Data: "<<endl;
  cin>>rootData;
  // create and push
  BTNode<int>* root=new BTNode<int>(rootData);
  queue<BTNode<int>*> q;
  q.push(root);
  // check the condition whether the q is empty
  while(!q.empty()){
    BTNode<int>* f=q.front();
    q.pop(); // remove
    
    // left side
    cout<<"Enter left child of "<<f->data<<endl;
    int leftChildData;
    cin>>leftChildData;

    if(leftChildData!=-1){ //create,push, connect
      BTNode<int>* child=new BTNode<int>(leftChildData);
      q.push(child);
      f->left=child;
    }
    // right side
    cout<<"Enter right child of "<<f->data<<endl;
    int rightChildData;
    cin>>rightChildData;

    if(rightChildData!=-1){ //create,push, connect
      BTNode<int>* child=new BTNode<int>(rightChildData);
      q.push(child);
      f->right=child;
    }
  }
  return root;
}

int main(){
  BTNode<int>* root=takeInputLevelWise();
  printTree(root);
  delete root;
  return 0;
}
// return
// Enter Root Data: 
// 1
// Enter left child of 1
// 2
// Enter right child of 1
// 3
// Enter left child of 2
// 4
// Enter right child of 2
// 5
// Enter left child of 3
// 6
// Enter right child of 3
// 7
// Enter left child of 4
// -1
// Enter right child of 4
// -1
// Enter left child of 5
// -1
// Enter right child of 5
// -1
// Enter left child of 6
// -1
// Enter right child of 6
// -1
// Enter left child of 7
// -1
// Enter right child of 7
// -1
// 1: L2R3
// 2: L4R5
// 4: 
// 5: 
// 3: L6R7
// 6: 
// 7: 

