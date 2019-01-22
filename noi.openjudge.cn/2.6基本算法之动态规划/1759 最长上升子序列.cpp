#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 1005;

int n;
int a[maxn];
int dp[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            dp[i] = 1;
        }
        int ans = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                if(a[i] > a[j]) dp[i] = max(dp[i], dp[j]+1);
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}