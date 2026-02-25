// Problem Link : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description
// Time Complexity : O(nlogn) where n is the number of elements in the input array
// Space Complexity : O(n) where n is the number of elements in the input array

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int a,int b){
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            if(countA == countB)return a<b;
            return countA < countB;
        });

        return arr;
    }
};