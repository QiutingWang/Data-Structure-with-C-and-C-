////////////////
/////String/////
// Treated as Class or a kind of data type
// contains a collection of characters surrounded by double quotes, null terminated ie. the last character is '\0'
// if the character length >256, buffer overrun problem raise
// to deal with this problem
// references: String https://www.w3schools.com/cpp/cpp_strings.asp
#include <iostream>
#include <string>
using namespace std;

int main(){
  string s="tempus";
  cout<<s<<endl;

  string s2;
  s2="fugit";
  cout<<s2<<endl;

  string *sp=new string;
  *sp="CarpeDiem";
  cout<<sp<<endl;
  cout<<*sp<<endl;

  return 0;
}
// return:
// tempus
// fugit
// 0x56097bb1a2c0 //the address
// CarpeDiem

/////Store Multiple Strings, use vector
// references: Vector https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html
// create a vector: vector<type> vec; 
#include <vector> //header
#include <algorithm> //include sort
#include <cstring> //atoi

int main(){
  string s="tempus";
  cout<<s<<endl;

  string s2;
  s2="fugit";
  cout<<s2<<endl;

  string *sp=new string;
  *sp="CarpeDiem";
  cout<<sp<<endl;
  cout<<*sp<<endl;

  vector<string> v;   //vector v is initially empty
  v.push_back(s);     //method: inserts a new element onto the back of a vector
  v.push_back(s2);
  for (int i=0; i<v.size(); i++){    //.size(): return the number of values stored in the vector
    cout<<v[i]<<endl;
    sort(v[i].begin(), v[i].end());  //sort(vec.begin(),vec.end()); by default, it is sorted ascending order
    cout<<v[i]<<endl;
  }

  string s3;
  // getline(cin, s3);   //syntax: getline(instream, stringName)
  // cout<<s3<<endl; 

  s3="Amantes";
  cout<<s3[1]<<endl; //extract by indexing, start from 0 as well
  s3[6]=a;  //change the last letter
  cout<<s3<<endl;

  string s4=s1 + s2 +"Audaces fortuna iuvat"; //concatenation, add multiple strings together
  cout<<s4<<endl;
  cout<<s4.size()<<endl; //or use  cout<<s4.length()<<endl;
  cout<<s4.substr(3)<<endl; //.substr(index) giving the characters from the specific index to the end(include itself)

  string s5=s4.substr(3,5); //.substr(index, # of characters we need), without changing original string, but return a new string
  cout<<s5<<endl;

  cout<<s4.find("Audaces")<<endl; //.find(values); it will return the index of A, the first letter of the object

  int a= 917;
  string s6=to_string(a); //convert int to str
  cout<<s6<<endl;
  s6[1]='2'; //change the value in a string written way
  cout<<s6<<endl; 

  s6.push_back('5');
  cout<<s6<<endl;

  a= atoi(s6.c_str()); //atoi(string); convert string into int type
  cout<<a<<endl;

  return 0;
}
// return:
// tempus
// fugit
// 0x5605636952c0
// CarpeDiem
// tempus
// empstu   //after sorting
// fugit
// fgitu    //after sorting
// in love  //keyboard input
// in love  //print s3 with space by using getline()
// m
// Amantea
// tempusfugitAudaces fortuna iuvat
// 32
// pusfugitAudaces fortuna iuvat
// pusfu
// 11
// 917
// 927
// 9275  //string
// 9275  //int

/////Another Methods that vector supports:
// .pop_back(): removes the last element from a vector
// .operator[](): provides access to the value stored at a given index within the vector
// .at(): provides the given position within the vector
// .empty(): return True: if has no value; return False: if have more than one or one value
// .clear(): make the vector empty
// .erase()
// .insert()