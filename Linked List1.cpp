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
