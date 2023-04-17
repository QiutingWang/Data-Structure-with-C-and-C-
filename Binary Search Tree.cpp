#include <iostream>
using namespace std;
//////////////////////
/////Introduction/////
// reference: https://www.softwaretestinghelp.com/binary-search-tree-in-cpp/
// Binary: each node has <=2 children
// Search: used to search for the presence T=O(log(n)) time complexity
// Features in BST:
  // all nodes of left subtree < root node
  // all nodes of right subtree > root node
    // in this case, we selected `root node value` as the key node in binary search algorithm


///////////////////////
/////Search in BST/////
// LeetCode No.700 https://leetcode.com/problems/search-in-a-binary-search-tree/
/////Method1: Recursion
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
    TreeNode* searchBST(TreeNode* root, int val) {
        // base case
        if(root==NULL) return NULL; //the value not found
        if(root->val==val) return root;
        // recursion case
        if(val>root->val){
            return searchBST(root->right, val);
        }else{
            return searchBST(root->left, val);
        }
        return NULL;
    }
};


/////Method2: Iteration
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL){
            if(val==root->val) return root;
            else if(val > root->val){
                root=root->right;
            }else{
                root=root->left;
            }
        }
        return NULL;
    }
};
// T=O(N)


///Find Min
// find the left most node value
///Find Max 
// find the right most node value

//////////////////////////
/////Range Sum in BST/////
// the range defined as [low bound, high bound]
// LeetCode No.938 https://leetcode.com/problems/range-sum-of-bst/
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        
        int sum=0; //initialization
        // for the current value
        if(root-> val >= low && root->val <=high){
            sum += root->val; //update sum variable
        }
        // move left and right
        if(root->val > high){
            sum += rangeSumBST(root->left, low, high); //the value is too large lying out of the range we want, value reduction is needed by moving left
        }else if(root->val < low){
            sum += rangeSumBST(root->right, low, high); //the value is too small lying out of the range we want, value enlarge is needed by moving right
        }else{
            sum += rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high); //if lies in the required range, go for both directions to make addition
        }
        return sum;
    }
};
// T=O(N)


//////////////////////
/////Validate BST/////
//Task: Check the Binary Tree is BST or not.
// Method1: InOrder traversal(LDR) of Binary tree is sorted.
  // store the InOrder traversal in an array
  // then check whether it is sorted or not
    // T=O(N), S=O(N)
  // Optimization: we do not have to create this array. 
    // Two pointers are needed, called previous and current. 
    // If previous->val < current->val, then it is a BST.
      // T=O(N), S=O(1)

// Method2: use the property of BST-- the constrains of each node
  // check each node's range is proper or not

// LeetCode No.98 https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
public:
    bool helper(TreeNode* root, long long minVal=-10000000000, long long maxVal=10000000000){
        // base case
        if(root==NULL) return true;
        // recursive case
        bool left=helper(root->left, minVal, root->val);
        bool right=helper(root->right, root->val, maxVal);

        if(left && right && root->val>minVal && root->val<maxVal) return true;
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};


////////////////////////////////////
/////Sorted Array->balanced BST/////
// make the mid element as the root, call the recursion assign the left and right elements

// LeetCode No.108 https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
class Solution {
public:
    TreeNode* helper(vector<int>& array, int start, int end){
        // base case
        if(start>end){
            return NULL;
        }
        int mid=(start+end)/2; //find the mid index
        int rootData=array[mid];
        TreeNode* root=new TreeNode(rootData); //create the root node and pass the root data
        // call the recursion on left and right subtree and make the connection between left/right subtrees to root node
        root->left= helper(array, start, mid-1);
        root->right=helper(array, mid+1, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(nums, 0, n-1);
    }
};


//////////////////////////////////
/////BST Class Implementation/////
// Copy the code from binary tree node
template<typename T>
class BTNode{
  public: 
    T data;
    BTNode* left;
    BTNode* right;
    BTNode(T data){
      this->data=data;
      left=NULL;
      right=NULL;
    }
    ~BTNode(){
      delete left;
      delete right;
    }
};

class Pair{ //include the final head and final tail
    public:
      BTNode<int>* head;
      BTNode<int>* tail;
};

class BST{
    // copy from Binary Tree Document
    BTNode<int>* root; //create a root node based on Binary Tree node class
    
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

