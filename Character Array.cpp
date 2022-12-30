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


///////////////////////////
/////Inbuilt Functions/////
#include<cstring>         //manipulate strings and arrays
/////1. strlen()
int main(){
  char string1[100];
  cin>>string1;
  int len=strlen(string1);  //strlen(string) returns the length of the given C-string.
  cout<<"Length: "<<len<<endl;
  return 0;
}
// return:
// Hello
// Length: 5

/////2. Compare two strings character by character: strcmp(str1, str2). 
// If the strings are equal, the function returns 0.  >0: str1>str2.  <0: str1<str2.
int main(){
  char string1[100];
  char string2[100];
  cin>>string1>>string2;

  if (strcmp(string1, string2)==0){
    cout<<"equal"<<endl;
  }else{
    cout<<"not equal"<<endl;
  }

  return 0;
}
// return:
// Hello Hello
// equal

// write the code about strcmp() function
bool mystrcmp(char str1[], char str2[]){
  if (strlen(str1) != strlen(str2)) return false;

  for (int i=0; i<strlen(str1); i++){
    if (str1[i] != str2[i]) return false;
  }
  return true;
}

/////3. Copy one string and do another string: strcpy(destinationString, sourceString)
int main(){
  char str1[100]="Doris";
  char str2[100]="Wang";
  
  cout<<"Before Copying"<<endl;
  cout<<"str1 "<<str1<<endl;
  cout<<"str2 "<<str2<<endl;

  strcpy(str1, str2); //copy the content of string2 to string1, and replace the original content in string1

  cout<<"After Copying"<<endl;
  cout<<"str1 "<<str1<<endl;
  cout<<"str2 "<<str2<<endl;

}
// return:
// Before Copying
// str1 Doris    //Doris \0
// str2 Wang
// After Copying
// str1 Wang     // Wang \0 \0, it also copies the null character.
// str2 Wang     // string2 is not affected.

/////4. Copy the first n characters: strncpy(destinationString, sourceString, n); n: how many characters you want to copy
int main(){
  char str1[100]="Happy";
  char str2[100]="NewYear";
  
  cout<<"Before Copying"<<endl;
  cout<<"str1 "<<str1<<endl;
  cout<<"str2 "<<str2<<endl;

  strncpy(str1, str2, 4); 

  cout<<"After Copying"<<endl;
  cout<<"str1 "<<str1<<endl;
  cout<<"str2 "<<str2<<endl;
}
// return:
// Before Copying
// str1 Happy
// str2 NewYear
// After Copying
// str1 NewYy
// str2 NewYear

/////5. strcat(str1, str2), copy the str2 behind the str1 coming to a new one string, without any effects on str2.
int main(){
  char str1[100]="Happy";
  char str2[100]="NewYear";

  cout<<"Before Copying"<<endl;
  cout<<"str1 "<<str1<<endl;
  cout<<"str2 "<<str2<<endl;

  strcat(str1, str2);

  cout<<"After Copying"<<endl;
  cout<<"str1 "<<str1<<endl;
  cout<<"str2 "<<str2<<endl;
}
//return:
// Before Copying
// str1 Happy
// str2 NewYear
// After Copying
// str1 HappyNewYear
// str2 NewYear


////////////////////////////
/////Print all Prefixes/////
// set each result start index=0,and ending index is different use loop
void printAllPrefixes(char str[]){
  for (int end=0; end<strlen(str); end++){
    for (int start=0; start<=end; start++){
      cout<<str[start];
    }
    cout<<endl;
  }
}
int main(){
  char str[]="GoodMorning";
  printAllPrefixes(str);
  return 0;
}
// return:
// G
// Go
// Goo
// Good
// GoodM
// GoodMo
// GoodMor
// GoodMorn
// GoodMorni
// GoodMornin
// GoodMorning
