#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 405;

// 题意：开始时有1000加元。给出每天1美元到加元的汇率，每次兑换要付3%的手续费，并且所有钱舍去美分后面的部分。问n天之后最多有多少加元
// f[i][0]表示第i天最多有多少美元，f[i][1]表示第i天最多有多少加元，然后用f[i-1]递推即可。

double cut(double x) {
    int a = floor(x*100); // 只保留两位小数
    return (double) a/100.0;
}

int main() {
    int n;
    while(~scanf("%d", &n) && n) {
        double dp[maxn][maxn];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 0, dp[0][1] = 1000.00;
        for(int i = 1; i <= n; i++) {
            double rate; cin >> rate;
            dp[i][0] = max(dp[i-1][0], cut(dp[i-1][1]*0.97/rate));
            dp[i][1] = max(dp[i-1][1], cut(dp[i-1][0]*0.97*rate));
        }
        printf("%0.2lf\n", dp[n][1]);
    }
    return 0;
}