// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

typedef long long int ll;
#define endl '\n'
#define ld long double
#define all(a) a.begin(),a.end()
#define int long long
#define pb push_back
#define pii pair <int, int>
#define ff first
#define ss second
#define sz(v) (int)v.size() 
#define UB upper_bound
#define LB lower_bound
#define OST tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>

const int INF = 1e15 + 0;
const int mod = 1e9 + 7;
//const int mod = 998244353;

set <pii> s;

void solve() {
    int n, k, x, steps = 1;
    pii p;
    cin >> n >> k;
    int data[n+5], C[k+5];
    vector <int> ans[n+5];

    for(int i = 1; i <= n; i++) {
       int x; cin >> x;
       data[i] = x;
    }

    for(int i = 1; i <= k; i++) {
        int x; cin >> x;
        C[i] = x;
    }

    sort(data + 1, data + n + 1);
    
    int left = C[1]; ans[0].pb(data[n]); s.insert({1,0});
   
    for(int i = n-1; i >= 1; i--) {
        x = C[data[i]];
        p = *(s.begin());
        auto it = s.begin();

        if(p.ff >= x) {
            s.insert({1,steps}); ans[steps].pb(data[i]); steps++;
        }
        else {
            s.erase(it);
            s.insert({p.ff+1,p.ss});
            ans[p.ss].pb(data[i]);
        }
    }
    cout << steps << endl;
    
    for(int i = 0; i < steps; i++) {
        cout << sz(ans[i]) << " ";
        for(auto l : ans[i]) cout << l << " ";
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
    int t = 1; // cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}    
