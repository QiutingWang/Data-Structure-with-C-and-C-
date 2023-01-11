#include <iostream>
#include <vector>
using namespace std;

/////////////////
/////Vectors/////
///Features:
// Do not need to give a size of vector when creating vector. It can resize itself automatically.(The same as dynamic array)
// We can insert as much number of elements as we want.(different from Dynamic array)
// reference:https://www.mygreatlearning.com/blog/vectors-in-c/

///Two Ways of Creating Vector:Statically and Dynamically
// 1. Syntax: vector<objectType> vectorName;
// 2. Syntax: vector<objectType> *vectorName=new vector<objectType>();

///Initialization
// Syntax: vectorName.push_back(elementValue);
  //Wrong Operation: If we directly use vectorName[index]=elementValue; We will push an element value which is outside the vector we created before, storing in the memory which is not belongs to us.

int main(){
  vector<int> v; //Statically: it will be deleted automatically, if it memory reach out of scope
  vector<int> *vp=new vector<int>(); //Dynamically: we have to delete it ourself, it cannot be deleted automatically

  for (int i=0; i<100;i++){
    v.push_back(i+1);
    cout<<v.size(); // it will increase linearly with i increasing from 1 to 100.
  }
  for (int i=0;i<v.size();i++){
    cout<<v[i]<<endl;
  }      //it will return 1~100 

  /*
  v.push_back(10);  //.push_back() function: insert the element in the vector one by one
  v.push_back(20); 
  v.push_back(30); 

  v[1]=99; //use index to change the value which already initalized
  //typically wrong for these two, not belong to vector memory-->Never Use it
  v[4]=1002; 
  v[5]=1234;

  v.push_back(77);
  v.push_back(66); 
  

  v.pop_back(); //removes elements from the back of the vector.

  for (int i=0;i<v.size(); i++){
    cout<<v[i]<<endl;
  }
  */

  /*
  /// vectorName.at(position): check whether the element in that index is valid or invalid
  cout<<v.at(4)<<endl;  //Similar to []:It returns a reference to the element at the specific position in the vector. Moreover, it is much safer to use vectorName.at(i) than vectorName[i];
  cout<<v.at(6)<<endl;  //not valid index, it will return out of range
  */
 
  /*
  cout<<v[0]<<endl; //access to the element value with [] indexing
  cout<<v[1]<<endl;
  cout<<v[2]<<endl;
  cout<<v[3]<<endl;
  cout<<v[4]<<endl;
  cout<<v[5]<<endl;
  cout<<v[6]<<endl;  //actual we only push back 5 elements into the vector, the remaining will be padded with 0(garbage values);
  */

  return 0;
}
// return: update element value
// 10   10
// 20   100
// 30   30

// return: with wrong operation
// 10
// 99
// 30
// 77
// 66
// 0
// 0

// return: .at(i)
// 66
// 'std::out_of_range'

// return: with for loop
// 10
// 99
// 30
// 77
// 66

// return: with pop_back()
// 10
// 99
// 30
// 77