#include <iostream>
#include <cstring>
using namespace std;

/////Shallow Copy, Deep Copy, and Own Copy Constructor:
class Student{
    int age;
  public:
    char *name;

    Student(Student const &s){ //infinite loop is created, avoiding this, we use pass by reference add &.
      this->age=s.age;
      // this->name=s.name; ///shallow copy
      ///Deep copy
      this->name=new char[strlen(s.name)+1]; //create a new array
      strcpy(this->name, s.name);
    }

    Student(int age, char *name){
      this->age=age;
      // this->name=name;    ///shallow copy:copy only the address and 0th index
      ///Deep Copy: create a new array for deep copy with the same size:copy the entire copy
      this->name=new char[strlen(name)+1]; //plus one to copy the null char
      strcpy(this->name,name); //strcpy(destination, source); copy the content
    }
    void display(){
      cout<<name<<" "<<age<<endl;
    }
};


/////Initialization:
class Student1{
  public:
    int age1;
    int &x; //age 
    const int rollNumber; //let this variable cannot be changed, constant variable cannot contain garbage value. Hence, const dataType varName; is false syntax. 
    // Another inflexible syntax: We need to initialize the value. const dataType varName=value; But we can not change the value anymore.

    // Solution: constructor for each object having a value
    Student(int r, int a): rollNumber(r), age1(a), x(this->age1){}     
    //use initialization list to prevent containing garbage value as soon as the variable created. 
    // rollNumber(r) means: const int rollNumber=r; 
};

//Another Example:
class Point {
private:
    int x;
    int y;
public:
    Point(int i = 0, int j = 0):x(i), y(j) {}
    /*  The above use of Initializer list is optional as the
        constructor can also be written as:
        Point(int i = 0, int j = 0) {
            x = i;
            y = j;
        }
    */     
    int getX() const {
      return x;
      }
    int getY() const {
      return y;
      }
};

class Fraction{
  private:
    int numerator;
    int denominator;

  public:
    Fraction(){

    }
    Fraction(int numerator, int denominator){
      this->numerator=numerator;
      this->denominator=denominator;
    }
    int getNumerator() const{     //mark a function as a constant function, by adding 'const' keyword before {}
      return numerator;
    }
    int getDenominator() const{
      return denominator;
    }
    void setNumerator(int n){   //cannot be constant function, because it is used to change the attribute
      numerator=n;
    }
    void setDenominator(int d){
      denominator=d;
    }
    void print() const{              //can be set into constant function, owing to it only accesses the properties
      cout<< this->numerator<<"/"<<denominator<<endl;
    }
    void simplify(){
      int gcd=1;
      int j=min(this->numerator, this->denominator);
      for (int i; i<=j; i++){
        if(this->numerator % i==0 && this->denominator % i==0){
          gcd=i;
        }
      }
      this->numerator=this->numerator/gcd;
      this->denominator=this->denominator/gcd;
    }
    void add(Fraction const &f2){
      int lcm=denominator* f2.denominator;
      int x=lcm/denominator;
      int y=lcm/f2.denominator;

      int num=x*numerator +(y*f2.numerator);

      numerator=num;
      denominator=lcm;
      
      simplify();
    }
    void multiply(Fraction const &f2){
      numerator =numerator* f2.numerator;
      denominator=denominator* f2.denominator;

      simplify();
    }
};



class Student{
    static int totalStudents; //intuition: each student cannot have different totalStudent quantity. It is a static member, being the same for all objects.This attribute belongs to the class.

  public:
    int rollNumber;     //once the object is created, only the non-static attributes are copied.
    int age;

    // If we create a new object, the value of totalStudents should add 1, with the help of constructor
    Student(){         
      totalStudents++;
    }
    int getRollNumber(){
      return rollNumber;
    }
   static int getTotalStudents(){  //create a static function
      return totalStudents;
    }
};
int Student::totalStudents=0; //initialization static member outside the class



class Fraction{
  private:
    int numerator;
    int denominator;

