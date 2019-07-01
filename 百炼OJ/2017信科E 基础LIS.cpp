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
const int maxn = 1005;
const int inf = 0x3f3f3f3f;

// 题目链接：http://bailian.openjudge.cn/xly2017/E/
// 提交链接：http://jsrgzx.openjudge.cn/dynamic1/06/

int n;
int a[maxn];
int dp[maxn];

int lis1() {
	int ans = 0;
	for(int i = 1; i <= n; i++) dp[i] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			if(a[j] >= a[i]) dp[i] = max(dp[i], dp[j]+1);
		}
		ans = max(ans, dp[i]);
	}
	// for(int i = 1; i <= n; i++) cout << dp[i] << ' '; cout << endl;
	return ans;
}

int lis2() {
	int ans = 0;
	for(int i = 1; i <= n; i++) dp[i] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			if(a[j] <= a[i]) dp[i] = max(dp[i], dp[j]+1);
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 0; i <= n; i++) dp[i] = 1;
		// cout << lis1() << endl;
		// cout << lis2() << endl;
		cout << max(lis1(), lis2()) << endl;
	}
	return 0;
}