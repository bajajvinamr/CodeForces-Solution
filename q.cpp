#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repp(i,a,b) for(int i = a; i <= b; i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mod 998244353
#define mod_in(a) bin(a, mod - 2)
#define fact(n) rep(i, 1, n+1) ft.pb((ft[i-1] * i) % mod)
#define ncr(n, r) (n >= r ? ((ft[n] * mod_in((ft[r] * ft[(n)-(r)]) % mod)) % mod) : 0LL)
#define pi 3.14159265358979323
#define INF 1e15
#define lb(v, a) lower_bound(v.begin(), v.end(), a)
#define ub(v, a) upper_bound(v.begin(), v.end(), a) 
#define deb(x) cerr<<#x<<" "<<x<<endl;  
 
//  Ordered Set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// template<typename T>
// using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
// #define os_find(k) find_by_order(k)
// #define os_order(k) order_of_key(k)
// //(**FOR USING ORDERED SET CHANGE INT**)
 
 
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
    return res;
}
 
bool prime(int n){
    if(n==3)return 1;
    repp(i,2,sqrt(n)){
        if(n%i==0)return 0;
    }
    return 1;
}

//DSU
void make_set(int u){
    par[u] = u;
    sz[u] = 1;
}

int find_set(int u){
    if(u == par[u]) return u;
    return par[u] = find_set(par[u]);
}

void union_set(int u, int v){
    int a = find_set(u);
    int b = find_set(v);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

// Sieve
vector<int> pr(1000005, 1);

void sieve(int n){ 
    pr[1] = 0; pr[0] = 0;
    for(int p = 2; p <= n; p++){ 
        if(pr[p] == 1){ 
            for(int i = p * p; i <= n; i += p){
                pr[i] = 0;
            }
        } 
    } 
}  

int arr[200001], p[200001], h[200001], ans[200001], val[200001];
int dp[200001][100];
vector<int> adj[200001];

void dfs(int n, int l, int p){
    h[n] = l;
    dp[n][0] = p;
    for(auto i : adj[n]){
        if(i != p){
            dfs(i, l + 1, n);
        }
    }
}

void lca1(int n, int k){
    repp(i, 1, k){
        rep(j, 2, n + 1){
            if(dp[j][i-1] != -1) dp[j][i] = dp[dp[j][i-1]][i-1];   
        }
    }
}

int lca(int x, int y, int k){
    if(h[x] > h[y]) swap(x, y);
    int d = h[y] - h[x];
    while(d){
        int f = log2(d);
        y = dp[y][f];
        d -= (1 << f);
    }
    if(y == x) return y;
    for(int i = k; i >= 0; i--){
        if(dp[x][i] != -1 && (dp[x][i] != dp[y][i])) x = dp[x][i], y = dp[y][i];
    }
    return dp[x][0];
}

void solve(){
    int n, q, c = 0;; cin >> n >> q;
    memset(dp, -1, sizeof(dp));
    rep(i, 0, n - 1){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0, -1);
    int k = log2(n); 
    lca1(n, k);
    while(q--){
        int x, y; cin >> x >> y;
        int node = lca(x, y, k);
        if(node == x or node == y) cout << abs(h[x] - h[y]) << endl;
        else cout << h[x] + h[y] - 2 * h[node] << endl;
    }
}
