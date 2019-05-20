#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 1005;

int g[maxn][maxn];

struct cmp {
    bool operator () (pii a, pii b) {
        return a.se < b.se;
    }
};

int n, m, st, ed;
int dis[maxn];
bool vis[maxn];

void dijk() {
    priority_queue<pii, vector<pii>, cmp> q;
    for(int i = 0; i <= n; i++) {
        vis[i] = 0; dis[i] = -1;
    }
    dis[st] = inf;
    q.push(make_pair(st, dis[st]));
    while(!q.empty()) {
        pii u = q.top(); q.pop();
        if(dis[u.fi] > u.se) continue;
        for(int i = 1; i <= n; i++) {
            if(g[u.fi][i] != -1) {
                int j = min(u.se, g[u.fi][i]);
                if(dis[i] == -1 || dis[i] < j) {
                    dis[i] = j;
                    q.push(make_pair(i, dis[i]));
                }
            }
        }
    }
}

int main() {
    int t;
    while(~scanf("%d", &t)) {
        for(int cas = 1; cas <= t; cas++) {
            memset(g, -1, sizeof g);
            scanf("%d %d", &n, &m);
            for(int i = 1; i <= m; i++) {
                int u, v, w;
                scanf("%d %d %d", &u, &v, &w);
                if(g[u][v] < w) g[u][v] = g[v][u] = w;
            }
            st = 1, ed = n;
            dijk();
            printf("Scenario #%d:\n%d\n\n", cas, dis[ed]);
        }
    }
}