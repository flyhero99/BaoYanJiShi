#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1000005;
const int inf = 0x3f3f3f3f;

int n, m, pre[maxn], rel[maxn];

void init() {
	for(int i = 0; i <= n; i++) {
		pre[i] = i; rel[i] = 0;
	}
}

int Find(int x) {
	if(x == pre[x]) return x;
	int t = pre[x];
	pre[x] = Find(pre[x]);
	rel[x] = (rel[x] + rel[t]) % 3;
	return pre[x];
}

bool Merge(int d, int x, int y) {
	int fx = Find(x), fy = Find(y);
	if(fx == fy) {
		int ans1 = (rel[x] - rel[y] + 3 + d-1) % 3;
		if(ans1 != 0) return false;
	}
	else {
		pre[fy] = fx;
		rel[fy] = (rel[x] - rel[y] + d-1 + 3) % 3;
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	init();
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		int d, x, y;
		scanf("%d %d %d", &d, &x, &y);
		if(x > n || y > n) {
			ans++;
			continue;
		}
		else if(d == 2 && x == y) {
			ans++;
			continue;
		}
		bool flag = Merge(d, x, y);
		if(!flag) {
			// cout << d << " " << x << ' ' << y << endl;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}