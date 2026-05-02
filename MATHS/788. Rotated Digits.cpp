// Problem Link : https://leetcode.com/problems/rotated-digits/
// Time Complexity : O(n)
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool mirroredNumber(int n){
        return n == 2 || n == 5 || n == 9 || n == 6;
    }
    bool noChangeNumber(int n){
        return n == 0 || n == 1 || n == 8;
    }
    bool goodNumber(int n){
        int mirroredNumbers = 0;
        int sameNumbers = 0;
        int invalidNumbers = 0;
        while(n > 0){
            int a = n%10;
            if(mirroredNumber(a))mirroredNumbers++;
            else if(noChangeNumber(a))sameNumbers++;
            else invalidNumbers++;
            n /= 10;
        }

        if(invalidNumbers > 0 || mirroredNumbers == 0)return false;
        return true;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1;i<=n;i++){
            if(goodNumber(i))count++;
        }

        return count;
    }
};