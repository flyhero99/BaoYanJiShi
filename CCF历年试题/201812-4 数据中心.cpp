#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#define fi first
#define se second
#define inf 0x7fffffff
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100005;

struct edge {
	int u, v;
	ll w;
	edge() {}
	edge(int u, int v, int w) : u(u), v(v), w(w) {}
	bool operator < (const edge &r) const {
		return w < r.w;
	}
} e[maxn];

int n, m, root;
ll pre[maxn];
vector<edge> res;

void init() {
	for(int i = 0; i <= n; i++) pre[i] = i;
}

int Find(int x) {
	if(x == pre[x]) return x;
	int t = pre[x];
	pre[x] = Find(pre[x]);
	return pre[x];
}

ll kruskal() {
	ll maxx = 0;
	int cnt = 0;
	sort(e+1, e+m+1);
	for(int i = 1; i <= m; i++) {
		int fu = Find(e[i].u), fv = Find(e[i].v);
		if(fu == fv) continue;
		pre[fv] = fu;
		// res.push_back(e[i]);
		maxx = max(maxx, e[i].w);
		if(++cnt == n-1) break;
	}
	return maxx;
}


int main() {
	scanf("%d %d %d", &n, &m, &root);
	init();
	for(int i = 1; i <= m; i++) {
		scanf("%d %d %lld", &e[i].u, &e[i].v, &e[i].w);
	}
	ll ans = kruskal();
	// for(int i = 0; i < res.size(); i++) printf("%d %d %d\n", res[i].u, res[i].v, res[i].w);
	printf("%lld\n", ans);
	return 0;
}