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
const int maxn = 30005;

struct Edge {
    int v, w, next;
} e[200005];

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
    stack<int> q; q.push(st); // 不知道为什么..这里用queue就会T...看网上博客改成stack就过了...很迷..
    while(!q.empty()) {
        int u = q.top(); q.pop();
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
    while(~scanf("%d %d", &n, &m)) {
        num = 0; memset(head, -1, sizeof head);
        int u, v, w;
        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            addEdge(u, v, w);
        }
        spfa(1);
        printf("%d\n", dis[n]);
    }
    return 0;
}