#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 100005;
typedef long long ll;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0'; ch = getchar(); }
    return x*f;
}

inline ll readll() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0';  ch = getchar(); }
    return x*f;
}

int main() {
    for(int n; ~scanf("%d", &n) && n; ) {
        double ans = 1.0*inf, v, t;
        for(int i = 1; i <= n; i++) {
            scanf("%lf %lf", &v, &t);
            if(t >= 0) {
                t = t + 45*360/v;
                ans = min(ans, t);
            }
        }
        printf("%d\n", ans > (int)ans ? (int)(ans+1) : (int)ans);
    }
    return 0;
}