#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;

int a[maxn][15], dp[maxn][15];

int main() {
	int n;
	while(~scanf("%d", &n) && n) {
		int x, t, minn = 0;
		memset(dp, 0, sizeof dp);
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &x, &t);
			minn = max(minn, t);
			dp[t][x]++;
		}
		int maxx = -inf;
		for(int i = minn-1; i >= 0; i--) {
			for(int j = 0; j <= 10; j++) {
				dp[i][j] += max(dp[i+1][j+1], max(dp[i+1][j], dp[i+1][j-1]));
			}
		}
		printf("%d\n", dp[0][5]);
	}
	return 0;
}