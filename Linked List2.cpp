#include <iostream>
using namespace std;
///////////////////////////////
/////Length with Recursion/////
class node{
  public:
    int data;
    node *next; 
    node(int data){
      this->data=data; 
      next=NULL;
    }
};

void print(node *head){  
  node *temp=head;
  while(temp!=NULL){
    cout<<temp->data<<"-> "; 
    temp=temp->next; 
  }
  cout<<"NULL"<<endl;
}

node* takeInput(){ 
  int data;
  cin>>data;
  node *head=NULL; 
  node *tail=NULL; 
  while(data!=-1){ 
    node *n=new node(data); 
    if(head==NULL){
      head=n; 
      tail=n;
    }else{
      tail->next=n; 
      tail=n; 
    }
    cin>>data;
  }
  return head; 
}

int length(node *head){
  if(head==NULL){
    return 0;
  }
  int smallAns=length(head->next);
  return 1+smallAns;
}

int main(){
  node *head=takeInput();
  cout<<length(head)<<endl; //call the function
  print(head);
  return 0;
}
// return:
// 10 98 235 66 84 34 -1
// 6
// 10-> 98-> 235-> 66-> 84-> 34-> NULL

// T=O(N)
// S=O(N), consider the nodes called in the call stack


///////////////////////////////
/////Search in Linked List/////
class node{
  public:
    int data;
    node *next; 
    node(int data){
      this->data=data; 
      next=NULL;
    }
};

node* takeInput(){ 
  int data;
  cin>>data;
  node *head=NULL; 
  node *tail=NULL; 
  while(data!=-1){ 
    node *n=new node(data); 
    if(head==NULL){
      head=n; 
      tail=n;
    }else{
      tail->next=n; 
      tail=n; 
    }
    cin>>data;
  }
  return head; 
}

bool isPresent(node *head,int data){
  node *current=head; //initalization
  while(current!=NULL){
    if(current->data==data){ //comparison
      return true;
    }
    current=current->next; //move ahead
  }
  return false;
}

int main(){
  node *head=takeInput();
  int data;
  cin>>data;
  if(isPresent(head,data)){ //call the function
    cout<<"found"<<endl;
  }else{
    cout<<"not found"<<endl;
  }
  return 0;
}
// return:
// 12 8 76 39 10 -1
// 39
// found

// T=O(N), S=O(1)


//////////////////////////////////////////
/////Search in Linked List--Recursive/////
bool findElement(node *head, int data){
  // base case: if the linked list is not present
  if(head==NULL){
    return false;
  }
  if(head->data==data){
    return true;
  }
  // recursive case
  return findElement(head->next,data); 
}

int main(){
  node *head=takeInput();
  int data;
  cin>>data;
  if(findElement(head,data)){ //call the function
    cout<<"found"<<endl;
  }else{
    cout<<"not found"<<endl;
  }
  return 0;
}
// T=O(N), S=O(N)
// return:
// 12 8 76 39 10 -1
// 76
// found


///////////////////////////////
/////Find Mid Node of List/////
// if it is a linked list with even numbers of nodes, return the second mid node.
///Process:
// 1. Find the length of linked list
// 2. calculate length/2
// 3. iterate totally length/2 times
// We travers the linked list two times for step 1 and 3.

// A better way:slow and fast pointer approach双指针
///Process:
// put the slow pointer at head, put the fast pointer next of head initially.
// slow pointer takes jump of one unit each time, fast pointer takes jump of two units each time
// when faster pointer reaches at null(the end of the linked list) stop here, the slow pointer reaches at mid. (for odd numbers of nodes' linked lists)
  // if the linked list has even number of nodes, it requires to return the second node, our return should adjust as next of slow
// only one traverse required.
// leetcode No.876 https://leetcode.com/problems/middle-of-the-linked-list/
class Solution {
public:
    ListNode* middleNode(ListNode* head) { //put the pointers
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next; //one jump
            fast=fast->next->next; //two jumps
        }
        if(fast!=NULL){ //even number of nodes
            return slow->next;
        }
        return slow; //odd number of nodes
    }
};


///////////////////////////////
/////Reverse a Linked List/////
///Process:
// set 3 pointers in adjacent orderly: previous, current, n(next of current). Namely,NodeA<-NodeB(Previous)  NodeC(Current)->NodeD(n)->NodeE->...->NULL. Treat current pointer's position as head initially.
// Save n node
// break the link between current and node n
// create the link between previous and current
// move the previous pointer's position to original current pointer's position
// move the current's position to original n pointer's position
// iterate the process above use a loop until the current pointer first reaches at NULL.
// Finally, the head becomes at previous pointer's position.

/// LeetCode.206 https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      //initialization
        ListNode *current=head;
        ListNode *previous=NULL;
        
        while(current!=NULL){
            ListNode *n=current->next; //save the next node n
            current->next=previous; //break the node, create the link between previous and current
            //move ahead
            previous=current; 
            current=n; 
        }
        return previous; //the head at final
    }
};
// T=O(N), S=O(1)


/////////////////////////////////////////////////
/////Remove kth Node from End of Linked List/////
/// Process:
// find the length of the LL: n
// find the kth node from the end: (i=n-k+1)th node from the front.
// do i-1 iteration jumps reach at the kth node
// Traverse the linked list twice. But only once traversal is allowed.

