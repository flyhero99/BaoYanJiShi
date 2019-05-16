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

int n, a[maxn], dp[maxn];

// n^2做法，dp[i]表示前i个元素的LIS，转移方程为：dp[i] = max(dp[i], dp[j]+1) (当a[i]>a[j]时)
int LISn2() {
	int maxx = 1;
	for(int i = 2; i <= n; i++) {
		dp[i] = 1;
		for(int j = 1; j < i; j++)
			if(a[i] > a[j]) dp[i] = max(dp[i], dp[j]+1);
		maxx = max(maxx, dp[i]);
	}
	return maxx;
}

// nlogn做法，利用贪心思想，若想让序列尽可能长，则应该让LIS最后一位尽可能小，这样就更有可能在后面找到更大的元素使序列变得更长
// dp[i]表示长度为i的LIS的最后一位数，初始化为inf，越后面的元素dp[i]应该越小
// 如果当前元素比LIS最后一位大，直接延长；否则二分查找到此时a[i]应该更新到的元素
int LISnlogn() {
	memset(dp, -1, sizeof dp);
	int cnt = 1;
	dp[1] = a[1];
	for(int i = 2; i <= n; i++) {
		if(a[i] > dp[cnt]) dp[++cnt] = a[i];
		else {
			int l = 0, r = cnt;
			while(l < r) {
				int mid = (l+r) >> 1;
				if(dp[mid] > a[i])
					r = mid;
				else l = mid+1;
			}
			dp[l] = a[i];
		}
	}
	return cnt;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = LISnlogn();
	cout << ans << endl;
	for(int i = 1; i <= ans; i++) cout << dp[i] << ' '; cout << endl;
	return 0;
}