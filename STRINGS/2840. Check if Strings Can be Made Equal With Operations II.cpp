// Problem Link : https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(NLOGN)
// Space Complexity: O(N)
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s3 = "";
        string s4 = "";
        string s5 = "";
        string s6 = "";

        int n = s1.size();
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                s3 += s1[i];
                s5 += s2[i];
            }else{
                s4 += s1[i];
                s6 += s2[i];
            }
        }

        sort(s3.begin(),s3.end());
        sort(s4.begin(),s4.end());
        sort(s5.begin(),s5.end());
        sort(s6.begin(),s6.end());

        return s3 == s5 && s4 == s6;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};

        int n = s1.size();
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                freq1[s1[i]-'a']++;
                freq1[s2[i]-'a']--;
            }else{
                freq2[s1[i]-'a']++;
                freq2[s2[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++){
            if(freq1[i] != 0 || freq2[i] != 0)return false;
        }

        return true;
    }
};