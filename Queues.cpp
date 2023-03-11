#include <iostream>
using namespace std;
////////////////////////////
/////Queue Introduction/////
// references: https://www.programiz.com/cpp-programming/queue
// Abstract datatype with specific order to insert and delete elements
// FIFO: elements are added first that will be removed first.
// methods:
  // push(): inserts an element at the back
  // pop():removes an element from the `front` of the queue
  // front(): returns the first element 
  // back():returns the last element 
  // size()
  // empty():returns true if the queue is empty
// Implement: Array(& Dynamic Array) or Linked List, inbuilt Queue


////////////////////////////////////////
/////Queue Using Array Introduction/////
// in queue, entry and exit point are different. As consequences, we need to maintain two pointers(nextIndex, firstIndex), initialize 0 -1 correspondingly. We do the operations with these two pointers move ahead or backward.
// user should give the capacity first
// Size calculation: use size==NULL to check the empty
  // size=nextIndex-firstIndex (without circulating)
  // size=(nextIndex-firstIndex+n)%n (with/without circulating)
// when we pop some elements, they become garbage but not delete, which means there spaces still be counted in size of queue. If we insert extra element at rear now, the capacity will run out.
  // 2 Solutions: 
    // Shifting: as soon as the capacity is full(the position is fixed unless we move it), we can shift all the un-popped elements toward left, update the firstIndex and nextIndex values. Then we can insert extra elements now.
    // Circulating(make the array circular): update nextIndex=0, then insert the new element here.
      // we cannot use circulating method in stack, thanks to its entry=exit
      // normally, the second solution is more favorable than solution1.
template<typename T>
class queue{
  private:
    T *arr;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
  
  public:
    queue(){ //set a default constructor
      capacity=5;
      arr=new T[capacity];
      nextIndex=0;
      firstIndex=-1;
      size=0;
    }
    queue(int cap){
      capacity=cap;
      arr=new T[capacity]; //create the new array
      //initialization
      nextIndex=0;  
      firstIndex=-1; //does not exit
      size=0;
    }
    int getSize(){
      return size;
    }
    bool isEmpty(){
      return size==0;
    }
    // insert elements
    void push(T element){
      if(size==capacity){ //constrain: check whether we have remaining capacity to insert another element
        cout<<"Queue Full"<<endl;
        return; //without insert
      }
      arr[nextIndex]=element;
      //moving circularly, we cannot simply write nextIndex++, mode capacity is needed
      nextIndex=(nextIndex+1)%capacity;
      if(firstIndex==-1){
        firstIndex=0; //update firstIndex, because after push, the queue is not empty anymore
      }
      size++;
    }
    T front(){
      if(isEmpty()){ //to avoid the firstIndex=-1 situation occurs
        cout<<"Queue empty"<<endl;
        return 0; //0 can maintain any dataType
      }
      return arr[firstIndex];
    }
    void pop(){
      if(isEmpty()){ //to avoid the firstIndex=-1 situation occurs
        cout<<"Queue empty"<<endl;
        return; 
      }
      firstIndex=(firstIndex+1) %capacity; //for circular queue, mode capacity is needed
      size--;
      // the part below is optional
      if(size==0){
        //reset index
        nextIndex=0;
        firstIndex=-1;
      }
    }
};

int main(){
  queue<int> q(5);
  q.push(11);
  q.push(22);
  q.push(33);
  q.push(44);
  q.push(55);
  q.push(66);
  q.push(77);
  cout<<q.front()<<endl;
  q.pop();
  q.pop();
  q.pop();
  cout<<q.front()<<endl;
  cout<<q.getSize()<<endl;
  cout<<q.isEmpty()<<endl;
  q.push(88);
  q.push(99);
  q.pop();
  q.pop();
  cout<<q.front()<<endl;
  cout<<q.getSize()<<endl;
  return 0;
}
// return:
// Queue Full
// Queue Full
// 11
// 44
// 2
// 0  (false)
// 88
// 2


///////////////////////
/////Dynamic Queue/////
// Remove the size constrains: 
  // make the new array with a larger capacity(normally we double the original capacity)
  // copy the original array into new array
