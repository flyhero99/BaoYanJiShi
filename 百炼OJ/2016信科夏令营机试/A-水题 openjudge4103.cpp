#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 100005;

int main() {
    for(int n; ~scanf("%d", &n); ) {
        int dp[30][3];
        memset(dp, 0, sizeof dp);
        dp[1][0] = dp[1][1] = dp[1][2] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i][0] = dp[i-1][0] + dp[i-1][2];
            dp[i][1] = dp[i-1][1] + dp[i-1][2];
            dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        }
        printf("%d\n", dp[n][0]+dp[n][1]+dp[n][2]);
    }
    return 0;
}