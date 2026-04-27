// Problem Link: https://leetcode.com/problems/range-sum-query-mutable/description/
// Solution: Square Root Decomposition
// Time Complexity: O(Q*sqrt(n)) for both update and sumRange
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    int n;
    int blockSize;
    vector<int> blocks;
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        blockSize = ceil(sqrt(n));

        blocks.resize(blockSize,0);
        for(int i=0;i<n;i++){
            int blockIdx = i/blockSize;
            blocks[blockIdx] += nums[i];
        }
    }
    
    void update(int index, int val) {
        int blockIdx = index/blockSize;

        blocks[blockIdx] -= nums[index];
        blocks[blockIdx] += val;

        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;

        int startBlock = left/blockSize;
        int endBlock = right/blockSize;

        if(startBlock == endBlock){
            for(int i=left;i<=right;i++)sum += nums[i];
            return sum;
        }

        int endOfStartBlock = (startBlock+1)*blockSize-1;
        int startOfEndBlock = endBlock*blockSize;

        for(int i=left;i<=endOfStartBlock;i++)sum += nums[i];

        for(int i=startBlock+1;i<endBlock;i++)sum += blocks[i];

        for(int i=startOfEndBlock;i<=right;i++)sum += nums[i];

        return sum;
    }
};
