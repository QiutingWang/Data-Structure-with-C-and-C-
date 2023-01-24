#include <iostream>
using namespace std;
/////////////////////////////////////////////
/////Print and Reverse Print Recursively/////
void print(char input[]){ //create an array
  if(input[0]=='\0'){ //if it only includes none character,just return without doing anything
    return ; 
  }
  cout<<input[0];
  print(input+1); //call recursion and moves ahead
}

void reversePrint(char input[]){
  if(input[0]=='\0'){ 
    return;
  }
  reversePrint(input+1);
  cout<<input[0];
}

int main(){
  char input[]="DorisWang";
  print(input);
  cout<<endl;
  reversePrint(input);
  return 0;
}
// return:
// DorisWang
// gnaWsiroD


//////////////////////////////
/////Find Length of Array/////
int length(char input[]){
  if(input[0]=='\0'){
    return 0;
  }
  int smallLength=length(input+1);
  return 1+smallLength;
}

int main(){
  char input[100]; //initialize
  cin>>input; //input from keyboard
  int l=length(input); //call the function
  cout<<l<<endl; //print
  return 0;
}
// return:
// Rabbit
// 6


///////////////////////////
/////Replace Character/////
// check the key value exists or not, if yes, replace it.
void replaceChar(char input[]){
  if(input[0]=='\0'){
    return;
  }
  if(input[0]=='o'){
    input[0]='e';
  }
  replaceChar(input+1);
}

int main(){
  char input[100];
  cin>>input;
  replaceChar(input);
  cout<<input<<endl;
  return 0;
}
// return:
// flowerBloom
// flewerBleem


//////////////////////////////////////////////
/////Remove Specific Character from Array/////
// check if the target value exists or not, if yes, remove, then shift the position to form a new array
void removeChar(char input[]){
  if(input[0]=='\0'){
    return ;
  }
  if(input[0]!='o'){
    removeChar(input+1);
  }else{
    for(int i=0;input[i]!='\0';i++){
      input[i]=input[i+1]; //shift the position
    }
    removeChar(input);
  }
}

int main(){
  char input[100];
  cin>>input;
  removeChar(input);
  cout<<input<<endl;
  return 0;
}
// return:
// FlowerBloom
// FlwerBlm


///////////////////////////////////////
/////Remove Consecutive Duplicates/////
void removeConsecutiveDup(char input[]){
  if(input[0]=='\0'){
    return ;
  }
  if(input[0]!=input[1]){
    removeConsecutiveDup(input+1); //call the recursion
  }else{
    for(int i=0;input[i]!='\0';i++){
      input[i]=input[i+1]; //shift the elements
    }
    removeConsecutiveDup(input); //call the recursion
  }
}

int main(){
  char input[100];
  cin>>input;
  removeConsecutiveDup(input);
  cout<<input<<endl;
  return 0;
}
// return:
// FlowerBloom
// FlowerBlom


//////////////////////////////////////////
/////Print All Subsequences of String/////
// if we have an array with length=n, then we will have 2^n sequences of this array. Because for each character it has two choice: include or exclude.
/// for each character, exclude: input.substr(1)
  // .substr(position of the first character to be copied, length of the substring), the second parameter is optional, if it isn't declared, then we treat it covers to the end.
/// include: output+input[0]

///// Use String
void printSubsequence(string input, string output){
  if(input.length()==0){ //if the string is empty
    cout<<output<<endl;
    return;
  }
  // The order of write exclude and include codes is important for the printing results
  printSubsequence(input.substr(1),output); //exclude. Namely, covers from the second element to the end.
  printSubsequence(input.substr(1),output+input[0]); //include the first element
}

int main(){
  string input;
  cin>>input;
  string output="";
  printSubsequence(input,output);
  return 0;
}
// return: the printing order we need to pay attention, the logic: binary tree
// Rose
//     // empty
// e
// s
// se
// o
// oe
// os
// ose
// R
// Re
// Rs
// Rse
// Ro
// Roe
// Ros
// Rose

///// Use Character array
void printSubsequence2(char input[], char output[], int i){ //i is created for push the value
  if(input[0]=='\0'){ 
    output[i]='\0';
    cout<<output<<endl;
    return;
  }
  // This time we print the include case first
  output[i]=input[0];//include
  printSubsequence2(input+1,output,i+1); 
  printSubsequence2(input+1,output,i); //exclude
}

int main(){
  char input[100];
  cin>>input;
  char output[10];
  printSubsequence2(input,output,0);
  return 0;
}
// return:
// Rose
// Rose
// Ros
// Roe
// Ro
// Rse
// Rs
// Re
// R
// ose
// os
// oe
// o
// se
// s
// e
// 


//////////////////////////////////////////
/////Store All Subsequences of String/////
// Store them in a vector
#include <vector>
void printSubsequence(string input, string output,vector<string> &v){ //pass the vector by reference
  if(input.length()==0){ 
    v.push_back(output); //storing
    return;
  }
  printSubsequence(input.substr(1),output,v); 
  printSubsequence(input.substr(1),output+input[0],v); 
}

