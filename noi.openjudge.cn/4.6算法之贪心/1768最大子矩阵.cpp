#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
typedef long long ll;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0'; ch = getchar(); }
    return x*f;
}

int n;
int sum[maxn][maxn], a[maxn][maxn];

int main() {
    n = read();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] = read();
            sum[i][j] = a[i][j]-sum[i-1][j-1]+sum[i][j-1]+sum[i-1][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= i; k++) {
                for(int l = 1; l <= j; l++) {
                    ans = max(ans, sum[i][j]+sum[k-1][l-1]-sum[i][l-1]-sum[k-1][j]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}