  public:
    Fraction(){

    }
    Fraction(int numerator, int denominator){
      this->numerator=numerator;
      this->denominator=denominator;
    }
    int getNumerator() const{     //mark a function as a constant function, by adding 'const' keyword before {}
      return numerator;
    }
    int getDenominator() const{
      return denominator;
    }
    void setNumerator(int n){   //cannot be constant function, because it is used to change the attribute
      numerator=n;
    }
    void setDenominator(int d){
      denominator=d;
    }
    void print() const{              //can be set into constant function, owing to it only accesses the properties
      cout<< this->numerator<<"/"<<denominator<<endl;
    }
    void simplify(){
      int gcd=1;
      int j=min(this->numerator, this->denominator);
      for (int i; i<=j; i++){
        if(this->numerator % i==0 && this->denominator % i==0){
          gcd=i;
        }
      }
      this->numerator=this->numerator/gcd;
      this->denominator=this->denominator/gcd;
    }
    Fraction operator+(Fraction const &f2){
      int lcm=denominator* f2.denominator;
      int x=lcm/denominator;
      int y=lcm/f2.denominator;

      int num=x*numerator +(y*f2.numerator);

      /*numerator=num;
      denominator=lcm;*/

      Fraction fNew(num, lcm); //parameterized constructor called 
      fNew.simplify();
      return fNew;
    }
    void multiply(Fraction const &f2){
      numerator =numerator* f2.numerator;
      denominator=denominator* f2.denominator;

      simplify();
    }
    Fraction operator*(Fraction const &f2){
      int n=numerator* f2.numerator;
      int d=denominator* f2.denominator;
      Fraction fNew(n,d);
      fNew.simplify();
      return fNew;
    }
    bool operator==(Fraction const &f2){
      return (numerator==f2.numerator && denominator==f2.denominator);
    }
    //Pre-increment 
    Fraction& operator++(){
      numerator= numerator + denominator;
      simplify();
      return *this; //*this means content, while this only includes the address
    }
    //Post-increment
    Fraction operator++(int){ //pass int keyword as argument to differentiate with pre-increment
      Fraction fNew(numerator,denominator);
      numerator=numerator+denominator;
      simplify();
      fNew.simplify();
      return fNew;
    }
    //+= operator
    Fraction operator+=(Fraction const &f2){
      int lcm=denominator* f2.denominator;
      int x=lcm/denominator;
      int y=lcm/f2.denominator;

      int num=x*numerator +(y*f2.numerator);

      numerator=num;
      denominator=lcm;
      simplify();
      return *this;
    }
};



class DynamicArray{
  int *data;
  int nextIndex;
  int capacity; //total size of the array

  public:
    DynamicArray(){
      data=new int[5];
      nextIndex=0;
      capacity=5;
    }
    DynamicArray(int c){     //users can defined arrays with the size they want
      data=new int[c];
      nextIndex=0;
      capacity=c;
    }
    DynamicArray(DynamicArray const &d){
      this->nextIndex=d.nextIndex;
      this->capacity=d.capacity;
      // this->data=d.data;      //shallow copy
      ///Create a deep copy
      this->data=new int[d.capacity]; //create a new array
      for (int i=0;i<d.nextIndex; i++){
        this->data[i]=d.data[i];
      }
    }
    /// Operator Overloading
    void operator=(DynamicArray const &d){    //inside code is the same as the above one
       this->nextIndex=d.nextIndex;
      this->capacity=d.capacity;
      
      this->data=new int[d.capacity]; 
      for (int i=0;i<d.nextIndex; i++){
        this->data[i]=d.data[i];
      }
    }
    void add(int element){
      if(nextIndex==capacity){     //create a new array with double size, new data=copy of old content+newly insert number
      int *newData=new int[capacity*2];
      for (int i=0;i<capacity;i++){
        newData[i]=data[i];
      }
      delete []data; //delete the old data. If we don't do so, it will lead to memory leak.
      data=newData;  //update the dataset and capacity to original names
      capacity=capacity*2;
      }
      data[nextIndex]=element;
      nextIndex++;
    }
    void add(int element,int i){  //insert an element @index i
      if (i<nextIndex){
        data[i]=element;
      }else if(i==nextIndex){
        add(element); //call the add function we created before
      }else{
        return ;
      }
    }
    int getElement(int i) const{
      if(i>=0 && i<nextIndex){    //inside the bracket, it sets the valid i conditions
        return data[i];
      }else{
        return -1; //return the default value
      }
    }
    void print() const{
      for (int i=0; i<nextIndex; i++){
        cout<<data[i]<<" ";
      }
      cout<<endl;
    }
    int getCapacity() const{
      return capacity;
    }
};
/////Memory Leak:
// reference:https://www.geeksforgeeks.org/memory-leak-in-c-and-how-to-avoid-it/
// This phenomena occurs when allocating memory by using new keyword and forgetting to deallocate the memory by using delete() function or delete[] operator to free an array of data values
// Disadvantage: memory usage is satirically increasing, computational cost increases.

