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

int n, m, c[maxn], v[maxn], dp[maxm];

int main() {
    int t; cin >> t;
    while(t--) {
        memset(c, 0, sizeof c);
        memset(v, 0, sizeof v);
        memset(dp, inf, sizeof dp);
        int x, y;
        scanf("%d %d", &x, &y);
        m = y-x;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &v[i], &c[i]);
        }
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = c[i]; j <= m; j++) {
                dp[j] = min(dp[j], dp[j-c[i]]+v[i]);
            }
        }
        if(dp[m] == inf) cout << "This is impossible." << endl;
        else cout << "The minimum amount of money in the piggy-bank is " << dp[m] << ".\n";
    }
    return 0;
}
