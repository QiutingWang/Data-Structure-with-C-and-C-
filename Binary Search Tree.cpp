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






