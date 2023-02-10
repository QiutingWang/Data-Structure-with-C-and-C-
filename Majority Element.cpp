#include <iostream>
using namespace std;
//////////////////////////
/////Majority Element/////
// Majority: >n/2 frequency
//////LeetCode No.169 https://leetcode.com/problems/majority-element/
/// Approach1: Brute-Force
  // pick one element, then traverse from left to right, count its occurrence repeatedly.If the occurrence of element>n/2, return the element. 
  // We only have one majority element
  // T=O(n^2), S=O(1)
/// Approach2: Hashmap
  // store the element:count with <key,value> pair format, iterate the array and fill the hashmap.If the occurrence of element>n/2, return the element. 
  // T=O(n), S=O(n)
/// Approach3: Sorting
  // After sorting, the elements with the same value gather together.
  // Find the midpoint element at index n/2, which is our majority element.
  // T=O(nlogn), S=O(1)
/// Approach4: Moore's Voting(the best one)
  // mark the majority element by +1, on the other hand, the rest of element will be marked as -1
  // if the selected value is majority element, the final sum result will be positive.
  // T=O(n), S=O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=nums[0];
        int count=1;

        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==candidate){
                count++;
            }else{
                count--;
                if(count==0){ //update the candidate
                    candidate=nums[i];
                    count=1;
                }
            }
        }
        //We cannot assume the majority element is exist
        int count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==candidate){
                count2++;
            }
        }
        if(count2>n/2) return candidate;//the majority element is there
        else return -1; //majority element doesn't exist.

        return candidate;
    }
};
