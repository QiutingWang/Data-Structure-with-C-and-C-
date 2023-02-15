#include <stdio.h>
#include <stdlib.h>
using namespace std;
/////////////////////////////
/////What is Linked List/////
// Data Structure: a way to store data
// Multiple data structure: linked list, stacks, queues, graph, trees, hashmap, priority queue...
// reference: https://www.geeksforgeeks.org/what-is-linked-list/?ref=lbp
// linear data structure, elements are linked using pointers, including connected nodes, which store this node's value and address, and the address of the `next` node
  // the first node called head, the last node called tail
  // one unit storage requirement is 8 bits(self-value+next node's address)
// Dynamic array(continuously stored, fixed size, random allocation of memory), ease of insertion or deletion, we can add as much elements as we want
// types: Simple, Doubly, Circular, Doubly Circular, Header LL.
class node{
  public:
    int data;
    node *next; //a pointer, related to address
    //build the constructor
    node(int data){
      this->data=data;
      next=NULL;
    }
};

int main(){
  // create object statically
  node n1(22); //constructor call
  node n2(38);
  // make the connection use next nodes' address
  n1.next=&n2;
  cout<<n1.data<<" "<<n2.data<<endl;
  
  node *head=&n1; //create a pinter head to store node1
  cout<<head->data<<endl; //the same as cout<<(*head).data<<endl;
  return 0;
}
// return:
// 22 38
// 22


/////////////////////////////
/////Print a Linked List/////
///// create nodes dynamically
class node{
  public:
    int data;
    node *next; 
    node(int data){
      this->data=data; 
      next=NULL;
    }
};

int main(){
  node *n3=new node(21); //we have stack and heap memory. new operator returns a unique and non-zero pointer as the data type declared before
  node *n4=new node(20);
  n3->next=n4;
  return 0;
}


///// create a linked list with 5 elements
class node{
  public:
    int data;
    node *next; 
    node(int data){
      this->data=data; 
      next=NULL;
    }
};

// create a print function
void print(node *head){  //if we write `node *&head`, passing by reference. Then even though we call the print function twice at the end of main(), it still returns once printing results, instead of twice. The second time place return as "NULL".
  while(head!=NULL){
    cout<<head->data<<"-> "; //head is passing by value. The link head not change, we only change the function head.
    head=head->next; //moving forward
  }
  cout<<"NULL"<<endl;
}

int main(){
  node n1(22); 
  node *head=&n1; 
  node n2(38);
  node n3(21);
  node n4(20);
  node n5(30);
  // create connections
  n1.next=&n2;
  n2.next=&n3;
  n3.next=&n4;
  n4.next=&n5;
  // print
  print(head);
  return 0;
}
// return:
// 22-> 38-> 21-> 20-> 30-> NULL


//////////////////////
/////Taking Input/////
// if we need to create large numbers of nodes, it is impossible and inconvenience to create them one by one manually.
// To make it accessible, we create a function called takeInput(), which will create linked list and return the head of ll to main.
class node{
  public:
    int data;
    node *next; 
    node(int data){
      this->data=data; 
      next=NULL;
    }
};

// create a print function
void print(node *head){  //if we write `node *&head`, passing by reference. Then even though we call the print function twice at the end of main(), it still returns once printing results, instead of twice. The second time place return as "NULL".
  node *temp=head; //create a temporary variable
  while(temp!=NULL){
    cout<<temp->data<<"-> "; //head is passing by value. The link head not change, we only change the function head.
    temp=temp->next; //moving forward
  }
  cout<<"NULL"<<endl;
}

//create the takeInput function🌟
node* takeInput(){ 
  int data;
  cin>>data;
  node *head=NULL; //linked list is empty now
  node *tail=NULL; //also means linked list is empty initially
  while(data!=-1){ //use -1 as termination mark
    // create the linked list
    // node n(data); //if we create the node statically, the scope in while brackets will only be effective for one iteration. Hence, dynamic method should be used.
    node *n=new node(data); // in this case, the node can only be deleted with the keyword `delete`. We are calling the parameter constructor here.
    // check whether the node is the first node
    if(head==NULL){ //update the address of head and tail simultaneously
      head=n; 
      tail=n;
    }else{
      tail->next=n; //insert the node at the last, moving forward, get a new tail.   //Alternatively, we can insert at head. At results, we will get the linked list printed in an opposite order.
      tail=n; //update tail
    }
    cin>>data;
  }
  return head; //if the condition in while is false, then simply execute this line.
}

int main(){
  node *head=takeInput(); //call the functions
  print(head);
  return 0;
}
// return:
// 10 98 235 66 84 34 -1
// 10-> 98-> 235-> 66-> 84-> 34-> NULL
// T=O(N)

/////Insert at head
// Approach1: apply the `reverse function` after applying the previous written functions
// Approach2: insert at head, the changing part of previous:
node* takeInput2(){ 
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
      n->next=head; //insert at head, get a new head
      head=n; //update tail
    }
    cin>>data;
  }
  return head; 
}
int main(){
  node *head2=takeInput2(); //call the functions
  print(head2);
  return 0;
}
// return:
// 34-> 84-> 66-> 235-> 98-> 10-> NULL
// T=O(N)


