// meet in the middle is technique where the search space is divided into two equal parts
// a seperate search is perfromed for both the halves and inthe end results are combined.

#include<bits/stdc++.h>
using namespace std;

long long findSubsets(vector<int>& arr, int x){
    int n = arr.size();
    
    int n1 = n/2;
    int n2 = n - n1;
    int nums1 = (1<<n1);
    int nums2 = (1<<n2);
    vector<long long> firstHalf(nums1, 0);
    vector<long long> secondHalf(nums2, 0);
    for(int num = 0; num < nums1; num++){
        long long sum = 0;
        for(int i = 0; i < n1; i++){
            if(num & (1<<i)){
                sum += arr[i];
            }
        }
        firstHalf[num] = sum;
    }

    for(int num = 0; num < nums2; num++){
        long long sum = 0;
        for(int i = 0; i < n2; i++){
            if(num & (1<<i)){
                sum += arr[n1+i];
            }
        }
        secondHalf[num] = sum;
    }

    long long res = 0;
    // merge
    sort(secondHalf.begin(), secondHalf.end());
    for(auto num : firstHalf){
        long long target = x - num;
        int idx1 = lower_bound(secondHalf.begin(),secondHalf.end(), target) - secondHalf.begin();
        int idx2 = upper_bound(secondHalf.begin(), secondHalf.end(), target) - secondHalf.begin();
        res = res + 1LL*idx2 - idx1;
    }

    return res;
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout << findSubsets(arr,x);
}