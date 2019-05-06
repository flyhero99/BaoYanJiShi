#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
const int inf = 0x3f3f3f3f;

// dp[i][j]表示选取第j个数字的情况下，将前j个数字分成i组的最大子段和
// (1) (x1,y1), (x2,y2), ..., (xi,yi,num[j])
// (2) (x1,y1), (x2,y2), ..., (xi-1,yi-1), (num[j])
// dp[i][j] = max(dp[i][j-1], dp[i-1][k]) + num[j] (其中k=[i-1, j-1])
// 发现dp[i][]只和dp[i-1][], dp[i][]有关，可以滚动数组优化
// dp[t][j] = max(dp[t][j-1], dp[1-t][k]) + num[j] (t=0或1)
// 发现最终只想要max(dp[1-t][k]), 也就是上一状态的值，所以用一个一维数组就可以了
// dp[j] = max(dp[j-1], pre[j-1]) + num[j]

int m, n;
int a[maxn], dp[maxn], pre[maxn];

int main() {
	while(~scanf("%d %d", &m, &n)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		memset(dp, 0, sizeof dp);
		memset(pre, 0, sizeof pre);
		int ans = -inf;
		for(int i = 1; i <= m; i++) { // 控制分成m组
			ans = -inf; // 需要取出每组dp[i][j]的最大值，供下一轮dp[i+1]使用
			for(int j = i; j <= n; j++) {
				dp[j] = max(dp[j-1], pre[j-1]) + a[j];
				pre[j-1] = ans; // 更新pre的值，滚动到上一轮（dp[i-1]）
				ans = max(ans, dp[j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}