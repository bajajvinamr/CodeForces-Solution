#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define quickie ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rep(i, a, b) for(int i=a; i<b; i++)
#define rep1(i, a, b) for(int i=a; i<=b; i++)
#define repp(i, a, b) for(int i=b-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define db double
#define mi map<int, int>
#define vi vector<int>
#define qi queue<int>
#define MI(x) power(x, mod-2)
#define test int t; cin >> t;
#define all(a) a.begin(),a.end()
#define mod 998244353 
#define pi 3.141592653589
#define fact(n) rep(i, 1, n+1)ft.insert((ft[i-1]*i)%mod) ;
int power(int x, int y) ;
int gcd(int a, int b) ;

// #include <ext/insert_ds/assoc_container.hpp>
// #include <ext/insert_ds/tree_policy.hpp>
// using namespace __gnu_insertds;
// template<typename T>
// using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// template<typename T>
// using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//(*****FOR USING ORDERED SET CHANGE INT*******)

// struct chash {
//     const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
//     static unsigned long long hash_f(unsigned long long x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
//     int operator()(int x) const { return hash_f(x)^RANDOM; }
// };

int power(int x, int y) ;
int gcd(int a,int b) ; 

signed main() {
    quickie
    int n ;
    cin >> n ;
    int a[n] ;
    rep(i, 0, n) {
        cin >> a[i] ;
    }
    vector<pair<int, int>> two, three, ans ;
    int cx = 1 ;
    rep(i, 0, n) {
        if(a[i] == 3) {
            if(three.size()) {
                int y = three.size() ;
                y-- ;
                int uu = three[y].fi ;
                ans.pb({three[y].fi-1, three[y].se}) ;
                ans.pb({three[y].fi-1, i+1}) ;
                three.pop_back() ;
                three.pb({uu+1, i+1}) ;
                cx = max(cx, uu+2) ;
            }
            else {
                cx++ ;
                three.pb({cx, i+1}) ;
            }
        }
        else if(a[i] == 2) {
            if(three.size()) {
                int y = three.size() ;
                y-- ;
                ans.pb({three[y].fi-1, three[y].se}) ;
                ans.pb({three[y].fi-1, i+1}) ;
                two.pb({three[y].fi, i+1}) ;
                cx = max(cx, three[y].fi+1) ;
                three.pop_back() ;
            }
            else {
                two.pb({cx, i+1}) ;
                cx++ ;
            }
        }
        else if(a[i] == 1) {
            if(two.size()) {
                int y = two.size() ;
                y-- ;
                ans.pb({two[y].fi, two[y].se}) ;
                ans.pb({two[y].fi, i+1}) ;
                two.pop_back() ;
            }
            else if(three.size()) {
                int y = three.size() ;
                y-- ;
                ans.pb({three[y].fi-1, three[y].se}) ;
                ans.pb({three[y].fi-1, i+1}) ;
                ans.pb({three[y].fi, i+1}) ;
                cx = max(cx, three[y].fi+1) ;
                three.pop_back() ;
            }
            else {
                ans.pb({cx, i+1}) ;
                cx++ ;
            }
        }
    }
    if(three.size() + two.size() != 0) {
        cout << -1 << "\n" ;
        return 0 ;
    }
    cout << ans.size() << "\n" ;
    for(auto i : ans) {
        cout << i.fi << " " << i.se << "\n" ;
    }
}

int power(int x, int y) {
    int res = 1; x %= mod;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res%mod;
}

int gcd(int a,int b) {
    if(a==0) return b;
    return gcd(b%a,a);
}

