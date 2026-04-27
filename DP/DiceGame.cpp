#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const int K = 6;

vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B){
    vector<vector<ll>> C(K,vector<ll>(K,0));

    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            for(int k=0;k<K;k++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j])%MOD;
            }
        }
    }

    return C;
}
vector<vector<ll>> power(vector<vector<ll>> A,int n){
    vector<vector<ll>> result(K,vector<ll>(K,0));

    for(int i=0;i<K;i++)result[i][i] = 1;

    while(n > 0){
        if(n&1) result = multiply(result,A);
        A = multiply(A,A);
        n>>=1;
    }
    return result;
}

int main(){
    int n;
    cin>>n;

    vector<ll> dp = {1,1,2,4,8,16};
    
    if(n < 6){
        cout<<dp[n];
        return 0;
    }
    vector<vector<ll>> M = {
        {1,1,1,1,1,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0},
    };

    M = power(M,n-5);

    ll ans = 0;
    for(int i=0;i<6;i++){
        ans = (ans + (M[0][i]*dp[5-i]))%MOD;
    }

    cout<<ans;
    return 0;
}

// f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6)
// f(1) = 1