///////////////////////////////////
/////Introduction to 2D Arrays/////
// if we want to create a 3*3 array: 
// First option: divide into 3 arrays with size=3: a1[3],a2[3],a3[3];
// Second option: create a 1 array with size=9: a4[9]; Then we need to do some calculation to find the corresponding position of the index in this array
// Third option: create a 2-dim (m*n) array, input data row wise or column wise. We need to create loop in loop.
// Syntax: data_type array_name[size1][size2]....[sizeN];
// references: https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/
#include <iostream>
using namespace std;

int main(){ 
  int a[100][100]; 
  int m,n;
  cin>>m>>n; //input the number of rows and columns

  //input the specific value 
  for (int i=0; i<m; i++){     //write the matrix in row wise
    for (int j=0; j<n; j++){
      cin>>a[i][j]; 
    }
  }
  //print the matrix
  // print in row wise with loop in loop
  for (int i=0; i<m; i++){     
    for (int j=0; j<n; j++){
      cout<<a[i][j]<<" "; //give the space between elements
    }
    cout<<endl;
  }

  //print in column wise
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      cout<<a[j][i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
// return:
// 2 3
// 1 2 3 4 5 6

// 1 2 3
// 4 5 6

// 1 4 
// 2 5 
// 3 6 


///////////////////////////////////////////////////
/////Initialise and Pass 2D Arrays to Function/////
// When initialize giving row is optional, while giving column is mandatory and keep it the same when pass it into function;
// if some values are not given directly, be default, they will be set=0;
// if we want to create a matrix with all values=0, eg: int a[10][10]={{0}};
void printArray(int a[][3],int m,int n){
  // print in row wise with loop in loop
  for (int i=0; i<m; i++){     
    for (int j=0; j<n; j++){
      cout<<a[i][j]<<" "; 
    }
    cout<<endl;
  }
}
int main(){
  int a[][3]={{1,2}, 
              {3,4}};
  //call the function
  printArray(a, 2, 3);
  return 0;
}
// return:
// 1 2 0
// 3 4 0


////////////////////////////////////////////
/////How 2D Arrays are Stored in Memory/////
// store in row by row(row major approach) or column by column(column major approach)
// Index Issue: convert the index in matrix into the position of 1-D array -->done automatically by the program system
// Index calculation Formula:
// Program stores in Row Major Method: int a[R][C]; a[i][j]=i*C+j; where R: row, C: column.
// That is why column initial is mandatory.
