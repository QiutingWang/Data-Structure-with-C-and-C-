//////////////////////
/////Introduction/////
// 1 bit for one unit, which is different from numerical array(4 bit for each)
// normally if there is a character array b[10]; then cin>>b; we input coding, since index6 gets automatically appended, it is a Null (\0) character. The Null is treated as Terminator-->stop printing. cout<<b;return is c o d i n g
// if the pre-set size of the character is n, then the maximum input of initialization is n-1. Because the last memory has to be \0 null. That is different from int.
#include<iostream>
using namespace std;

int main(){
  char name[100];
  cout<<"Enter your name: ";
  cin>>name;
  cout<<"Your name is "<<name<<endl;
  return 0;
}
// return:
// Enter your name: Doris
// Your name is Doris


//////////////////////////
/////Length of String/////
int length(char input[]){
  int count=0;
  for (int i=0; input[i] != '\0'; i++){ //if the character is not null, then take this element into counting
    count++;
  }
  return count;
}

int main(){
  char name[100];
  cout<<"Enter your name: ";
  cin>>name;
  cout<<"Your name is "<<name<<endl;
  cout<<"Length: "<<length(name);
  return 0;
}
// return:
// Enter your name: Doris
// Your name is Doris
// Length: 5


///////////////////////
/////cin.getline()/////
// If we want to get the output out of our memory, the program might crash.
// But the limitation of cin function: can take anything as an input. 
// The second limitation of cin: if the input we set contains space, then the output should always be the part before the first space. eg: input from keyboard is Doris Wang; output only returns Doris. While, cin can contain spaces, tab, newline'\n'(delimiter, breaking point)
// Those limits are the reasons why we need cin.getline().
// Syntax: cin.getline(stringName, length, optional:endingCharacter);
// If omit the last one, it will be set as '\0'. 
// If we set endingChar=4, then it will return only 3 char, because the last one is \0.
// if we have cin.getline(a) and int variableName[b]: a cannot larger than b. a<=b.
// As soon as the cin.getline() reach to the newline character, it will stop printing.
/////Space in input
int length(char input[]){
  int count=0;
  for (int i=0; input[i] != '\0'; i++){
    count++;
  }
  return count;
}

int main(){
  char name[100];
  cout<<"Enter your name: ";
  cin.getline(name, 100);
  cout<<"Your name is "<<name<<endl;
  cout<<"Length: "<<length(name);
  return 0;
}
// return:
// Enter your name: Doris Wang
// Your name is Doris Wang
// Length: 10

/////constrain the length limit
int length(char input[]){
  int count=0;
  for (int i=0; input[i] != '\0'; i++){ 
    count++;
  }
  return count;
}

int main(){
  char name[100]; //this is not matter
  cout<<"Enter your name: ";
  cin.getline(name, 4); //the length of print in .getline() function is matter
  cout<<"Your name is "<<name<<endl;
  cout<<"Length: "<<length(name);
  return 0;
}
// return:
// Enter your name: Doris Wang
// Your name is Dor
// Length: 3

/////setting the endingCharacter
int length(char input[]){
  int count=0;
  for (int i=0; input[i] != '\0'; i++){ 
    count++;
  }
  return count;
}

int main(){
  char name[100]; 
  cout<<"Enter your name: ";
  cin.getline(name, 100, 'g');   //it will stop before once pre-set letter appear, regardless the re-emerge of this character later.
  cout<<"Your name is "<<name<<endl;
  cout<<"Length: "<<length(name);
  return 0;
}
// // return
// Enter your name: Qiuting Wang
// Your name is Qiutin
// Length: 6


////////////////////////
/////Reserve String/////
// use swap(start, end) and while method
int length(char input[]){
  int count=0;
  for (int i=0; input[i] != '\0'; i++){ 
    count++;
  }
  return count;
}

void reverse(char input[]){
  int start=0;
  int end=length(input)-1; //except the null character

  while(start<end){
    swap(input[start], input[end]);
    start++;
    end--;
  }
}

int main(){
  char name[100]; 
  cout<<"Enter your name: ";
  cin.getline(name, 100);   
  cout<<"Your name is "<<name<<endl;
  reverse(name);  //insert the reverse function inside main and apply to name
  cout<<"Reverse Character Array: "<<name<<endl;
  cout<<"Length: "<<length(name);
  return 0;
}
// return:
// Enter your name: Doris Wang
// Your name is Doris Wang
// Reverse Character Array: gnaW siroD
// Length: 10