    bool hasData(BTNode<int>* node, int data){
        // base case
        if(node==NULL){
            return false;
        }
        if(node->data==data){
            return true;
        }
        // recursive case
        if(node->data > data){
            return hasData(node->left, data);
        }else{
            return hasData(node->right, data);
        }     
    }

/////Insert Procedure:(with recursion)
// root node create first
// create another node with value, comparing with root node value, deciding which side to put
// return the newly created node to root, make the connection with root node
    BTNode<int>* insert(BTNode<int>* node, int data){
        // base case
        if(node==NULL){ //initialize value is NULL, it will be updated later
            BTNode<int>* n=new BTNode<int>(data); //create the node and pass the value
            return n;
        }
        // recursive case
        if(data < node->data){
            node->left=insert(node->left, data); //insert the node in left sub-tree and make the connection 
        }else{
            node->right=insert(node->right, data); //insert the node in right sub-tree and make the connection 
        }
        return node;
    }

/////Delete Procedure:
// search or reach the target node is present or not
// if exists(3 cases):
  // 1. if the target node is leaf node, we delete it and return `NULL` to its parent node
  // 2. if the target node has children in left/right sub-tree, we delete it and return its sub-tree node(s) to its parent node
  // 🌟 3. if the target node has children both situated in left and right sub-trees, we delete the target node, combining its right and left sub-trees by finding the replacement of the target node.
    // replacement can be: (still cohere the binary search tree traits)
      // the maximum node value of left sub-tree;
      // OR the minimum node value of right sub-tree
  // con't: then call the recursion of the sub-tree which the replacement node originally located in, delete the original replacement node. 
    BTNode<int>* deleteData(BTNode<int>* node, int data){
        // base case
        if(node==NULL){
            return NULL;
        }
        // recursion case
        if(data > node->data){
            node->right=deleteData(node->right, data); //update the right sub-tree
        }else if(data < node->data){
            node->left=deleteData(node->left, data);
        }else{       // data == node->data, reach at the target node
            // base case, leaf node
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }else if(node->right==NULL){
                // second case
                // first store target node's sub-tree in temporary node
                // isolation the target node
                // delete the target node
                BTNode<int>* temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }else if(node->left==NULL){
                BTNode<int>* temp=node->right;
                node->right=NULL;
                delete node;
                return temp;
            }else{
                // 🌟third case
                BTNode<int>* minNode=node->right; //create the node
                while(minNode->left != NULL){
                    minNode=minNode->left; //move left most in right sub-tree and update it
                }
                int rightMin=minNode->data; //find out the data
                node->data=rightMin; //replace the node with right minimum value
                // call the recursion and make connection
                node->right=deleteData(node->right, rightMin);
            }
        }
        return node;
    }

    Pair convert2LL(BTNode<int>* root){
        if(root==NULL){
            Pair ans;
            ans.head=NULL;
            ans.tail=NULL;
            return ans;
        }
        if(root->left==NULL && root->right==NULL){ //case1
            Pair p; //create a pair
            p.head=root;
            p.tail=root;
            return p;
        }else if(root->left !=NULL && root->right==NULL){ //case2
            Pair leftLL=convert2LL(root->left);  //call the recursion, the subtree is converted into a linked list
            leftLL.tail->right=root; // make the connection 
            Pair ans; //create a pair
            ans.head=leftLL.head;
            ans.tail=root;  
            return ans;
        }else if(root->right !=NULL && root->left==NULL){ //case3
            Pair rightLL=convert2LL(root->right);  //call the recursion, the subtree is converted into a linked list
            root->right=rightLL.head; // make the connection 
            Pair ans; //create a pair
            ans.head=root;
            ans.tail=rightLL.tail;  
            return ans;
        }else{ //case4
            // call the recursions
            Pair leftLL=convert2LL(root->left);
            Pair rightLL=convert2LL(root->right);
            // make connections
            leftLL.tail->right=root;
            root->right=rightLL.head;
            Pair ans;
            ans.head=leftLL.head;
            ans.tail=rightLL.tail;
            return ans;
        }
    }

