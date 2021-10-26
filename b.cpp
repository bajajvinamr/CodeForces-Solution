#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define mod 1000000007

int bin(int x, int n){
    int res=1; x%=mod;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}

int dp[19][2][75][2];

vector<int> v;
int k;

int fun(int ind, int f, int p, int sum, int f1){
    if(p > k) return 0;
    if(ind == v.size()){return 1;}
    if(dp[ind][f][sum][f1] != -1) return dp[ind][f][sum][f1];
    int ans = 0;
    if(f == 0){
        if(f1){
            for(int i = 0; i < v[ind]; i++){
                ans += fun(ind + 1, 1, p * i, sum + i, 1);
            }
            ans += fun(ind + 1, 0, p * v[ind], sum + v[ind], 1);
        }
        else{
            for(int idx = 0; idx < v[ind]; idx++){
                if(idx == 0){
                    ans += fun(ind + 1, 1, 1, sum + idx, 0);
                }
                else ans += fun(ind + 1, 1, p * idx, sum + idx, 1);
            }
            if(v[ind] != 0) ans += fun(ind + 1, 0, p * v[ind], sum + v[ind], 1);
            else ans += fun(ind + 1, 0, 1, sum + v[ind], 0);
        }
    }
    else{
        if(f1){
            for(int i = 0; i <= 9; i++){
                ans += fun(ind + 1, 1, p * i, sum + i, 1);
            }
        }
        else{
            for(int i = 0; i <= 9; i++){
                if(i == 0){
                    ans += fun(ind + 1, 1, 1, sum + i, 0);
                }
                else ans += fun(ind + 1, 1, p * i, sum + i, 1);
            }
            if(v[ind]) ans += fun(ind + 1, 1, p * v[ind], sum + v[ind], 1);
            else (ans += fun(ind + 1, 1, 1, sum + v[ind], 0));
        }
    }
    return dp[ind][f][sum][f1] = ans;
}

void solve(){
    int n; cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    int t = n;
    while(t){
        v.pb(t % 10);
        t /= 10;
    }
    reverse(v.begin(), v.end());
    cout << fun(0, 0, 1, 0, 0) - 1;
}

signed main(){
    fast
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
}