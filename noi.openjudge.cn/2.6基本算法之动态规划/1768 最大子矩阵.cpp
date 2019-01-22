#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 105;

int n;
int a[maxn][maxn], sum[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

int main() {
    while(~scanf("%d", &n)) {
        memset(sum, 0, sizeof sum);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
                sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= i; k++) {
                    for(int l = 1; l <= j; l++) {
                        ans = max(ans, sum[i][j]-sum[i][l-1]-sum[k-1][j]+sum[k-1][l-1]);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}