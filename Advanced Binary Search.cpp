#include <vector>
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////
/////Find First and Last Occurrence for a Given Key Value in a Sorted Array/////
/////LeetCode No.34 https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// target value exist or not exist. 
// If the key value not exist return [-1,-1]
// If the key value exist, it might be duplicated or only with one unique index
// First we use `linear search` for the _unsorted array_, T=O(n),S=O(1)
// `binary search` can be applied in sorted array. Compare the midpoint with target value. We use this method to solve the problem.T=O(logn), S=O(1).
class Solution {
public:
    int getFirstPos(vector<int>& nums, int target){
        int start=0;
        int end=nums.size()-1;
        int ans=-1;

        //define the mid index
        while(start<=end){
            int mid=(start+end)/2; 

            //comparison between midpoint and key value
            if(nums[mid]==target){
                ans=mid; //save the answer
                end=mid-1;//search the left half side for the first position
                // return mid;
            }else if(nums[mid]<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }

    int getLastPos(vector<int>& nums, int target){
        int start=0;
        int end=nums.size()-1;
        int ans=-1;

        while(start<=end){
            int mid=(start+end)/2; //define the mid index

            //comparison between mid point and key value
            if(nums[mid]==target){
                ans=mid; //save the answer
                start=mid+1;//search the right half side for the last position, which is the only difference with getStartPos function.
                // return mid;
            }else if(nums[mid]<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1); //create a vector with 2 elements, given the default value=-1;
        //call the function
        int first=getFirstPos(nums,target);
        if(first==-1){ //2 possible reasons: not exist or the target value occurs at the first index 
            return v;
        }
        int last=getLastPos(nums, target);

        //update the vector
        v[0]=first;
        v[1]=last;
        return v;
    }
};
// if we want to count the number of target duplicates, occurrence= last-first+1;


////////////////////////////////////////
/////Search in Rotated Sorted Array/////
// Assumption: the array has no duplicates.
// choose a pivot with index k, dividing the array into 2 sub-arrays, then move the second sub-array ahead of the original first sub-array.
///// LeetCode No.33 https://leetcode.com/problems/search-in-rotated-sorted-array/
//🌟 Graphical explanation reference: https://www.cnblogs.com/lichen782/p/leetcode_Search_in_Rotated_Sorted_Array.html
class Solution {
public:
    int search(vector<int>& nums, int target) {
       int start=0;
       int end=nums.size()-1;

       while(start<=end){
           int mid=(start+end)/2;

           if(nums[mid]==target){ //case1
               return mid;
           }

           if(nums[start]<nums[mid]){ //case2
               if(target>=nums[start] && target<=nums[mid]){
                   end=mid-1;
               }else{
                   start=mid+1;
               }
           }else{ //case3
               if(target>=nums[mid] && target<=nums[end]){
                   start=mid+1;
               }else{
                   end=mid-1;
               }
           }
       }
       return -1; //the given target doesn't appear in original array
    }
};