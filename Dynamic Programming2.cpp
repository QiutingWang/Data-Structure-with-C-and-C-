#include <iostream>
#include <vector>
using namespace std;
////////////////////////////////////////////////////////
/////Longest Common Subsequence between Two Strings/////
/////Recursive Approach
// LeetCode No.1143 https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int LCS(string S1, int i, string S2, int j){ //i and j are indexes of string S1 and S2 correspondingly
        if(i==S1.size()||j==S2.size()){ //the strings are not exist
            return 0;
        }
        //check match or mismatch
        // match
        if(S1[i]==S2[j]){
            return 1+ LCS(S1,i+1,S2,j+1); //1+ the remaining strings recursively
        }
        // mismatch
        return 0+max(LCS(S1,i,S2,j+1),LCS(S1,i+1,S2,j)); // we have two options, call the remaining part of string2 compared with string1, or call the remaining of string1 compared with string2. As results, we get the maximum value.
    }
    int longestCommonSubsequence(string text1, string text2) {
        return LCS(text1,0,text2,0);
    }
};


/////DP
//create a matrix the length and width are the lengths of S1 and S2 +1 
class Solution {
public:
    int LCS(string S1, int i, string S2, int j){ //i and j are indexes of string S1 and S2 correspondingly
        if(i==S1.size()||j==S2.size()){ //the strings are not exist
            return 0;
        }
        //check match or mismatch
        if(S1[i]==S2[j]){
            return 1+ LCS(S1,i+1,S2,j+1); //1+ the remaining strings recursively
        }
        return 0+max(LCS(S1,i,S2,j+1),LCS(S1,i+1,S2,j));
    }
    int longestCommonSubsequence(string S1, string S2) {
        int m=S1.size();
        int n=S2.size();
        int dp[m+1][n+1];

        for(int i=0;i<=m;i++){
            //base case
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                //match
                else if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{ //mismatch
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};


//////////////////////////
/////Minimum Distance/////
// LeetCode No.72 https://leetcode.com/problems/edit-distance/
// return the minimum numbers of operations required to convert word1 to word2. The allowed operations as follows:
  // insert
  // delete
  // replace
// Process: compare from the last character, if match then move on to the previous ones recursively, if not match then use insert/delete/replace operation recursively

// Recursive Approach
class Solution {
public:
    int MD(string S1, int m, string S2, int n){
        if(m==0){ 
            //insert all the characters in string 2
            return n;
        }
        if(n==0){
            //delete all the characters in string 1
            return m;
        }
        if(S1[m-1]==S2[n-1]){ //check from the last characters of S1 and S2
            return MD(S1, m-1, S2, n-1); //call the recursion of the remaining parts of S1 and S2
        }
        int Insert=MD(S1, m, S2, n-1);
        int Delete=MD(S1, m-1, S2, n);
        int Replace=MD(S1, m-1, S2, n-1);
        return 1+min(Insert, min(Delete, Replace));
    }
    int minDistance(string word1, string word2) {
        return MD(word1, word1.size(), word2, word2.size());
    }
};


// Dynamic Programming Approach
// construct a matrix dp[m+1][n+1] with pointers i and j from dp[0][0] recursive moves to dp[m][n]
class Solution {
public:
    int MD(string S1, int m, string S2, int n){
        if(m==0){ 
            //insert all the characters in string 2
            return n;
        }
        if(n==0){
            //delete all the characters in string 1
            return m;
        }
        if(S1[m-1]==S2[n-1]){ //check from the last characters of S1 and S2
            return MD(S1, m-1, S2, n-1); //call the recursion of the remaining parts of S1 and S2
        }
        int Insert=MD(S1, m, S2, n-1);
        int Delete=MD(S1, m-1, S2, n);
        int Replace=MD(S1, m-1, S2, n-1);
        return 1+min(Insert, min(Delete, Replace));
    }
    int minDistance(string S1, string S2) {
        int m=S1.size();
        int n=S2.size();
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==0){
                    dp[i][j]=j;
                }else if(j==0){
                    dp[i][j]=i;
                }else if(S1[i-1]==S2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int Insert=dp[i][j-1]; //insert one character in S1, then call the remaining parts of S1 and S2
                    int Delete=dp[i-1][j]; //delete one character in S1, then call the remaining parts of S1 and S2
                    int Replace=dp[i-1][j-1]; 
                    dp[i][j]=1+min(Insert, min(Delete, Replace));
                }
            }
        }
        return dp[m][n];
    }
};
// T=O(mn), S=O(mn)


//////////////////////
/////0-1 Knapsack/////
// https://www.interviewbit.com/problems/0-1-knapsack/
// maximum profit with weights limitation of a knapsack to contain various goods with different prices and weights
// for each kind of goods, we have 2 options: we pick this item or not pick it(0-1 property), for fulfilling maximum profits and not exceeds the bag's weight limit.

/////Recursive Approach
// WKnapsack: weight limit of package
// n: numbers of item
// Price Weight: prices and weights of different items
int knapsack(int n, int WKnapsack, vector<int> Price, vector<int> Weight){ //this function will return the max profit
    if(n==0 || WKnapsack==0){
        return 0;
    }
    if(Weight[n-1] > WKnapsack){
        return knapsack(n-1, WKnapsack, Price, Weight); //if the last item weight is bigger than package limitation, then call recursion
    }else{
        int include=Price[n-1]+ knapsack(n-1, WKnapsack-Weight[n-1], Price, Weight);
        int exclude=knapsack(n-1, WKnapsack, Price, Weight); //move ahead to next one
        return max(include, exclude);
    }
}

int Solution(vector<int> &Price, vector<int> &Weight, int WKnapsack) {
    return knapsack(Price.size(), WKnapsack, Price, Weight);
}


/////Dynamic Programming Approach
// create a matrix(2-D array) to solve this problem because there are two variables changed 
// construct a matrix dp[n+1][WKnapsack+1] with pointers i and j from dp[0][0] recursive moves to dp[n][KWeights]
int knapsack(int n, int WKnapsack, vector<int> Price, vector<int> Weight){ //this function will return the max profit
    if(n==0 || WKnapsack==0){
        return 0;
    }
    if(Weight[n-1] > WKnapsack){
        return knapsack(n-1, WKnapsack, Price, Weight); //if the last item weight is bigger than package limitation, then call recursion
    }else{
        int include=Price[n-1]+ knapsack(n-1, WKnapsack-Weight[n-1], Price, Weight);
        int exclude=knapsack(n-1, WKnapsack, Price, Weight); //move ahead to next one
        return max(include, exclude);
    }
}

int Solution(vector<int> &Price, vector<int> &Weight, int WKnapsack) {
    int n=Price.size();
    int dp[n+1][WKnapsack+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=WKnapsack; j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else if(Weight[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                int include=Price[i-1]+dp[i-1][j-Weight[i-1]];
                int exclude=dp[i-1][j];
                return max(include, exclude);
            }
        }
    }
    return dp[n][WKnapsack];
}