    public:
    // build the constructor
      BST(){
        root=NULL;
      }
      ~BST(){
        delete root;
      }
      void deleteData(int data){
        root=deleteData(root, data);
      }
      void insert(int data){
        root=insert(root, data);
      }
      bool hasData(int data){
        return hasData(root, data); //call the private function
      }
      void print(){
        printTree(root);
      }
      BTNode<int>* convert2LL(){
        Pair p=convert2LL(root);
        return p.head;
      }
};

int main(){
    BST b;
    b.insert(10);
    b.insert(8);
    b.insert(22);
    b.insert(4);
    b.insert(17);
    b.insert(5);
    b.insert(46);

    b.print();

    BTNode<int>* head=b.convert2LL();
    BTNode<int>* temp2=head;
    while(temp2!=NULL){
        cout<<temp2->data<<"→";
        temp2=temp2->right; //move ahead
    }

    /*int data;
    cin>>data;
    cout<<b.hasData(data)<<endl;

    b.deleteData(10);
    cout<<endl;
    b.print();

    b.deleteData(4);
    cout<<endl;
    b.print();

    b.deleteData(100); //data doesn't exist
    cout<<endl;
    b.print();
    
    cout<<"deleting 4"<<endl; //case2
    b.deleteData(4);
    cout<<endl;
    b.print();

    cout<<"deleting 46"<<endl; //case3
    b.deleteData(46);
    cout<<endl;
    b.print();*/

    return 0;
}
// return:
// 10: L8R22
// 8: L4
// 4: R5
// 5: 
// 22: L17R46
// 17: 
// 46:

// 17 //search the data we need to type in the target
// 1

// 17: L8R22
// 8: L4
// 4: R5
// 5: 
// 22: R46
// 46: 

// 17: L8R22
// 8: L5
// 5: 
// 22: R46
// 46: 

// 17: L8R22
// 8: L5
// 5: 
// 22: R46
// 46:
// deleting 4

// 17: L8R22
// 8: L5
// 5: 
// 22: R46
// 46: 
// deleting 46

// 17: L8R22
// 8: L5
// 5: 
// 22: 

// 10: L8R22
// 8: L4
// 4: R5
// 5: 
// 22: L17R46
// 17: 
// 46:

// 4→5→8→10→17→22→46



//////////////////////////////////////////////////
/////Convert BST to Sorted Singly Linked List/////
// we are not creating new node, instead we just change the pointers from left&right to next.

/// Procedures:
//Method1: less time complexity
  // first call the recursion with left sub-tree and right sub-tree separately, correspondingly, it returns 2 sorted linked lists, with 4 values: leftHead & leftTail, rightHead & rightTail
  // to make connection between these two sorted linked lists, we need to connect leftTail, root node, and  rightHead nodes.

//Method2: more time complexity owing to traversal to find the leftTail value
  //the same as previous method, except it only required to return 2 values: leftHead & rightHead
  // we need to traversal the left sorted linked list with pointer to find out leftTail value, then make the connection with root node.

/// Possible Cases:
// 1. both right and left sub-trees are NULL
// 2. right sub-tree is NULL, left sub-tree exists(left LL+node)
// 3. left sub-tree is NULL, right sub-tree exists(node+right LL)
// 4. both right and left sub-tree exist(left LL+ root +right LL)


// Codes are in above class implementation part.


///////////////////////////////
/////Types of Balanced BST/////
// reference: Self-Balancing Binary Search Trees https://www.geeksforgeeks.org/self-balancing-binary-search-trees/

/// Definition and features: 
  // automatically keep the height as small as possible
  // all operations ie:insert, delete, search, T=O(logN), which is nearly H

/// Types:
  // AVL Tree: for every node, |left sub-tree Height-right sub-tree Height|<=1
  // Red Black Tree: 
    // every node is colored with either red or black. 
    // The root and leaf nodes are always marked as black.
    // the children of each red node are black
    // all leaves have the same black depth
    // every simple path from the root to descendant leaf node have the same number of black nodes.
  // Splay Tree:
    // bring the most recently accessed or inserted element to the root, by performing a sequence of tree rotations
    // zip or zap rotation

/// Self-Balancing Method:
// left rotation or right rotation
// reference: Self-Balancing Binary Search Trees 101  https://towardsdatascience.com/self-balancing-binary-search-trees-101-fc4f51199e1d
