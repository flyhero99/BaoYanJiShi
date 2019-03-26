#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 1115;

pii a[maxn];

int n, d;
int pre[maxn];
int vis[maxn];

int dis(int i, int j) {
    return (int) (a[i].fi-a[j].fi)*(a[i].fi-a[j].fi) + (a[i].se-a[j].se)*(a[i].se-a[j].se);
}

void init() {
    for(int i = 0; i <= n; i++) {
        pre[i] = i; vis[i] = 0;
    }
}

int Find(int x) {
    if(pre[x] == x) return x;
    return pre[x] = Find(pre[x]);
}

void join(int a, int b) {
    int fa = Find(a), fb = Find(b);
    if(fa == fb) return;
    pre[fb] = fa;
}

int main() {
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(~scanf("%d %d", &n, &d)) {
        init();
        for(int i = 1; i <= n; i++) {
            int x, y; scanf("%d %d", &x, &y);
            a[i] = make_pair(x, y);
        }
        char s[3];
        while(~scanf("%s", s)) {
            if(s[0] == 'O') {
                int x; scanf("%d", &x);
                vis[x] = 1;
                for(int i = 1; i <= n; i++) {
                    if(vis[i] && dis(i, x) <= d*d) {
                        join(i, x);
                    }
                }
                // for(int j = 1; j <= n; j++) cout << Find(j) << ' '; cout << endl;
            }
            else if(s[0] == 'S') {
                int x, y; cin >> x >> y;
                // cout << "babax: " << Find(x) << " babay: " << Find(y) << endl;
                if(Find(x) == Find(y)) cout << "SUCCESS" << endl;
                else cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}