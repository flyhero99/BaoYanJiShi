#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 505;
const int maxm = 10005;
const int inf = 0x3f3f3f3f;

// dp方程：f[i][m] = max(f[i-1][m], f[i-1][m-c[i]]+v[i])
// 表示 搜索到第i件物品时 容量恰好为m时的价值。
// 第i件物品放或不放。不放：遍历到第i件物品相当于什么都没做。
// 放：相当于在遍历了前i-1种商品后容量为m-c[i]，而放进这个容量为c[i]的物品后恰好转移到f[i][m]，且此时的价值是之前的基础上+v[i]。

int n;
int s[maxm], d[maxm], dp[maxm];

int main() {
    int t; cin >> t;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
        for(int i = 1; i <= n-1; i++) scanf("%d", &d[i]);
        memset(dp, inf, sizeof dp);
        dp[0] = 0; dp[1] = s[1];
        for(int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1]+s[i], dp[i-2]+d[i-1]);
        }
        // dp[n] = min(dp[n-1]+s[n], dp[n-2]+d[n-1]);
        cout << dp[n] << endl;
    }
}