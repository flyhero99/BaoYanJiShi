#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 105;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int a[maxn][maxn], dp[maxn][maxn];
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}