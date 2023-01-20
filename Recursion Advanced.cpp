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


