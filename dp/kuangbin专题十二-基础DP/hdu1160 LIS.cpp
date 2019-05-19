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

int n;
// int dp[maxn];

struct node {
	int w, s, id;
} ms[maxn];

struct node2 {
	// int val;
	deque<int> id;
} dp[maxn];

bool cmp(node a, node b) {
	return a.w < b.w;
}

int main() {
	n = 1;
	while(~scanf("%d %d", &ms[n].w, &ms[n].s)) { ms[n].id = n; n++; }
	n--;
	sort(ms+1, ms+1+n, cmp);
	// cout << "after: " << endl;
	// for(int i = 1; i <= n; i++) cout << ms[i].id << ": " << ms[i].w << " " << ms[i].s << endl;
	// cout << endl;
	int ans = 0, pos = 0;
	for(int i = 1; i <= n; i++) { dp[i].id.push_back(ms[i].id); }
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i-1; j++) {
			if(ms[i].s < ms[j].s && ms[i].w != ms[j].w) {
				if(dp[j].id.size() + 1 > dp[i].id.size()) {
					// dp[i].val = dp[j].val+1;
					dp[i].id = dp[j].id;
					dp[i].id.push_back(ms[i].id);
				}
				// dp[i].val = max(dp[i].val, dp[j].val+1);
				// dp[i].id.push_front(ms[j].id);
			}
		}
		int t = dp[i].id.size();
		if(ans < t) { ans = t; pos = i; }
	}
	cout << dp[pos].id.size() << endl;
	for(int i = 0; i < dp[pos].id.size(); i++) cout << dp[pos].id[i] << endl;
	return 0;
}
