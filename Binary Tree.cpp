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


///////////////////////////////
/////Level Order Traversal/////
///Procedure:
// use queue, check the root, left side, right side exist or not
// if exists push the node inside the queue, pop the element, print the value
  // after finish pushing the elements in the same level, we push NULL in the queue
  // when print the elements as a binary tree, as soon as we meet a NULL, we start from a new line
  // In conclusion, NULL is used to differentiate between levels.
// when the queue is empty, stop execution

// LeetCode No.102 https://leetcode.com/problems/binary-tree-level-order-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > v; //create the vector
        if(root==NULL){
            return v; //now v is empty
        }
        vector<int> temp; //to store the result of current level
        // create a queue, push root level elements
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* f=q.front();  //create a pointer variable
            q.pop(); //remove the element

            if(f==NULL){
                //cout<<endl; write in a new line
                v.push_back(temp);
                temp.clear(); //update to make temp empty
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{ //print out the value
                temp.push_back(f->val); //left side
                if(f->left!=NULL){
                    q.push(f->left);
                }
                if(f->right!=NULL){  //right side
                    q.push(f->right);
                }
            }
        }
        return v;
    }
};
// T=O(N); S=O(N)


/////////////////////
/////Count Nodes/////
// Procedure: 
// answer=# of nodes present in left + # of nodes present in right + root(1)
// call the count recursion with left sub-trees and right sub-trees
// basic case: if the root is NULL;

// LeetCode No.222 https://leetcode.com/problems/count-complete-tree-nodes/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        // base case
        if(root==NULL){
            return 0;
        }
        // recursive case
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};
// T=O(N); S=O(N) 


///////////////////////////
/////InOrder Traversal/////
// Rule: for every node use recursion, visit left side sub-tree->current root data->right side sub-tree (LDR)

// LeetCode No.94 https://leetcode.com/problems/binary-tree-inorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void InOrder(TreeNode* root, vector<int> &ans){ //pass by reference, change are permanent
        if(root==NULL) return ;

        InOrder(root->left, ans);
        ans.push_back(root->val);
        InOrder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // create a vector
        vector<int> ans;
        InOrder(root, ans);
        return ans;
    }
};
// T=O(N); S=O(N)


////////////////////////////
/////PreOrder Traversal/////
// Rule: for every node, D->L->R

// LeetCode No.144 https://leetcode.com/problems/binary-tree-preorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void PreOrder(TreeNode* root, vector<int> &ans){
        if(root==NULL) return ;

        ans.push_back(root->val);
        PreOrder(root->left, ans);
        PreOrder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        PreOrder(root, ans);
        return ans;
    }
};
// T=O(N); S=O(N);
