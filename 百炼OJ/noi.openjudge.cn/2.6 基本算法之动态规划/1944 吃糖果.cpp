#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 205;

int dp[maxn];

int main() {
    int n; cin >> n;
    memset(dp, 0, sizeof dp);
    dp[0] = 1; dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout << dp[n] << endl;
    return 0;
}