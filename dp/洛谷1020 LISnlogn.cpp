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

ll n, x, a[maxn], dp[maxn];

int main() {
	n = 0;
	while(scanf("%lld", &a[++n]) == 1);
	n--;
	// cin >> n; for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	ll m = 1; memset(dp, inf, sizeof dp); dp[1] = a[1];
	for(int i = 2; i <= n; i++) {
		if(dp[m] >= a[i]) dp[++m] = a[i];
		else {
			ll l = 0, r = m;
			while(l < r) {
				ll mid = (l+r) >> 1;
				if(dp[mid] >= a[i]) l = mid+1;
				else r = mid;
			}
			dp[l] = a[i];
		}
	}
	cout << m << endl;
	m = 1; memset(dp, -1, sizeof dp); dp[1] = a[1];
	for(int i = 2; i <= n; i++) {
		if(dp[m] < a[i]) dp[++m] = a[i];
		else {
			ll l = 0, r = m;
			while(l < r) {
				ll mid = (l+r) >> 1;
				if(dp[mid] >= a[i]) r = mid;
				else l = mid+1;
			}
			dp[l] = a[i];
		}
	}
	cout << m << endl;
	return 0;
}