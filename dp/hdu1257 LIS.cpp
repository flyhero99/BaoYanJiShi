#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
const int inf = 0x3f3f3f3f;

// 对于这个最长上升子序列而言，每一个数代表一个拦截系统的最小值，并且由于序列是上升的，
// 每一个数都不能再拦截序列中的下一个数，因为下一个数更大，因此这个子序列的长度就是拦截系统数。

int a[maxn], dp[maxn];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans = 1;
		for(int i =1; i <= n; i++) dp[i] = 1;
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				if(a[i] > a[j]) dp[i] = max(dp[i], dp[j]+1);
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}