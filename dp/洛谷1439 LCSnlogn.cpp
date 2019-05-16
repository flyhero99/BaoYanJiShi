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

const int maxn = 100005;

int n, a[maxn], b[maxn], dp[maxn];

int main() {
	scanf("%d", &n);
	// for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	// for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	// memset(dp, 0, sizeof dp);
	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 1; j <= n; j++) {
	// 		if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
	// 		else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	// 	}
	// }
	// cout << dp[n][n] << endl;
	int x;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		a[x] = i;
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		b[i] = a[x];
	}
	int m = 1;
	dp[1] = b[1];
	for(int i = 2; i <= n; i++) {
		if(b[i] > dp[m]) dp[++m] = b[i];
		else {
			int t = lower_bound(dp+1, dp+m+1, b[i]) - dp;
			dp[t] = b[i];
		}
	}
	cout << m << endl;
	return 0;
}