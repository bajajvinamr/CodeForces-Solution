#include <bits/stdc++.h>
using namespace std;
int a[16];
int f[16][1 << 15 | 1], g[16][1 << 15 | 1], sum[1 << 15 | 1];
vector<int> x, y;
int main() {
	int t;
	scanf("%d", &t);
	while(t --) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i ++)
		            scanf("%d", &a[i]);
		int o = n;
		vector<int> ff[16];
		for (int i = 0; i < (1 << n); i ++) {
			// printf("push %d\n", i);
			ff[__builtin_popcount(i)].push_back(i);
		}
		// for(int ss = 0; ss < n; ss ++)
		//     printf("size %d\n", (int)ff[ss].size());
		for (int ss = 0; ss < n; ss ++)
		            for (int ii = 0; ii < (int)ff[ss].size(); ii ++) {
			int s = ff[ss][ii];
			x.clear();
			y.clear();
			y.push_back(0);
			for (int i = 0; i < n; i ++)
			                    if(s >> i & 1)
			                        x.push_back(i); else
			                        y.push_back(i);
			int n = y.size() - 1, m = x.size();
			for (int i = 0; i < (1 << m); i ++)
			                    for (int j = sum[i] = 0; j < m; j ++)
			                        if(i >> j & 1)
			                            sum[i] += a[x[j]];
			for (int i = 0; i < (1 << m); i ++)
			                    f[0][i] = INT_MAX;
			f[0][0] = 0;
			for (int i = 1; i <= n; i ++) {
				for (int j = 0; j < (1 << m); j ++) {
					f[i][j] = INT_MAX;
					if(a[y[i]] > f[i - 1][j]) {
						f[i][j] = a[y[i]];
						g[i][j] = 0;
					} else {
						for (int k = j; k; k = j & (k - 1))
						                                if(a[y[i]] + sum[k] > f[i - 1][j ^ k]) {
							if(a[y[i]] + sum[k] < f[i][j]) {
								f[i][j] = a[y[i]] + sum[k];
								g[i][j] = k;
							}
						}
					}
				}
			}
			if(f[n][(1 << m) - 1] != INT_MAX) {
				// printf("fetch %d %d\n", ss, s);
				o = ss;
				goto out;
			}
		}
		out:
		        printf("%d\n", o);
		int cc = (1 << x.size()) - 1;
		vector<int> out[16];
		for (int i = y.size() - 1; i >= 1; i --) {
			for (int j = 0; j < x.size(); j ++)
			                if(g[i][cc] >> j & 1) {
				// printf("pushed");
				out[y[i]].push_back(x[j]);
			}
			// printf("used %d\n", g[i][cc]);
			cc ^= g[i][cc];
		}
		int p[16];
		for (int i = 0; i < n; i ++)
		            p[i] = i;
		for (int i = 1; i < y.size(); i ++) {
			for (int j = 0; j < out[y[i]].size(); j ++) {
				printf("%d %d\n", p[out[y[i]][j]] + 1, p[y[i]] + 1);
				for (int k = out[y[i]][j]; k < n; k ++)
				                    p[k] --;
			}
		}
	}
	return 0;
}
