#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 50005;

// int a[maxn];
//int dp[3][maxn];

// dp[1][j]表示将前j个元素分为1个以a[j]结尾的连续子串，dp[2][j]表示将前j个元素分为2个以a[j]为结尾的连续字串
// dp[1][j] = max(dp[1][j-1], 0) + a[j];
// dp[2][j] = max(dp[2][j-1], max(dp[1][0], dp[1][1], ..., dp[1][j-1]) ) + a[j];
// 由于其连续性，可将dp数组简化为一个变量。

int main() {
    int t; cin >> t;
    while(t--) {
        int n; scanf("%d", &n);
        int a; scanf("%d", &a);
        int dp1 = a; // 相当于dp[1]
        int dp2 = a; // 相当于dp[2]
        int max_dp1 = -inf;
        int ans = -inf;
        for(int i = 1; i < n; i++) {
            scanf("%d", &a);
            dp1 = max(dp1, 0) + a; // 相当于dp[1][i] = max(dp[1][i-1], 0) + a;
            dp2 = max(dp2, max_dp1) + a; // 相当于dp[2][i] = max(dp[2][i-1], max_dp1) + a;
            max_dp1 = max(max_dp1, dp1); // 更新max_dp1, 这里的dp1就相当于之前版本刚更新过的dp[1][i]
            ans = max(ans, dp2);
        }
        printf("%d\n", ans);
    }
    return 0;
}