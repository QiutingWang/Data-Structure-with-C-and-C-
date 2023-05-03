#include <iostream>
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
