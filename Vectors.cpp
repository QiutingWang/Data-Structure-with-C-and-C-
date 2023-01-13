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
  
  ///Initialization: Create a vector of given size and value
    //Syntax: vector<objectType> vectorName(size,value(optional));
  vector<int> v2(10,-2); //all the values are initalized as -2 with size 10
  for (int i=0;i<v2.size(); i++){
    cout<<v2[i]<<endl;
  }
  // Sort the vector using .sort()
  sort(v2.begin(), v2.end());

  for (int i=0; i<100;i++){
    cout<<"Capacity "<<v.capacity()<<endl; // .capacity(): give the current capacity of the vector. In this case, it doubly increases from 0,1...to 128 to contain 100 elements.
    cout<<v.size(); // it will increase linearly with i increasing from 1 to 100.
    v.push_back(i+1);
  }
  for (int i=0;i<v.size();i++){
    cout<<v[i]<<endl;
  }      //it will return 1~100 

/// Differences between capacity and size:
// .size() gives how many elements are present
// .capacity() gives how many elements you can insert inside the vector, the return type is double. It doubly increases. 0 1 2 4 4 8 8...
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


/////////////////////////////
/////Spiral Order Matrix/////
// the input is a matrix, then we need to traverse the matrix in spiral order顺时针方向
///implementation
// Four variables needed: startRow, endRow, startColumn, endColumn
// Logic: startRow→endColumn→endRow→startColumn,then startRow++, endColumn--, endRow--, startColumn++ with for loop. 
// add Constrain(stopping condition) with while: startColumn<=endColumn && startRow<=endRow;
// Another stopping condition: count=0, as soon as the printed elements equal to m*n, stop the program
///Example: LeetCode#54 Spiral Matrix https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int m=matrix.size();
        int n=matrix[0].size();

        int startRow=0,endRow=m-1,startColumn=0,endColumn=n-1;
        int count=0; 

        while(startRow<=endRow && startColumn<=endColumn){
            //print the startRow
            for(int i=startColumn; i<=endColumn; i++){
                answer.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            if(count==m*n) return answer;
            //print the endColumn
            for(int i=startRow; i<=endRow;i++){
                answer.push_back(matrix[i][endColumn]);
                count++;
            }
            endColumn--;
            if(count==m*n) return answer;
            //print the endRow
            for(int i=endColumn;i>=startColumn;i--){
                answer.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            if(count==m*n) return answer;
            //print the startColumn
            for(int i=endRow; i>=startRow; i--){
                answer.push_back(matrix[i][startColumn]);
                count++;
            }
            startColumn++;
            if(count==m*n) return answer;
        }
        return answer;
    }
};
//in this case: Space Complexity:O(1), Time Complexity:O(m*n)