////////////////
/////Length/////
class node{
  public:
    int data;
    node *next; 
    node(int data){
      this->data=data; 
      next=NULL;
    }
};
// 🌟 Length function:
int length(node *head){ //if we know the head of linked list, we know the whole linked list
  int count=0;
  while(head!=NULL){ //head exists
    count++;
    head=head->next; //move forward
  }
  return count;
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

int main(){
  node *head=takeInput(); //only use insert at tail now
  cout<<length(head)<<endl; //call length functions
  return 0;
}
// return:
// 10 98 235 66 84 34 -1
// 6
// T=O(N), owing to this method just traversing across the linked list.


////////////////////////
/////Print ith Node/////
// first we need to reach at the specific index, using for/while loop moving ahead, then print the data
// add this function below the length function
void printIthNode(node *head, int i){
  int n=length(head);
  if(i<0 || i>n-1){
    cout<<"-1"<<endl; //if the index is invalid
    return;
  }
  //if the index is valid:
  int count=1;
  while(count<=i){
    head=head->next; //moving ahead until reach the index we want
    count++;
  }
  cout<<head->data<<endl; //as soon as reach the ith node, print the data
}

int main(){
  node *head=takeInput();
  printIthNode(head,3); //if we want to get the data at index 3
  return 0;
}
// return:
// 10 98 235 66 84 34 -1
// 66
// T=O(n+i), from time complexity, it is not perform well. If n>>i, the time complexity can be rewrite as T=O(n).

// As a result, we can `optimize` the code:
void printIthNode(node *head, int i){ //in this method, length function is not needed any more
  if(i<0){
    cout<<"-1"<<endl; //if the index is invalid
    return;
  }
  int count=1;
  while(count<=i && head!=NULL){  //if the index is valid
    head=head->next; //moving ahead until reach the index we want
    count++;
  }
  //Print:
  if(head!=NULL){ //check whether head exists
    cout<<head->data<<endl; //as soon as reach the ith node, print the data
  }else{
    cout<<"-1"<<endl; //the index is not valid
  }
}
// the return is the same as the previous version
// T=O(i). As for the worst case, i=n, T=O(n), which is the same as previous one. However, on average, the optimized solution is faster than previous one.


///////////////////////////////////
/////Insert Node @ith Position/////
// if we want to insert an element at position i, we need to reach at position `i-1`, create a node with the specific value, create the connection with adjacent nodes, and the original link will be broken, shift the right side elements one unit
// Two approaches:
// 1. connect the new node with the next one→ connect the new node with previous one→original link broken(easier way)
// 2.store the address of right side first remaining node as `temp`→connect the new node with previous one→ original link broken→the original right side remaining sub-linked list is lost(hence we need to storage the remaining nodes at first)→connect the new node with the first node of temp
///Approach 1:
node* insertAtIthPos(node *head,int i,int data){ //in this method, length function is not needed any more
  if(i<0){ //invalid
    return head;
  }

  if(i==0){ //insert at head
    node* n=new node(data); //create a new node dynamically
    n->next=head; //assign the address of original head in this node
    head=n; //update head
    return head;
  }

  node *copyHead=head;
  int count=1;
  while(count<=i-1 && head!=NULL){  //if the index is valid
    head=head->next; //moving ahead until reach the index we want
    count++;
  }
  //Print:
  if(head!=NULL){ //check whether head exists
    node *n=new node(data); //create a new node
    n->next=head->next;
    head->next=n;
    return copyHead;
  }
  return copyHead; //if the value of index is invalid
}

int main(){
  node *head=takeInput();
  int i, data;
  cin>>i>>data;
  head=insertAtIthPos(head,i,data); //update the head
  print(head); //use head function we have defined   
  return 0;
}
// return:
// 10 98 235 66 84 34 -1
// 5 100
// 10-> 98-> 235-> 66-> 84-> 100-> 34-> NULL

// test another case, if we want to insert at head position
// 10 98 235 66 84 34 -1
// 0 100
// 100-> 10-> 98-> 235-> 66-> 84-> 34-> NULL

// test for invalid values, the return shows our linked list is unchanged
// 10 98 235 66 84 34 -1
// -4 99
// 10-> 98-> 235-> 66-> 84-> 34-> NULL

// test for insert at index=length position, using copyHead method
// 10 98 235 66 84 34 -1
// 6 99
// 10-> 98-> 235-> 66-> 84-> 34-> 99-> NULL

///Approach 2: only shows the changed part
node* insertAtIthPos(node *head,int i,int data){ 
  //Print:
  if(head!=NULL){ //check whether head exists
    node *n=new node(data); //create the new node
    node *temp=head->next;//store the right side first remaining node address
    head->next=n;
    n->next=temp;
    return copyHead;
  }
  return copyHead; //if the value of index is invalid
}
