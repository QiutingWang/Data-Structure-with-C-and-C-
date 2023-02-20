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
