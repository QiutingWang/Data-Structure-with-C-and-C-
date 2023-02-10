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

