#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 1005;
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

int n;

int work(int a[], int b[]) {
    int ans = 0;
    int l1 = 1, l2 = 1, r1 = n, r2 = n;
    while(l1 <= r1 && l2 <= r2) {
        if(b[r2] > a[r1]) { r2--; r1--; ans += 3; }
        else if(b[l2] > a[l1]) { l2++; l1++; ans += 3; }
        else if(b[l2] == a[r1]) { l2++; r1--; ans += 2; }
        else { l2++; r1--; ans += 1; }
    }
    return ans;
}

int main() {
    while(~scanf("%d", &n) && n) {
        int c[maxn], s[maxn];
        for(int i = 1; i <= n; i++) c[i] = read();
        for(int i = 1; i <= n; i++) s[i] = read();
        sort(c+1, c+n+1);
        sort(s+1, s+n+1);
        // cout << work(c, s) << ' ' << work(s, c);
        printf("%d %d\n", work(c, s), 4*n-work(s, c));
    }
    return 0;
}