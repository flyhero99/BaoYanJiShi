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

int n, a[maxn], dp1[maxn], dp2[maxn];

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		dp1[i] = 1;
		for(int j = 1; j < i; j++)
			if(a[i] > a[j]) dp1[i] = max(dp1[i], dp1[j]+1);
	}
	for(int i = n; i >= 1; i--) {
		dp2[i] = 1;
		for(int j = i+1; j <= n; j++)
			if(a[i] > a[j]) dp2[i] = max(dp2[i], dp2[j]+1);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, dp1[i]+dp2[i]-1);
	// for(int i = 1; i <= n; i++) cout << dp1[i] << ' '; cout << endl;
	// for(int i = 1; i <= n; i++) cout << dp2[i] << ' '; cout << endl;
	// cout << "ans: " << ans << endl;
	cout << n-ans << endl;
	return 0;
}	