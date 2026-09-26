#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElementToLeft(vector<int>& arr){
    int n = arr.size();
    stack<int> st; // storing index
    vector<int> result(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(!st.empty()){
            result[i] = arr[st.top()];
        }
        st.push(i);
    }
    return result;
}
int main(){
    vector<int> arr = {4, 2, 5, 1, 3};
    vector<int> result = nextSmallerElementToLeft(arr);
    for(auto x : result){
        cout<<x<<" ";
    }
}