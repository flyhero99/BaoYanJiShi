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
#define inf 0x3f3f3f3f
#define infll 0x7fffffff
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1005;

int n, m, e;
int match[maxn];
bool vis[maxn];

vector<int> vec[maxn];

bool dfs(int u) {
	for(int i = 0; i < vec[u].size(); i++) {
		int v = vec[u][i];
		if(vis[v]) continue;
		vis[v] = true;
		if(!match[v] || dfs(match[v])) {
			match[v] = u;
			// match[u] = v;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d %d", &n, &m, &e);
	for(int i = 1; i <= e; i++) {
		int u, v; scanf("%d %d", &u, &v);
		if(u > m || v > m) continue;
		vec[u].push_back(v);
		// vec[v].push_back(u);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		if(dfs(i)) ans++;
	}
	cout << ans << endl;
	return 0;
}