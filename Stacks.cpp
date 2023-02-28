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


///////////////////
/////Templates/////
// use templates to avoid copy and paste repeatedly if the only thing needed to do is to change the data type, by passing data type as a parameter
// Two keywords: `template<typename T>`. The second one can be replaced by `class`.
// Format: T x; means x is a variable of type T.
//Function Templates: write a generic function that can be used for different data types. 
// we can pass more than one data type as arguments to templates.
// we can specify default arguments to templates
template<typename T> //without semicolon
class Pair{
  private:
    T x;
    T y;

  public: //setter and getter for private area
    void setX(T x){
      this->x=x;
    }
    T getX(){
      return x;
    }
    void setY(T y){
      this->y=y;
    }
    T getY(){
      return y;
    }
};

int main(){
  Pair<int> p1; //in p1, all of datatypes are int.
  p1.setX(1);
  p1.setY(2);
  cout<<p1.getX()<<" "<<p1.getY()<<endl;

  Pair<double> p2; //in p1, all of datatypes are double.
  p2.setX(1.25);
  p2.setY(2.22);
  cout<<p2.getX()<<" "<<p2.getY()<<endl;
 
  return 0;
}
// return:
// 1 2
// 1.25 2.22

// If we want to set up two variables with different dataTypes, one template typename is not enough. In this case, we need to add one more typename in our template.
template<typename T, typename V>
class Pair{
  private:
    T x;
    V y;

  public: //setter and getter for private area
    void setX(T x){
      this->x=x;
    }
    T getX(){
      return x;
    }
    void setY(V y){
      this->y=y;
    }
    V getY(){
      return y;
    }
};

int main(){
  Pair<int,char> p3; 
  p3.setX(5);
  p3.setY('E');
  cout<<p3.getX()<<" "<<p3.getY()<<endl;
 
  return 0;
}
// return:
// 5 E

// Special case: Pair in Pair(Triplet)
// if one element in pair contains two elements(actual this element is a pair),how to define and print it.
// But we cannot use second level of nesting any more.
int main(){
  Pair<Pair<int,int>,int> p4;
  p4.setY(30);
  Pair<int,int> temp;
  temp.setX(10);
  temp.setY(20);
  p4.setX(temp);
  cout<<p4.getX().getX()<<" "<<p4.getX().getY()<<" "<<p4.getY()<<endl;

  return 0;
}
// return:
// 10 20 30


///////////////////////////////
/////Stack using Templates/////
// to create generic class
template<typename T>
class Stack{
   T *arr; //we need to change all arr related datatype to T.
   int nextIndex; //has to be integer
   int capacity; //has to be integer

   public:
       Stack(){
          capacity = 4;
          arr = new T[capacity];
          nextIndex = 0;
       }
       int size(){
          return nextIndex;
       }
       bool isEmpty(){
         return nextIndex==0;
       }
       void push(T element){
          if(nextIndex==capacity){
            T *newArr = new T[2*capacity];
            for(int i=0;i<capacity;i++){
                newArr[i] = arr[i];
            }
            delete []arr;
            arr = newArr;
            capacity = 2*capacity;
          }
          arr[nextIndex] = element;
          nextIndex++;
       }
       void pop(){
          if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return;
          }
          nextIndex--;
       }
       T top(){
         if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return 0; //change -1 to 0
          }
         return arr[nextIndex-1];
       }
};

int main(){
  Stack<char> s;
  s.push(100);
  s.push(101);
  s.push(102);
  s.push(103);
  s.push(104);

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
// return
// h
// g
// f
// 2
// 0
