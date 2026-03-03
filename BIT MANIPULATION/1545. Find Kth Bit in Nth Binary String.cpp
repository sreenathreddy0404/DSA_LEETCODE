// Problem link : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Using string generation
// Time complexity : O(N^2)
// Space complexity : O(2^N)
class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        int i=0;
        while(i<n){
            string temp = s;
            reverse(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++){
                temp[i] = ((1-(temp[i]-'0')) + '0');
            }
            s = s + "1" + temp;
            i++;
        }
        return s[k-1];
    }
};

// Approach 2 : Using recursion
// Time complexity : O(N)
// Space complexity : O(N)
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1)return '0';

        int len = (1 << n)-1;
        int mid = (len+1)/2;

        if(k == mid)return '1';
        if(k < mid)return findKthBit(n-1,k);

        int mirror = len-k+1;
        char bit = findKthBit(n-1,mirror);

        return (bit == '0')?'1':'0';
    }
};