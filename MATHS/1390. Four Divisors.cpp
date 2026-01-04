//problem link: https://leetcode.com/problems/four-divisors/
//Time Complexity: O(n * sqrt(m)) where n is size of nums and m is max element in nums
//Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;

        int n = nums.size();

        for(int i=0;i<n;i++){
            int num = nums[i];

            int sum = 1+num;
            int factors = 2;
            for(int j=2;j*j<=num;j++){
                if(num % j == 0){
                    sum += j;
                    sum += num/j;
                    if(j*j!=num)factors+=2;
                    else factors++;
                    if(factors>4){
                        break;
                    }
                }
            }

            if(factors == 4){
                res += sum;
            }
        }

        return res;
    }
};