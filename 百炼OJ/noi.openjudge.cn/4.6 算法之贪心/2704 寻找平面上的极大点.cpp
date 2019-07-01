#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 10005;
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

vector<pii> vec, ans;

int main() {
    int n = read();
    for(int i = 0; i < n; i++) {
        pii x; x.fi = read(); x.se = read(); vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    // for(int i = 0; i < vec.size()-1; i++) {
    //     printf("(%d,%d),", vec[i].fi, vec[i].se);
    // }
    // printf("(%d,%d)\n", vec[vec.size()-1].fi, vec[vec.size()-1].se);
    int cnt = 1, maxy = vec[n-1].se; ans.push_back(vec[n-1]);
    for(int i = n-2; i >= 0; i--) {
        if(vec[i].se > maxy) {
            maxy = vec[i].se;
            ans.push_back(vec[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size()-1; i++) {
        printf("(%d,%d),", ans[i].fi, ans[i].se);
    }
    printf("(%d,%d)\n", ans[ans.size()-1].fi, ans[ans.size()-1].se);
    return 0;
}