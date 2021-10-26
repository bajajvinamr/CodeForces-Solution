#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <algorithm>
typedef long long ll;
using namespace std;
 
const int INF = int(1e9);
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	//ifstream fin; fin.open("input.txt");
	//ofstream fout; fout.open("output.txt");
 
	ll a, b, c, d, ans = 0;
	cin >> a >> b >> c >> d;
	for (ll z = a; z <= b; ++z) {
		int miii = max(d-z+1, c);
		if (miii > c)
			miii = 0;
		else
			miii = c - miii + 1;
		ans += (b - a + 1)*miii;
		for (ll y = b; y <= min(z - a, c); ++y) {
			// z < x + y
			// z - x > y
			// - x > y - z
			// x > z - y
			ll minx = z - y + 1; // минимальная сторона
			minx = max(minx, a);
			if (minx > b)
				minx = 0;
			else
				minx = b - minx + 1;
			ans += minx;
		}
	}
	cout << ans;
	return 0;
}