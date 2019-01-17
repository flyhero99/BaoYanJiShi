#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
typedef long long ll;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0'; ch = getchar(); }
    return x*f;
}

struct dd {
    int n, v;

    bool operator < (const dd &rhs) const {
        return v*rhs.n > n*rhs.v;
    }
}a[maxn];

int main() {
    int t = read();
    while(t--) {
        int w = read(), s = read();
        for(int i = 1; i <= s; i++) {
            a[i].n = read(); a[i].v = read();
        }
        sort(a+1, a+s+1);
        double sum = 0.0;
        for(int i = 1; i <= s; i++) {
            if(w == 0) break;
            if(a[i].n >= w) {
                sum += (double)w * a[i].v/a[i].n;
                w = 0;
            }
            else {
                sum += a[i].v;
                w -= a[i].n;
            }
        }
        printf("%.2f\n", sum);
    }
    return 0;
}