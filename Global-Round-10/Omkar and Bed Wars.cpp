#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
// #define mp make_pair
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repp(i,a,b) for(int i = a; i <= b; i++)
#define endl '\n'
#define mod 1000000007
#define mod_in(a) bin(a, mod - 2)
#define ncr(n, r) (n >= r ? ((ft[n] * mod_in((ft[r] * ft[(n)-(r)]) % mod)) % mod) : (int)0)
#define pi 3.14159265358979323
#define INF 1e15
#define lb(v, a) lower_bound(v.begin(), v.end(), a)
#define ub(v, a) upper_bound(v.begin(), v.end(), a)

int power(int x, int n){
    int res=1;
    while(n>0){
        if(n&1)
            res=res*x;
        x*=x;
        n>>=1;
    }
    return res;
}

int bin(int x, int n){
    int res=1; x%=mod;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res%mod;
}
// vector<int> ft;

// int ncr(int n, int r){
//     if(n>=r){
//         return (ft[n] * mod_in((ft[r] * ft[(n)-(r)]) % mod)) % mod;
//     }
//     else return 0;
// }

bool prime(int n){
    if(n==3)return 1;
    repp(i,2,sqrt(n)){
        if(n%i==0)return 0;
    }
    return 1;
}
    

// vector<int> pr(2000005, 1), xx[2000005];
// void sieve(int n){ 
//     for(int p=2; p<n; p++){ 
//         if(pr[p]){ 
//             for(int i=p; i<n; i += p){
//                 pr[i]=0;
//                 xx[i].pb(p);
//             }
//         } 
//     } 
// }  


void solve(){
    int n, f=0, ans=0, c=1; cin>>n;
    string s; cin>>s;
    vector<int> vv;
    rep(i,0,n-1){
        if(s[i]==s[i+1])c++;
        else{
            f=1;
            vv.pb(c);
            c=1;
        }
    }
    if(s[0]!=s[n-1]) vv.pb(c);
    else if(vv.size()) vv[0] += c;
    if(f==0){
        cout<<1 + (n-1)/3<<endl;
        return;
    }
    else{
        rep(i,0,vv.size()){
            ans += vv[i]/3;
        }
        cout<<ans<<endl;
    }
}

signed main(){
    fast
    // ft.pb(1);
    // rep(i,1,2000005) ft.pb((ft[i-1]*i)%mod);
    int t=1;
    cin>>t;
    while(t--) solve();
}
