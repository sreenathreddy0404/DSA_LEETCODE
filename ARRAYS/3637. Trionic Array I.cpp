// problem link : https://leetcode.com/problems/trionic-array-i/
// solution link : https://leetcode.com/problems/trionic-array-i/solutions/7547243/only-one-loop-solution-with-flag-variabl-g39y/
// Time Complexity: O(n)
// space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

//Approach 1
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        //increasing
        while(i<n-1 && nums[i] < nums[i+1])  i++;
        if(i == 0 || i == n-1)return false;

        //decreasing
        while(i<n-1 && nums[i] > nums[i+1]) i++;
        if(i == n-1)return false;

        //increasing
        while(i<n-1 && nums[i] < nums[i+1])i++;
        return i == n-1;
        
    }
};

//Approach 2
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool flag = true; //true -> increasing and false -> decreasing
        int count = 0; //should be exactly 3 at end
        if(nums[0] < nums[1])count++;
        else return false;

        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1] || count > 3)return false;
            if(flag && nums[i] > nums[i+1]){
                flag = false;
                count++;
            }else if(!flag && nums[i] < nums[i+1]){
                flag = true;
                count++;
            }
        }

        return count == 3;
    }
};