#include <bits/stdc++.h> 
#define int long long
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
#define mc map<char, int>
#define ms map<string, int>
#define vi vector<int>
#define qi queue<int>
#define MI(x) power(x, mod-2)
#define test int t; cin >> t;
//#define mod 1000000007LL
#define mod 998244353 
using namespace std;
int power(int x, int y) ;
int gcd(int a, int b) ;
#define pi 3.141592653589
const int lll = 39800;
vi t(4*lll);
vi ans;

void solve(int v, int tl, int tr)
{
	if(tl==tr) {
		t[v] = ans[tl];
	}
	else {
		int tm = (tl+tr)/2;
		solve(v*2,tl,tm);
		solve(v*2+1,tm+1,tr);
		t[v]=t[v*2]+t[v*2+1];
	}
}

int fun(int v, int tl, int tr, int l, int r)
{
	if(l>r)
		return 0;
	if(tl==l&&tr==r)
		return t[v];
	int tm = (tl+tr)/2;
	return fun(v*2,tl,tm,l,min(r,tm))+fun(v*2+1,tm+1,tr,max(l,tm+1),r);
}

signed main() {
    quickie 
    test
    while(t--) {
        int a, b, q ;
        cin >> a >> b >> q;
        int o = (a*b)/gcd(a, b) ;
        ans.assign(o, 0) ;
        rep(i, 0, o) {
            int m = (i%a)%b, mm = (i%b)%a ;
            if(m != mm)
                ans[i] = 1 ;
        }
        solve(1, 0, o-1) ;
        rep(i, 0, q) {
            int l, r ;
            cin >> l >> r ;
            int in = l%o, inn = r%o ;
            int v = fun(1, 0, o-1, (int)in, o-1) + fun(1 , 0, o-1, 0, (int)inn) ;
            int d = o-in, dd = inn+1 ;
            int dist = r-l-dd-d+1 ;
            v += (dist/o)*fun(1, 0, o-1, 0, o-1) ;
            cout << v << " " ;
        }
        cout << "\n" ;
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
 
int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
