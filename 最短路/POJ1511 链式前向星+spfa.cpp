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
const int maxn = 1000005;

struct Edge {
    int to, w, next;
} e[maxn];

int n, m, ecnt;
int head[maxn];
ll dis[maxn];
int cnt[maxn];
bool vis[maxn];
int a[maxn][3]; // 将边存起来，因为要调换
ll sum;

void addEdge(int u, int v, int w) {
    e[ecnt].to = v;
    e[ecnt].w = w;
    e[ecnt].next = head[u];
    head[u] = ecnt++;
}

bool spfa(int st) {
    memset(dis, inf, sizeof dis);
    memset(vis, 0, sizeof vis);
    memset(cnt, 0, sizeof cnt);
    dis[st] = 0; vis[st] = true; cnt[st] = 0;
    queue<int> q; q.push(st);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = e[i].next) { // mark：链式前向星遍历边
            int v = e[i].to, c = e[i].w;
            if(dis[v] > (ll) c + dis[u]) {
                dis[v] = (ll) c + dis[u];
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    if(++cnt[v] > n) return 0;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
        sum = (ll) dis[i] + sum;
    return 1;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        sum = 0;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++)
            scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);

        ecnt = 0;
        memset(head, -1, sizeof head); memset(e, 0, sizeof e);
        for(int i = 1; i <= m; i++) addEdge(a[i][0], a[i][1], a[i][2]);
        spfa(1); // 正着跑一次

        ecnt = 0;
        memset(head, -1, sizeof head); memset(e, 0, sizeof e);
        for(int i = 1; i <= m; i++) addEdge(a[i][1], a[i][0], a[i][2]);
        spfa(1); // 反着跑一次
        printf("%lld\n", sum);
    }
    return 0;
}