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

struct node {
    int x, id;

    bool operator < (const node &rhs) const {
        return x > rhs.x;
    }
} a[maxn];

int ans1[maxn], ans2[maxn];

int main() {
    int n = read(), c = read();
    int l = 1;
    for(int i = 1; i <= c; i++) {
        a[i].x = read(); a[i].id = i;
    }
    sort(a+1, a+1+c);
    // for(int i = 1; i <= c; i++) cout << a[i].x << ' '; cout << endl;
    for(int i = 1; i <= n/2; i++) {
        ans1[i] = a[l].id;
        a[l].x--;
        if(!a[l].x) l++;
    }
    for(int i = 1; i <= n/2; i++) {
        ans2[i] = a[l].id;
        a[l].x--;
        printf("%d %d\n", ans1[i], ans2[i]);
        if(!a[l].x) l++;
    }
    return 0;
}