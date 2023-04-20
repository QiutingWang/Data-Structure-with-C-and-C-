#include <iostream>
using namespace std;
//////////////////////
/////Introduction/////
// references:https://www.geeksforgeeks.org/what-is-hashing/
// hashing: a popular technique with direct access table for storing and retrieving data as fast as possible, with time complexity T=O(1)
// key-value pair: key and value can be any data type, key has to be unique
// operations: 
  // hashtable: create a new hash table; 
  // delete: delete a specific key-value pair from table
  // get: search a key inside hash table and return the corresponding value of the key
  // put: insert a new key-value pair
  // DeleteHashTable: delete the hash table
// way of implementation:
  // linked list: structure: data(key,value), next element position. T=O(N), cuz we need to search the key first
  // Balanced BST: T=O(logN)
  // Hash Table


///////////////////////////
/////In-Built Hash Map/////
#include <unordered_map>
#include <string>

int main(){
  unordered_map<string, int> myMap; //declare the key-value pair and its data type
  //insert elements method1:
  pair<string, int> p("Doris",17);
  myMap.insert(p);
  //insert elements method2: with bracket
  myMap["Age"]=22;

  // find and access elements
  cout<<myMap["Doris"]<<endl; //method1: with bracket
  cout<<myMap.at("Doris")<<endl; //method2: use .at()

  cout<<"Size: "<<myMap.size()<<endl;

  // search for the element without inserting before
  /*cout<<myMap.at("Gilbert")<<endl;*/ 
  cout<<myMap["Gilbert"]<<endl; //if search with bracket, the return will be 0. Owing to the bracket first insert the key into myMap, then return a default value 0.
  // use the count function(check how many time the key present inside the map with 0 & 1 indicator value) to check the presence of a key
  if(myMap.count("Gilbert")>0){
    cout<<"Gilbert is present"<<endl;
  }else{
    cout<<"Not present"<<endl;
  }

  // update keys
  myMap["Doris"]=917;
  // find the size of map, how many key-value pairs in the map
  cout<<"Size: "<<myMap.size()<<endl;
  
  //delete
  myMap.erase("Gilbert");
  // check
  if(myMap.count("Gilbert")>0){
    cout<<"Gilbert is present"<<endl;
  }else{
    cout<<"Not present"<<endl;
  }
  cout<<"Size: "<<myMap.size()<<endl;


  return 0;
}
// return:
// 17
// 17
// Size: 2
// 'std::out_of_range'
// 0
// Gilbert is present
// Size: 3
// Not present
// Size: 2


///////////////////////////
/////Remove Duplicates/////
// vectors stored hash map elements contain only unique ones
// use unordered_map T=O(1)[linear], or we can use map approach T=O(logN)
#include <vector>
vector<int> removeDuplicates(int *a, int n){ //n is size of the vector
  vector<int> output; // construct the vector store the unique elements in the same order
  unordered_map<int, bool> myMap; //construct the unordered map

  for(int i=0;i<n;i++){
    if(myMap.count(a[i])==0){ //if it is coming for the first time, take key as input
      output.push_back(a[i]); //push inside the vector
      myMap[a[i]]=true; //push into myMap
    }
  }
  return output;
}

int main(){
  int a[]={1,2,7,4,10,46,9,3,7,5,2,55,79,34,22,5,1}; //give the elements
  vector<int> output=removeDuplicates(a, 17); //call the constructor
  for(int i=0;i<output.size();i++){
    cout<<output[i]<<" "<<endl; //call the output vector and print it
  }
  return 0;
}
// return
// 1 
// 2 
// 7 
// 4 
// 10 
// 46 
// 9 
// 3 
// 5 
// 55 
// 79 
// 34 
// 22
// T=O(N)


///////////////////
/////Iterators/////
#include<bits/stdc++.h>
// C++ HashMaps. https://leimao.github.io/blog/CPP-HashMaps/

///// Unordered_set: https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/. 
  // If we only care about the `key`, and ignore the corresponding values
  // #include <unordered_set> STL, unordered_set<data_type> name
  // Time complexity:T=O(1);
  // values are unsorted, only unique values
  // use Hash table for implementation
  // important functions:
    // size(), empty(),find(),insert(),erase(),begin(),end(),count(),clear(),cbegin(), cend(), swap(),max_size()

///// set: https://www.geeksforgeeks.org/set-in-cpp-stl/
  // each element has to be `unique` because the value of the element identifies it.
  // the values are stored in a specific `sorted order`
  // #include <set> in STL, set <data_type, greater<data_type>> set_name
  // it follows binary search tree implementation
  // the values in a set are unindexed.
  // Time complexity:T=O(logN);
  // important functions:
    // begin(), end(), size(), max_size(), empty(),erase(), find(),lower_bound(const g), upper_bound(const g), swap(), count()

