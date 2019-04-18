#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#define fi first
#define se second
#define MAXN 99
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int inf = 0x3f3f3f3f;
const int maxn = 505; // maximum value of n


int n, m;
int dp[100][100];
int d[100];

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= n; i++) scanf("%d", &d[i]);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dp[i-1][0];
            for(int j = 1; j <= m; j++) {
                if(i >= j) dp[i][0] = max(dp[i][0], dp[i-j][j]);
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+d[i]);
            }
        }
        cout << dp[n][0] << endl;
    }
    return 0;
}