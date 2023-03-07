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


/////////////////////////////////
/////Stack using Linked List/////
// references: https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/
// every function T=O(1)
// Mostly, we use single linked list. LIFO. First node on the top of stack. `Last node` of linked list represents `bottom` of the stack.
// `Insert at head` is only allowed in stack using linked list.
// Advantage of using linked list: it is possible to implement a stack that can shrink or grow as much as needed, without capacity limit.

template <typename T> //this line code should be written above any class which we going to use template
class node{ //make it as generic class for any data type by Templates
  public:
    T data;
    node<T> *next; //add a pointer
    node(T data){  //initialization
      this->data=data;
      next=NULL;
    }
};

template <typename T>
class stack{
  private:
    node<T> *head;
    int size;

  public:
    stack(){ //initialize
      head=NULL;
      size=0;
    }
    int getSize(){
      return size;
    }
    bool isEmpty(){
      return size==0; //check the size is empty or not
    }
    void push(T element){
      node<T> *n=new node<T>(element); //create a new node with template
      n->next=head; //create the connection between original head and insert element
      head=n; //update head
      size++; //update size
    }
    void pop(){ //remove the top most element
      if(isEmpty()){ //check if the stack is null
        cout<<"Stack empty"<<endl;
        return;
      }
      node<T> *temp=head; //create a new temp at head
      head=head->next; //move the head to next node, update head
      temp->next=NULL; //isolation
      delete temp; //deallocate memory, free the temp node
      size--; //update size
    }
    T top(){
      if(isEmpty()){ //check if the stack is null
        cout<<"Stack empty"<<endl;
        return 0;
      }
      return head->data;
    }
};

int main(){
  stack<char> s;
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
  cout<<s.getSize()<<endl;
  cout<<s.isEmpty()<<endl;
  return 0;
}
// return
// h
// g
// f
// 2
// 0


///////////////////////
/////Inbuilt Stack/////
// Content: push(), pop(), top(), size(), empty()相对之前的构造方法，expression更加简单
#include <stack>
int main(){
  stack<int> s;
  s.push(1); //we can push as many elements as we want, without considering the capacity
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);

  cout<<s.top()<<endl;
  s.pop();
  cout<<s.top()<<endl;
  s.pop();

  cout<<s.size()<<endl;
  cout<<s.empty()<<endl;

  while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
  }
  cout<<s.size()<<endl;
  return 0;
}
// return
// 6
// 5
// 4
// 0
// 4
// 3
// 2
// 1
// 0


///////////////////////////////////////////////////////////
/////Check Balanced Valid Parenthesis with Linked List/////
// the input is string(6 characters): () {} []
// Valid parenthesis: opening and closing are matching. 
// The process of using stack to check:
  // if `opening` bracket, then push()
  // if it is `closing`, check whether it is matched with the corresponding opening one. 
    // if it is matched with opening one, pop() 
    // if it is not matched, return false
  // At final, check whether the stack is empty
    // if the remaining stack is empty, return true
    // if the remaining stack is not empty, return false
// T=O(n), S=O(n)

// LeetCode20 https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string A) {
        stack<char> s;

        for(int i=0;i<A.size();i++){
            if(A[i]=='(' || A[i]=='[' || A[i]=='{'){ //push the opening bracket inside the stack
                s.push(A[i]);
            }else{
                if(s.empty()) return false; //if do not write, it will return running time error
                // check the ending bracket is matched or not
                else if(A[i]==')'){
                    if(s.top()=='(') s.pop();
                    else return false;
                }else if(A[i]==']'){
                    if(s.top()=='[') s.pop();
                    else return false;
                }else if(A[i]=='}'){
                    if(s.top()=='{') s.pop();
                    else return false;
                }
            }
        }
        // check whether the string is empty or not
        if(s.empty()) return true;
        return false;
    }
};


///////////////////////////////////////////////////
/////Evaluate Reverse Polish(postfix) Notation/////
// references:
  // https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/
  // https://www.cs.colostate.edu/~cs165/.Fall19/recitations/L15/doc/traversal-order.html
  // https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/
// three notations:infix, postfix, prefix
  // postfix notation: Operators are written after pair of operands, evaluated faster than other expressions
  // infix notation: Operators are written in-between pair of operands
  // prefix notation: Operators are written before pair of operands.
// calculation process: change into postfix expression and then evaluate the postfix expression
  // Conversion: infix->postfix
    // scan infix from left to right
    // move the operators to the corresponding closing brackets
  // Evaluation Rules: Assumption the postfix is valid
    // We must have two operands for applying operators
    // in stack: if scanned element is operand, push into stack
    // if scanned element is operator, pop the `top two elements` in stack, apply the operator, push the calculated `result` in the stack
    // Finally, our answer is top of stack

// LeetCode No.150 https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
// with the given postfix 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                // two elements
                int value1=st.top();
                st.pop();
                int value2=st.top();
                st.pop();
                // perform the operation
                if(tokens[i]=="+" ){
                    st.push(value2+value1); //push result to stack
                }
                else if(tokens[i]=="-"){
                    st.push(value2-value1); 
                }
                else if(tokens[i]=="*"){
                    st.push(value2*value1); 
                }
                else if(tokens[i]=="/"){
                    st.push(value2/value1); 
                }
            }
            else{
                // operands
                st.push(atoi(tokens[i].c_str())); 
                //convert the string to integer using inbuilt function: atoi(string) with C-style string as input.
                //  There are two types of string in C++: C-style (char a[]), string class. 
                // Hence, we need to convert string s into C-style string first, using function .c_str()
            }
        }
        // finally, it remains only one element in stack, which is our answer
        return st.top();
    }
};
// T=O(n); S=O(n)


//////////////////////////////////////////////////
/////Remove All Adjacent Duplicates in String/////
// also delete adjacent duplicates in post-deleted string repeatedly, until we no longer can.有点像开心消消乐
🟦🟦🟥🟥🟪🟪🟫🟫🟨🟨⬛️⬛️
// with the help of map, and a stack of characters
  // if the stack is empty, push
  // comparison between the top element already in stack and element at index i
    // if they are not equal, push
    // if they are equal, pop from stack and move foreword
  // finally, as soon as reach to the end of the string, the answer is the remaining elements in stack, by pop() every element out of stack, then reverse the string to get the final answer.
    // as results, every element in final answer string is unique.

// LeetCode No.1047 https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
class Solution {
public:
    string removeDuplicates(string A) {
        stack<char> s;
        for(int i=0;i<A.size();i++){ //traverse
            if(s.empty() || A[i]!=s.top()){ //comparison and check whether empty in stack now
               s.push(A[i]); 
            }else{
                s.pop(); //pop and move ahead 
            }
        }
        string ans="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end()); //give the correct order
        if(ans.size()==0) return "Empty String";
        return ans;
    }
};
// T=O(n), S=O(n)

///Optimization with S=O(1)
// we only need to maintain a top pointer, without reserve the order at final
class Solution {
public:
    string removeDuplicates(string A) {
        int stringPointer=-1; //create a pointer and initialization, -1 means empty
        for(int i=0;i<A.size();i++){ //traverse
            if(stringPointer==-1 || A[i]!=A[stringPointer]){ //comparison and check whether empty in stack now
               stringPointer++; //move ahead
               A[stringPointer]=A[i]; //push the element
            }else{
                stringPointer--; //delete the element by don't put it into stack
            }
        }
        string ans=""; 
        for(int i=0;i<=stringPointer;i++){
            ans.push_back(A[i]); //put the final answer in string
        }
        return ans;
    }
};
// T=O(n)

