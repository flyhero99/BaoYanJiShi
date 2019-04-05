#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 1005;
typedef long long ll;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0'; ch = getchar(); }
    return x*f;
}

string a, b, t;
int len, ans = inf;

void flip(int i) {
    a[i] = a[i]=='1' ? '0' : '1';
    a[i-1] = a[i-1] == '1' ? '0' : '1';
    if(i+1 < len) a[i+1] = a[i+1] == '1' ? '0' : '1';
}

int main() {
    cin >> a >> b; t = a; len = a.length();
    int cnt1 = 0, cnt2 = 1;
    for(int i = 1; i < len; i++) {
        if(a[i-1] != b[i-1]) {
            cnt1++;
            flip(i);
        }
    }
    if(a == b) ans = min(ans, cnt1);
    a = t;
    a[0] = a[0] == '1' ? '0' : '1';
    a[1] = a[1] == '1' ? '0' : '1';
    for(int i = 1; i < len; i++) {
        if(a[i-1] != b[i-1]) {
            cnt2++;
            flip(i);
        }
    }
    if(a == b) ans = min(ans, cnt2);
    if(ans == inf) puts("impossible");
    else printf("%d\n", ans);
    return 0;
}