///Another Way, Process:
// 1.Find out the desired kth node
  // take 2 pointers(One and Two) initially both locate at head of the linked list.
  // make pointer Two takes k jumps. Hence, the distance between One & Two=k nodes
  // move One and Two ahead simultaneously
  // once pointer Two moves at NULL, One pointer reach at kth node.
// 2. Remove kth node
  // when One comes to (k-1)th node and Two comes to the last node of the linked list, create the link between (k-1)th and (k+1)th nodes.
  // kth node is removed automatically

/// LeetCode.19  https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode *One=head;
        ListNode *Two=head;

        while(k--!=NULL){ //pointer Two first jumps k times 
            Two=Two->next;
        }
        // check for the special case first
        if(Two==NULL){//ListNode.length=k -->delete the first node
            return One->next;  //pointer one jumps 1 unit
        }
        //move ahead
        while(Two->next!=NULL){
            One=One->next;
            Two=Two->next;
        }
        //delete kth node from the end by creating the new link
        One->next=One->next->next; //still a memory leak
        return head;
    }
};


//////////////////////////////////////
/////Merge Two Sorted Linked List/////
/// Process: Without creating any new nodes, we only change the connection.
// comparing the first node of the linked list1 and the first node of the linked list2-->find the final head
// compare the larger first node of one linked list with the second node of another linked list.
// make the new connection with head and another linked list's first node.
// move ahead...
// if one linked list first reach at NULL, connect with the last node of this linked list with remaining part of another linked list.

///LeetCode.21 https://leetcode.com/problems/merge-two-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        ListNode *finalHead=NULL; //initialize, find out the head of merged linked list
        //comparison
        if(l1->val<l2->val){
            finalHead=l1;
            l1=l1->next; //move ahead
        }else{
            finalHead=l2;
            l2=l2->next; //move ahead
        }
        // create a new pointer to form the merged linked list.
        ListNode *finalTail=finalHead;//initialize
        while(l1 && l2){
            if(l1->val<l2->val){
                finalTail->next=l1; //inserting a tail
                l1=l1->next; //move ahead
            }else{
                finalTail->next=l2; 
                l2=l2->next;
            }
            finalTail=finalTail->next; //update the pointer
        }
        //if l2==NULL
        if(l1){
            finalTail->next=l1;
        }else{ //if l1==NULL
            finalTail->next=l2;
        }
        return finalHead;
    }
};
// T=O(m+n), S=O(1)


/////////////////////////////////////////////////
/////Merge Two Sorted Linked List(recursion)/////
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        // base case
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        // Recursive case
        ListNode *newHead=NULL; //initialize
        if(l1->val<l2->val){
            newHead=l1;
            newHead->next=mergeTwoLists(l1->next, l2);
        }else{
            newHead=l2;
            newHead->next=mergeTwoLists(l2->next, l1);
        }
        return newHead;
    }   
};


//////////////////////////////////
////Merge Sort on Linked List/////
/// Process:
// find the mid using slow and fast pointers approach, break the linked list into two parts
// apply merge sort into two sub-linked lists by recursion
// use the functions that merge two sorted linked list we have mentioned above
/// LeetCode 148  https://leetcode.com/problems/sort-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
public:
  //  just copy from above
   ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a==NULL) return b;
        if(b==NULL) return a;
        
        ListNode* newHead = NULL;
        if(a->val < b->val){
            newHead = a;
            newHead ->next = mergeTwoLists(a->next, b);
        }else{
            newHead = b;
            newHead->next = mergeTwoLists(a,b->next);
        }
        return newHead;
    }

    ListNode* sortList(ListNode* head) {
        // base case: 0 node and 1 node
        if(head==NULL || head->next==NULL) return head;
        // break list into two halves, find the mid first
        // initialize slow and fast pointers
        ListNode *slow=head;
        ListNode *fast=head->next;
        // move ahead
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // store the address, n is the first node after the breaking point
        ListNode *n=slow->next;
        // break into two sub-linked lists
        slow->next=NULL;
        // call the sort function into both of parts and store them
        ListNode *a=sortList(head);
        ListNode *b=sortList(n);

        // merge the two sorted halves, call the function
        head=mergeTwoLists(a,b); 
        return head;
    }
};
// T=O(nlogn)


///////////////////////////////////
/////Variations of Linked list/////
///// Doubly linked list
// reference:https://www.geeksforgeeks.org/introduction-and-insertion-in-a-doubly-linked-list/
// the drawback of single linked list: can only move in the forward direction, we can only store the address of next node, not store the address of previous node
// The features of doubly linked list: we can move backward and forward. We can store the previous address as well.
// the backwards of doubly linked list: it requires more memory

/////Circular Single Linked List
// reference: https://www.geeksforgeeks.org/circular-linked-list/?ref=lbp
// the link direction is only forward, and the last node has connection with the first node, (last node stores the address of first node) without any NULL values.
// advantage: 
  // do not need to maintain the head pointer any more.
  // The circular singly linked list has no beginning or end.
// We can count the length of circular linked list by a temp pointer moving ahead until next-of-temp reaches at the beginning position.
// insert problem: T=O(N), first find out the last node, make the new connection between the inserted node and last node, the original link is automatically broken.

/////Circular Doubly Linked List
// any two consecutive elements are linked(includes the last and first nodes)

