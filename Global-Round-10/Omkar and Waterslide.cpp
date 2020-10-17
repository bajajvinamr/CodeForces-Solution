#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fffaasstt ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repp(i,a,b) for(int i = a; i <= b; i++)
#define mod 1000000007
#define mod_in(a) bin(a, mod - 2)
#define fact(n) rep(i, 1, n+1) ft.pb((ft[i-1] * i) % mod)
#define ncr(n, r) (n >= r ? ((ft[n] * mod_in((ft[r] * ft[(n)-(r)]) % mod)) % mod) : 0LL)
#define INF 1e15

signed main(){
    fffaasstt
    int t=1;
    cin>>t;
    while(t--){
        int n, mx, aa=0, ans=0; cin>>n;
    int a[n];
    rep(i,0,n) cin>>a[i];
    rep(i,0,n){
        if(i==0)mx=a[i];
        else{
            if(a[i] <a[i-1]){
                aa = max(aa, mx-a[i]);
            }
            else{
                ans += aa;
                aa =0;
                mx = a[i];
            }
        }
    }
    ans += aa;
    cout<<ans<<endl;
    }
}
