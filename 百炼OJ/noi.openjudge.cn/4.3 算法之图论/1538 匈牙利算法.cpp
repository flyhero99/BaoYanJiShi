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
#define MAXN 99
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;

int n, m, s, v;

pdd gpos[maxn], hpos[maxn];
int match[maxn];
int g[maxn][maxn];
bool vis[maxn];

bool dfs(int x) {
    for(int j = 1; j <= m; j++) {
        if(g[x][j] == 1 && !vis[j]) {
            vis[j] = 1;
            if(match[j] == 0 || dfs(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

double dis2(pdd a, pdd b) {
    return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}

void addEdge(int u, int v) {
    g[u][v] = 1;
}

int main() {
    while(~scanf("%d %d %d %d", &n, &m, &s, &v)) {
        memset(g, 0, sizeof g);
        memset(gpos, 0, sizeof gpos);
        memset(hpos, 0, sizeof hpos);
        memset(match, 0, sizeof match);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                g[i][j] = 0;
        for(int i = 1; i <= n; i++) scanf("%lf %lf", &gpos[i].fi, &gpos[i].se);
        for(int i = 1; i <= m; i++) scanf("%lf %lf", &hpos[i].fi, &hpos[i].se);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if((double) 1.0*s*v*s*v >= dis2(gpos[i], hpos[j]))
                    addEdge(i, j);
            }
        }
        // for(int i = 1; i <= m; i++) {
        //     int x, y; scanf("%d %d", &x, &y);
        //     addEdge(x, y);
        // }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            memset(vis, 0, sizeof vis);
            if(dfs(i)) ans++;
        }
        printf("%d\n", n-ans);
        // for(int i = 1; i <= n; i++) printf("%d -> %d\n", i, match[i]);
    }
    return 0;
}