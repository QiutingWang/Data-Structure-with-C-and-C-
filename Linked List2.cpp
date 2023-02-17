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