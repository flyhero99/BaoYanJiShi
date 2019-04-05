#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 1005;
typedef long long ll;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0'; ch = getchar(); }
    return x*f;
}

int dp[maxn][maxn];

int main() {
    int t = read();
    while(t--) {
        int n = read();
        memset(dp, inf, sizeof dp);
        for(int i = 1; i <= n; i++) {
            int m = read();
            for(int j = 1; j <= m; j++) {
                int b = read(), p = read();
                if(i == 1) dp[i][b] = min(dp[i][b], p);
                else {
                    for(int k = 1; k <= maxn; k++) {
                        if(dp[i-1][k] != inf) {
                            if(k < b) dp[i][k] = min(dp[i][k], dp[i-1][k]+p);
                            else dp[i][b] = min(dp[i][b], dp[i-1][k]+p);
                        }
                    }
                }
            }
        }
        double maxx = -inf*1.0;
        for(int k = 1; k <= maxn; k++) {
            if(dp[n][k] != inf) {
                maxx = max(maxx, (double)k / (double)dp[n][k]);
            }
        }
        printf("%.3f\n", maxx);
    }
    return 0;
}