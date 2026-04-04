//Problem Link : https://leetcode.com/problems/decode-the-slanted-ciphertext/
//Time Complexity: O(N)
//Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int m = n/rows;

        string ans = "";
        for(int k=0;k<m;k++){
            int i=0;
            int j=k;
            while(i<rows && j<m){
                ans += encodedText[i*m + j];
                i++;
                j++;
            }
        }

        n  = ans.size()-1;
        while(n>0){
            if(ans[n] == ' ')n--;
            else break;
        }
        return ans.substr(0,n+1);
    }
};