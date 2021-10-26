#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define mod 1000000007
#define pi 3.14159265358979323846

int bin(int x, int n){
    int res = 1; x %= mod;
    while(n){
        if(n&1) res = (res*x) % mod;
        x = (x*x) % mod;
        n >>= 1;
    }
    return res;
}

void solve(){
    
}

signed main(){
    fast
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}