/// Only revised part of above is shown:
template<typename T>
class queue{
       /// insert element🌟
       void push(T element){
          if(size == capacity){
            T *newArr = new T[2*capacity];
            int j = 0;
            for(int i=firstIndex;i<capacity;i++){
                newArr[j] = arr[i];
                j++;
            }
            for(int i=0;i<firstIndex;i++){
                newArr[j] = arr[i];
                j++;
            }
            firstIndex = 0;
            nextIndex = capacity;
            capacity = 2*capacity;
            delete []arr;
            arr = newArr;

          }
          arr[nextIndex] = element;
          nextIndex = (nextIndex + 1)%capacity;
          if(firstIndex == -1){
            firstIndex = 0;
          }
          size++;
       }
};

///main() is the same as above

// return:
// 11
// 44
// 4
// 0
// 66
// 4


//////////////////////////////////
/////Queue Using Linked List /////
///push()
// We have head pointer only, we need to iterate over the linked list to reach the last node, and make the new connection. As consequences, T=O(N)
// Additionally, we can optimize our method to obtain T=O(1) by maintaining tail pointer as well.
template<typename T>
class node{
  public:
    T data;
    node* next;
    node(T data){
      this->data=data;
      next=NULL;
    }
};

template<typename T>
class queue{
  node<T>* head;
  node<T>* tail;
  int size;

  public:
    queue(){ //constructor
      head=NULL;
      tail=NULL;
      size=0;
    }
    int getSize(){
      return size;
    }
    bool isEmpty(){
      return size==0;
    }
    void push(T element){
      node<T>* n=new node<T>(element); //create a new node
      if(head==NULL){ //check empty
        head=n; 
        tail=n;
      }else{
        tail->next=n; //move ahead and set the newly created node
        tail=n; //update
      }
      size++;
    }
    T front(){
      if(isEmpty()){ //check empty
        return 0;
      }
      return head->data;
    }
    void pop(){
      if(head==NULL){ //check empty
        return;
      }
      node<T>* temp=head; //use a temporary pointer
      head=head->next;//move forward
      temp->next=NULL; //isolation
      delete temp;
      size--;
    }
};

int main(){
  queue<int> q;
  q.push(11);
  q.push(22);
  q.push(33);
  q.push(44);
  q.push(55);
  q.push(66);
  q.push(77);
  cout<<q.front()<<endl;
  q.pop();
  q.pop();
  q.pop();
  cout<<q.front()<<endl;
  cout<<q.getSize()<<endl;
  cout<<q.isEmpty()<<endl;
  q.push(88);
  q.push(99);
  q.pop();
  q.pop();
  cout<<q.front()<<endl;
  cout<<q.getSize()<<endl;

  while(!q.isEmpty()){
    cout<<q.front()<<endl;
    q.pop();
  }
  cout<<q.getSize()<<endl;
  cout<<q.isEmpty()<<endl;
  return 0;
}
// return
// 11
// 44
// 4
// 0
// 66
// 4
// 66
// 77
// 88
// 99
// 0
// 1


///////////////////////
/////Inbuilt Queue/////
// we do not need to define class queue manually
#include <queue>

int main(){
  queue<int> q;
  q.push(11);
  q.push(22);
  q.push(33);
  q.push(44);
  q.push(55);
  cout<<q.front()<<endl;
  q.pop();
  q.pop();
  cout<<q.front()<<endl;
  cout<<q.size()<<endl;
  q.push(66);
  q.push(77);
  q.pop();
  cout<<q.front()<<endl;
  cout<<q.size()<<endl;

  while(!q.empty()){
    cout<<q.front()<<endl;
    q.pop();
  }
  cout<<q.size()<<endl;
  return 0;
}
// return
// 11
// 33
// 3
// 44
// 4
// 44
// 55
// 66
// 77
// 0

// Always use the inbuilt queue thanks to its simplicity, without the needs of using linked list or array to build the extra define class.


/////////////////////////
/////Reverse a Queue/////
#include <stack>
// push the queue elements in stack, then take them out of stack to reform a new queue with an reverse order
// Pass by value VS pass by reference. https://www.educative.io/answers/pass-by-value-vs-pass-by-reference
void reverse(queue<int> &q){ //pass q by reference, not by value. If we use call by value, we only return function q in this reverse function, which is different from what we will get in main funciton about q
  stack<int> s;
  while(!q.empty()){
    s.push(q.front());
    q.pop();
  }
  // q is empty, stack is full. This time we push the elements from stack to queue
  while(!s.empty()){
    q.push(s.top());
    s.pop();
  }
}

int main(){
  queue<int> q;
  for(int i=1;i<=5;i++){
    q.push(i);
  }
  reverse(q);
  // print
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  return 0;
}
// return
// 5 4 3 2 1