///// map: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/?ref=lbp
  // a associative containers stored elements in a mapped fashion, with `key and mapped value` elements
  // time complexity: T=O(logN)
  // #include <map> in STL
  // `sorted` order output according to `keys` will be obtained

///Keyword: auto, find the data type automatically
  // advantages: to avoid long initializations when creating iterators for containers.  

int main(){
  //unordered_map iteration
  unordered_map<string, int> myMap; 
  myMap["Doris"]=1;
  myMap["Emma"]=2;
  myMap["Cheryl"]=3;
  myMap["Franklin"]=4;
  myMap["Jose"]=5;
  myMap["Klaus"]=6;
  //iteration with pointer 'it'
  for(auto it=myMap.begin(); it!=myMap.end(); it++){
    cout<<"Key: "<<it->first<<", Value: "<<it->second<<endl;
  }

  // construct map to get ordered result in terms of key with iterator
  map<string, int> myMap2; 
  myMap2["Doris"]=11;
  myMap2["Emma"]=22;
  myMap2["Cheryl"]=33;
  myMap2["Franklin"]=44;
  myMap2["Jose"]=55;
  myMap2["Klaus"]=66;
  for(map<string, int>::iterator it=myMap2.begin(); it!=myMap2.end(); it++){
    cout<<"Key: "<<it->first<<", Value: "<<it->second<<endl;
  }

  // iterator of vector
  vector<int> v;
  v.push_back(10);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  for(auto it = v.begin(); it!=v.end(); it++){
        cout<<*it<<endl; //it contains address to access elements
        }
 //find the key exists or not
  if(myMap.find("Doris")==myMap.end()){ //end: next of last element, which means Doris is not present
    cout<<"Not Present";
  }else{
    cout<<"Present";
  }

 //erase specific elements
  //unordered_map<string, int>::iterator it=myMap.find("Doris");
  myMap.erase(myMap.begin(), myMap.end());  //we delete the whole map now
  //find the iterator
  if(myMap.find("Doris")==myMap.end()){ //end: next of last element, which means Doris is not present
    cout<<"Not Present";
  }else{
    cout<<"Present";
  }
  for(auto it=myMap.begin(); it!=myMap.end(); it++){
    cout<<"Key: "<<it->first<<", Value: "<<it->second<<endl;
  }
  cout<<myMap.size()<<endl; //check the size to figure out whether it is delete the whole elements or not

  // auto related application
  auto a = 5;
  cout<<a<<endl;
  auto c = "Doris";
  cout<<c<<endl;
  
  return 0;
}
// return:
// Key: Jose ,Value: 5
// Key: Cheryl ,Value: 3
// Key: Klaus ,Value: 6
// Key: Franklin ,Value: 4
// Key: Doris ,Value: 1
// Key: Emma ,Value: 2       //it is an unordered result

// Key: Cheryl, Value: 33
// Key: Doris, Value: 11
// Key: Emma, Value: 22
// Key: Franklin, Value: 44
// Key: Jose, Value: 55
// Key: Klaus, Value: 66

// 10
// 2
// 3
// 4
// 5

// Present
// Not Present
// 0

// 5
// Doris


//////////////////////////////////////
/////Bucket Array & Hash Function/////
// references: https://en.wikipedia.org/wiki/Hash_function
/////Implement Hash Map using Hash Table
// in hash map, store and access both require constant time O(1), with (key,value) of `array` called bucket array. The process: 
  // convert the key(can be string, integer, bool...) into an integer, pass key in hash function, then return a practical integer.
  // store the key and value got from hash function(treated as `index`) in bucket array.
  // when we input the index, it can return the corresponding key-value pair

// Hash Function: 
  // Hash Code: it can return any integer
    //types: sum of ASCII, EBCDIC, MD5, or SHA1 values. Taking care of permutation issues, we only consider the sum of first three characters
    // if the original key is string, we can pass by their `addresses` as input, then convert into integer with hash code
  // Compression Function: convert into `fixed-size valid index`
    // given requirement of XX% bucket size, then the valid index range is [0,XX-1].
// What is a good hash function?
  // computationally and storage space-efficient form of data access
  // give us a uniformity distribution with `huge range of integer`

// What if there are multiple keys will come to the same index?-->Collision


////////////////////////////
/////Collision Handling/////
// 2 Types of collision handling techniques:
  // Closed Hashing:
    // Separate Chaining: 
      // construct a `linked list` after the corresponding index, to store the multiple keys.
      // each `bucket` will be the `head` of the linked list. Hence, multiple keys will present in that index
  // Open Addressing:
    // a key pass through the `hash function` which will give an index
      //there is an `empty` index, no key-value pair stored<--`store` the key here
      // if it is not empty, we have to find `alternative index` for storing key-value pair
        // h_i(k)=hashFunction(k)+f(i), where i: ith attempt for finding the index, k: key, hashFunction(k): original index
          // basic case: f(i)=0, when i=0 store in original index
          // different f(i) is different addressing technique
            // 1. Linear Probing(LP): f(i)=i, take the jump of 1: 0,1,2,3,4,... HashFunction=hashFunction(k)+i%N;
            // 2. Quadratic Probing(QP): f(i)=i^2. HashFunction=hashFunction(k)+(i^2)%N; take the jump at index of 0,1,4,9,16,...
          // Quadratic probing is better. Because Linear Probing will incur clustering problem. With QP, we will have a good distribution with a larger range.
            // 3. Double Hashing: use two hash functions for reducing conflicts. HF1(k)+HK2(k)


