#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,int> mp;
    mp[1] = 10;
    if(mp[1] > 0){
        cout<<"hello"<<endl;
    }
    for(auto it:mp){
        cout<<it.first<<" "<<it.second;
    }
}