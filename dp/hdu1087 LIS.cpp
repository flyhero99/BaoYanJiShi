#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 400005;
const int inf = 0x3f3f3f3f;

int n;

int a[maxn], dp[maxn];

int main() {
    while(~scanf("%d", &n) && n) {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        memset(dp, 0, sizeof dp);
        int ans = -1;
        for(int i = 1; i <= n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(a[i] > a[j]) dp[i] = max(dp[i], dp[j]+a[i]);
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}