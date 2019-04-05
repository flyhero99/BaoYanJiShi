#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 505;

int main() {
    int m, n; cin >> m >> n;
    int dp[maxn][maxn]; memset(dp, 0, sizeof dp);
    dp[0][1] = 1;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    // for(int i = 1; i <= m; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[m][n] << endl;
    return 0;
}