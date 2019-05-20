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
const int maxn = 1005;

struct Edge {
    int v, w, next;
} e[maxn*maxn];

int n, m, q, num;
int weight[maxn], dis[maxn], cnt[maxn], head[maxn];
bool vis[maxn];
bool cir[maxn]; // 记录该点是否为负环上的点

void dfs(int u) { // 每次检测到出现负环时，利用dfs，将该负环上的点全部标记
    cir[u] = true;
    for(int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        if(!cir[v]) dfs(v);
    }
}

void spfa(int st) {
    for(int i = 0; i <= n; i++) {
        dis[i] = inf; cnt[i] = 0; vis[i] = 0; cir[i] = 0;
    }
    dis[st] = 0; cnt[st] = 1; vis[st] = true;
    queue<int> q; q.push(st);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].v, c = e[i].w;
            if(cir[v]) continue;
            if(dis[v] > dis[u]+c) {
                dis[v] = dis[u]+c;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    if(++cnt[v] > n) {
                        dfs(v);
                    }
                }
            }
        }
    }
}

int diff(int x, int y) {
    return (y-x)*(y-x)*(y-x);
}

void addEdge(int u, int v, int w) {
    e[num].v = v;
    e[num].w = w;
    e[num].next = head[u];
    head[u] = num++;
}

int main() {
    int t; scanf("%d", &t);
    for(int ncase = 1; ncase <= t; ncase++) {
        memset(head, -1, sizeof head);
        num = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &weight[i]);
        scanf("%d", &m);
        int u, v;
        for(int i = 1; i <= m; i++) {
            scanf("%d %d", &u, &v);
            addEdge(u, v, diff(weight[u], weight[v]));
        }
        spfa(1);
        printf("Case %d:\n", ncase);
        scanf("%d", &q);
        int x;
        while(q--) {
            scanf("%d", &x);
            if(cir[x] || dis[x] < 3 || dis[x] == inf)
                puts("?");
            else
                printf("%d\n", dis[x]);
        }
    }
    return 0;
}