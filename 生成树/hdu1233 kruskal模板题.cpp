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
#define inf 0x7fffffff
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 10005;

int pre[105];

int Find(int x) {
    if(x == pre[x]) return x;
    int t = pre[x];
    pre[x] = Find(pre[x]);
    return pre[x];
}

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator < (const Edge &r) const {
        return w < r.w;
    }
} e[maxn];

int main() {
    int n;
    while(~scanf("%d", &n) && n) {
        memset(e, 0, sizeof e);
        for(int i = 0; i <= n; i++) pre[i] = i;
        int m = (n-1)*n/2;
        for(int i = 1; i <= m; i++) {
            int x, y, z; scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
        }
        sort(e+1, e+m+1);
        ll sum = 0;
        int cnt = 0;
        for(int i = 1; i <= m; i++) {
            int fa = Find(e[i].u), fb = Find(e[i].v);
            // cout << "fa: " << fa << " fb: " << fb << endl;
            if(fa == fb) continue;
            sum += e[i].w;
            pre[fa] = fb;
            cnt++;
            if(cnt == n-1) break;
        }
        printf("%lld\n", sum);
    }
    return 0;
}