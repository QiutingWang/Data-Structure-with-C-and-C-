#include <iostream>
using namespace std;
////////////////////////////
/////Stack Introduction/////
/// references: https://www.programiz.com/cpp-programming/stack
/// Order:
// Abstract dataType: There will be a specific order in which you can insert or delete the elements. Namely, we cannot insert/delete in between.
// LIFO: last in first out, insert at top and delete at top.

/// Operations we can perform on stack:
// insert at top: push()
// remove from top: pop()
// access and return the element on the top: top()
// return # of elements in stack: size()
// return true(1) if stack is empty: empty()
  // stack underflow: pop an item from the stack, when the stack is empty
  // stack overflow: insert additional element while the size of stack has been already full.

/// Recursion related:
// recursion uses stack, recursive function call in stack memory


//////////////////////////////////////
/////Stack Implication with Array/////
// We can also implement by linked list.
class Stack{
  private:
    int *arr; //we do not know the size we want to create, here we use dynamic array.
    int nextIndex; //used for stack operations
    int capacity;
  
  public:
    Stack(){ //default constructor, if the users do not provide the specific size
      capacity=4; 
      arr=new int[capacity]; 
      nextIndex=0;
    }
    Stack(int cap){ //parameter constructor
      capacity=cap;
      arr=new int[capacity];
      nextIndex=0;
    }
    //size
    int size(){
      return nextIndex; //return the number of elements present in stack
    }
    bool isEmpty(){
      if(nextIndex==0){
        return true;
      }else{
        return false;
      }
    }
    //push
    void push(int element){
      if(nextIndex==capacity){ //check whether the capacity is full, avoid stack overflow problem
        cout<<"Stack Full"<<endl;
        return;
      }
      arr[nextIndex]=element;
      nextIndex++;
    }
    //pop
    void pop(){
      if(isEmpty()){ //do not do anything if stack is empty, avoid stack underflow problem
        cout<<"Stack Empty"<<endl;
        return;
      }
      nextIndex--;
    }
    //top
    int top(){
       if(isEmpty()){ //do not do anything if stack is empty, avoid stack underflow problem
        cout<<"Stack Empty"<<endl;
        return -1;
      }
      return arr[nextIndex-1];
    }
};

int main(){
  Stack s(4);
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  cout<<s.top()<<endl;
  s.pop();
  cout<<s.top()<<endl;
  s.pop();
  cout<<s.top()<<endl;
  s.pop();
  cout<<s.size()<<endl;
  cout<<s.isEmpty()<<endl;

  Stack s2(10); //create another stack
  for(int i=1;i<=10;i++){
    s2.push(i);
  }
  // print the content of stack
  while(!s2.isEmpty()){
    cout<<s2.top()<<endl;
    s2.pop();
  }
  cout<<s2.size()<<endl;
  return 0;
}
// return
// Stack Full
// 40
// 30
// 20
// 1
// 0

// 10
// 9
// 8
// 7
// 6
// 5
// 4
// 3
// 2
// 1

// 0


///////////////////////
/////Dynamic Stack/////
// problem of previous functions we create: size constraint
// Solution: solve it by create another longer stack, copy the original shorter array on the longer one, then delete the original one.
class Stack{
  private:
    int *arr; 
    int nextIndex; 
    int capacity;
  
  public:
    Stack(){ 
      capacity=4; 
      arr=new int[capacity]; 
      nextIndex=0;
    }
    //size
    int size(){
      return nextIndex; 
    }
    bool isEmpty(){
      if(nextIndex==0){
        return true;
      }else{
        return false;
      }
    }
    //push, and create a new stack, copy the data, delete original array, assign the `arr` to newly created array now and capacity updates.
    void push(int element){
      if(nextIndex==capacity){ 
        int *newArr=new int[2*capacity]; //create with double size as before
        for(int i=0;i<capacity;i++){ //copy
          newArr[i]=arr[i];
        }
        delete []arr; //delete
        //updates
        arr=newArr;
        capacity=2*capacity;
      }
      arr[nextIndex]=element;
      nextIndex++;
    }
    //pop
    void pop(){
      if(isEmpty()){ 
        cout<<"Stack Empty"<<endl;
        return;
      }
      nextIndex--;
    }
    //top
    int top(){
       if(isEmpty()){ 
        cout<<"Stack Empty"<<endl;
        return -1;
      }
      return arr[nextIndex-1];
    }
};

int main(){
  Stack s; //user without giving the size, because it is a dynamic stack.
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  cout<<s.top()<<endl;
  s.pop();
  cout<<s.top()<<endl;
  s.pop();
  cout<<s.top()<<endl;
  s.pop();
  cout<<s.size()<<endl;
  cout<<s.isEmpty()<<endl;
  
  return 0;
}
// return:
// 50
// 40
// 30
// 2
// 0