/////////////////////////
/////Implementation/////
/////Destructor:
// instance member function invoked automatically whenever an object will be destroyed.
// has the same name as class name, preceded by a ~
// number of destructor<=1
// it releases memory space occupied by objects created by constructor

template<typename V>
class MapNode{
  public:
    string key;
    V value;
    MapNode *next;
    //constructor
    MapNode(string key, V value){
      this->key=key;
      this->value=value;
      next=NULL;
    }
    //destructor
    ~MapNode(){
      delete next; //all the recursive linked list will be destroyed 
    }
};

template<typename V>
class myMap{
  private:
    MapNode<V>** buckets; //call the constructor
    int count;
    int numBuckets;

    int getBucketIndex(string key){
      //calculate hash code,initialization, iterate from tail to head
      // eg: abc->ap^2+bp^1+cp^0. The larger p, the value is increasing faster, being out of range.
      int hashCode=0;
      int base=1;   //base=p^0
      int p=37;
      for(int i=key.size()-1;i>=0;i--){
        hashCode += key[i]*base; //sum up 
        base = base*p; //update
        //apply the percentage buckets, keep our value ranges smaller
        hashCode=hashCode%numBuckets;
        base=base%numBuckets;
      }
      return hashCode%numBuckets;
    }
  public:
    myMap(){
      count=0;
      numBuckets=5;
      buckets=new MapNode<V>*[numBuckets];
      for(int i=0;i<numBuckets;i++){
        buckets[i]=NULL;
      }
    }
    ~myMap(){ //we need to delete the linked lists first, then delete bucket array elements recursively
      for(int i=0;i<numBuckets;i++){
        delete bucket[i];
      }
      delete []buckets;
    }
    /////Define operation functions
    int size(){
      return count;
    }

    V getValue(string key){
      //initialize the key and pass the value to head pointer
      int bucketIndex=getBucketIndex(key); 
      MapNode<V>* head=buckets[bucketIndex];
      //iterate the linked list to find out the key
      while(head!=NULL){
        if(head->key==key){
          return head->value;
        }
        head=head->next;
      }
      return 0; //the given key is not present
    }

    void insert(string key, V value){
      int bucketIndex=getBucketIndex(key); //call the function to find out index of bucket array
      MapNode<V>* head=buckets[bucketIndex]; //pass the bucket index value to newly created linked list head index
      //traverse the linked list
      while(head!=NULL){ //if the given key is present
        if(head->key==key){ //check the given key is present or not
          head->value=value; //update the value
          return; //directly return
        }
        head=head->next; //move ahead 
      }
      //if the given key is not present, we need to create a node, insert at the head, and unlink the original head
      MapNode<V>* node=new MapNode<V>(key, value); //call the constructor to create a new node
      node->next=buckets[bucketIndex]; //make the new connection
      buckets[bucketIndex]=node; //update the head
      count++;
    }
///Delete: 
//iterate the linked list to find out the key we want to delete
//take previous & current pointers to finish delete operation(break the original link and create new link)
    V remove(string key){
      //find the bucket index
      int bucketIndex=getBucketIndex(key);
      MapNode<V>* head=buckets[bucketIndex];
      MapNode<V>* previous=NULL; //initialize the previous pointer

      while(head!=NULL){
        if(head->key==key){ //delete the head only
          if(previous==NULL){ //check the previous value is empty or not
            buckets[bucketIndex]=head->next; //move ahead the pointer to update the bucket index
          }else{
            previous->next=head->next; //destroy the original link and create a new link
          }
          V value=head->value; //store the value before deleting
          head->next=NULL; //isolate the node
          delete head;
          count--;
          return value;
        }
        previous=head;
        head=head->next; //update
      }
      return 0; //default value indicates given key is not present
    }
};


/////Time Complexity&Load Factor
//insert: on average, T=O(n/b), where n: numbers of entities; b: bucket size; n/b: load factor
  // n/b<threshold, usually we set threshold=0.7 or 0.65... Hence, T<O(1)≈O(1)
  // how to ensure the threshold is always valid? 
    // Solution: `increase b` to adjust the range fill into the desired one, called Rehashing. Normally, we double b.
// delete and search also take constant time O(1).


/////////////////////////////
/////Rehashing Implement/////

