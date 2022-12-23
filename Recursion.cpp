#include<bits/stdc++.h>
using namespace std;
///////////////////
/////Recursion/////
//Definition: when a function is call itself
// main()->A()->A()...
// We use it when the solution of a problem depends on the solution of a smaller problem with the same nature but a different input size
// Example: fact(N)=n*fact(N-1) to compute n!
int fact(int n){
  cout<<n<<endl;
  if (n==0) return 1; //to make a finite recursion without running out of memories.
  int smallAns=fact(n-1);
  return n*smallAns;
}

int main(){
  int n;
  cin>>n;
  int ans=fact(n);
  cout<<ans<<endl; 
  return 0;
}
// return:24 if we set input==4

//cout: standard output stream, predefined object of ostream class, with stream insertion operator (<<) to display the output on a console
// cin: standard input stream, with stream extraction operator >> to read the input from a console
// endl: standard end line,  used to insert a new line characters and flushes the stream.
// Call Stack: main()->fact(4)->fact(3)->...->fact(0) then once return the ans, the corresponding fact(n) function goes out of the memory. The goes out order is reverse:fact(0),fact(1)...,fact(4),main()


///////////////////////////
/////Recursion and pmi/////
// Principle of Mathematical Induction(PMI):used to prove facts
int fact(int n){
  ///first case:base case
  if (n==0){
    return 1;
  }
  int smallAns=fact(n-1); //second step:Assumption, recursive case(Induction Hypothesis)
  int ans=n*smallAns; //third step: Calculation to prove step 2 and step1
  return ans;
}
int main(){
  cout<<fact(4)<<endl;
  return 0;
}
// return:24