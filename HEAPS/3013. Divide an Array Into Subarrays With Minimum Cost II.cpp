//problem link : https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/
//Time Complexity: O(n log k)
//Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int,int> PII;
    typedef long long ll;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        
        set<PII> KMinElements;
        set<PII> remaining;

        int i=1;
        ll sum = 0;

        //create window
        while(i-dist < 1){
            KMinElements.insert({nums[i],i});
            sum += nums[i];

            if(KMinElements.size()>k-1){
                PII temp = *KMinElements.rbegin();
                sum -= temp.first;
                KMinElements.erase(temp);
                remaining.insert(temp);
            }
            i++;
        }

        ll result = LONG_MAX;
        while(i<n){
            KMinElements.insert({nums[i],i});
            sum += nums[i];

            if(KMinElements.size()>k-1){
                PII temp = *KMinElements.rbegin();
                sum -= temp.first;
                KMinElements.erase(temp);
                remaining.insert(temp);
            }

            result = min(result,sum);

            PII remove = {nums[i-dist],i-dist};
            if(KMinElements.count(remove)){
                KMinElements.erase(remove);
                sum -= remove.first;

                if(remaining.size() > 0){
                    PII temp = *remaining.begin();
                    sum += temp.first;
                    KMinElements.insert(temp);
                    remaining.erase(temp);
                }
            }else{
                remaining.erase(remove);
            }
            i++;
        }

        return nums[0] + result;
    }
};