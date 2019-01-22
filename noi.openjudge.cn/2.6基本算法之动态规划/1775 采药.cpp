#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 1005;

int T, M;
int t[maxn], v[maxn];
int dp[maxn];

void zeroOnePack() {
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < M; i++) {
        for(int j = T; j >= t[i]; j--) {
            dp[j] = max(dp[j], dp[j-t[i]]+v[i]);
        }
    }
}

void completePack() {
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < M; i++) {
        for(int j = t[i]; j <= T; j++) {
            dp[j] = max(dp[j], dp[j+t[i]]+v[i]);
        }
    }
}

int main() {
    while(~scanf("%d %d", &T, &M)) {
        for(int i = 0; i < M; i++) scanf("%d %d", &t[i], &v[i]);
        zeroOnePack();
        cout << dp[T] << endl;
    }
    return 0;
}