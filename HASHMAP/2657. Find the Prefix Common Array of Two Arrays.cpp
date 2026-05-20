// Problem Link : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        
        vector<int> hashmap(n+1,0);
        vector<int> C(n,0);

        C[0] = A[0] == B[0];
        hashmap[A[0]]--;
        hashmap[B[0]]++;

        for(int i=1;i<n;i++){
            C[i] = C[i-1];

            if(hashmap[A[i]] > 0) C[i]++;
            hashmap[A[i]]--;

            if(hashmap[B[i]] < 0) C[i]++;
            hashmap[B[i]]++;
        }
        return C;
    }
};