int main(){
  string input;
  cin>>input;
  string output="";
  vector<string> v;
  printSubsequence(input,output,v);
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<endl;
  }
  return 0;
}
// return:
// Rose
// 
// e
// s
// se
// o
// oe
// os
// ose
// R
// Re
// Rs
// Rse
// Ro
// Roe
// Ros
// Rose


///////////////////////////////////
/////Convert String to Integer/////
// logic:the first n-1 elements composing the smallAnswer, which multiply by 10 then plus the last character at index[n-1], which need to use `char-char=int` logic, converting character to integer.
int length(char input[]){
  if(input[0]=='\0'){
    return 0;
  }
  return 1+length(input+1);
}

int convertStr2Int(char str[],int n){
  if(n==0){ 
    return 0;
  }
  int smallAns=convertStr2Int(str,n-1); //call the recursion
  int lastDigit=str[n-1]-'0'; //calculations
  int ans=smallAns*10+lastDigit;
  return ans;
}

int main(){
  char str[]="20230123"; //no more than 9 digit, for longer character, we need to use long data type.
  int n=length(str);
  int a=convertStr2Int(str,n); 
  cout<<a<<endl;
  return 0;
}
// return:
// 20230123


/////////////////////////////////////////
/////Print All Permutation of String/////
// the numbers of total permutation of a string=length!=length*(length-1)*(length-2)*...*1
// Logic: We fix the first element and combine with others, then swap the first element to another one, treat it as the fixed element, repeat the process above.
void printPermutation(char str[], int i){
  if(str[i]=='\0'){
    cout<<str<<endl;
    return;
  }
  for(int j=i;str[j]!='\0';j++){ //j is the element need to be swapped at the right side of string
    swap(str[i],str[j]);
    printPermutation(str, i+1);
    swap(str[i],str[j]); //swap back to the original for next swap and printing execute successfully
  }
}

int main(){
  char str[]="iris";
  printPermutation(str,0);
  return 0;
}
// return:
// iris
// irsi
// iirs
// iisr
// isir
// isri
// riis
// risi
// riis
// risi
// rsii
// rsii
// iris
// irsi
// iirs
// iisr
// isir
// isri
// srii
// srii
// siri
// siir
// siir
// siri


///////////////////////////
/////Staircase Problem/////
// How many number of ways to reach up to N from 0?
// Recursion application: f(N)=f(N-1)+f(N-2)+f(N-3)+...+f(0). Here, for instance, f(0)=1, f(1)=1,f(2)=2,f(3)=4
int countWays(int n){
  if(n==0||n==1){
    return 1;
  }
  /*
  if(n==2){ //also treated as base case
    return 2;
  }*/
  // Another method:
  if(n<0){ //invalid
    return 0;
  }
  return countWays(n-1)+countWays(n-2)+countWays(n-3);
}

int main(){
  int n;
  cin>>n;
  cout<<countWays(n)<<endl;
  return 0;
}
// return:
// 5
// 13


////////////////////////
/////Tower of Hanoi/////
// Game Explanation reference: https://zh.wikipedia.org/zh-cn/%E6%B1%89%E8%AF%BA%E5%A1%94
// The total steps=2^n -1 →change to power problem we have ever solved in Recursion_Basic part
// OR: f(N)=f(N-1)+1+f(N-1)=Steps(A→B)+1[Steps(A→C)]+Steps(B→C), where A: Source; B: Helper; C:Destination
int ToH(int n){
  if(n==0){
    return 0;
  }
  return ToH(n-1)+1+ToH(n-1);
}

int main(){
  int n;
  cin>>n;
  cout<<ToH(n)<<endl;
  return 0;
}
// return:
// 6
// 63


///////////////////////////////////////
/////Print Steps in Tower of Hanoi/////
int ToH(int n){
  if(n==0){
    return 0;
  }
  return ToH(n-1)+1+ToH(n-1);
}

void printSteps(int n, char source, char destination, char helper){
  if(n==0){
    return;
  }
  printSteps(n-1,source,helper,destination);
  cout<<"Moving disk"<<n<<" from "<< source <<" to "<<destination<<endl;
  printSteps(n-1,helper,destination,source);
}

int main(){
  int n;
  cin>>n;
  cout<<ToH(n)<<endl;
  printSteps(n,'A','C','B');
  return 0;
}
// return:
// 4
// 15
// Moving disk1 from A to B
// Moving disk2 from A to C
// Moving disk1 from B to C
// Moving disk3 from A to B
// Moving disk1 from C to A
// Moving disk2 from C to B
// Moving disk1 from A to B
// Moving disk4 from A to C
// Moving disk1 from B to C
// Moving disk2 from B to A
// Moving disk1 from C to A
// Moving disk3 from B to C
// Moving disk1 from A to B
// Moving disk2 from A to C
// Moving disk1 from B to C
