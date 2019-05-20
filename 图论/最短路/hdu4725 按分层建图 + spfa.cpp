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
const int maxn = 200010;

struct Edge {
    int v, w, next;
} e[200010*20];

int n, m, k, num;
int dis[maxn], cnt[maxn], head[maxn];
bool vis[maxn];
int layer[maxn];

bool spfa(int st) {
    for(int i = 0; i <= 2*n; i++) {
        dis[i] = inf; cnt[i] = 0; vis[i] = 0;
    }
    dis[st] = 0; cnt[st] = 1; vis[st] = true;
    queue<int> q; q.push(st);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].v, c = e[i].w;
            if(dis[v] > dis[u]+c) {
                dis[v] = dis[u]+c;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    if(++cnt[v] > n) return false;
                }
            }
        }
    }
    return true;
}

void addEdge(int u, int v, int w) {
    e[num].v = v;
    e[num].w = w;
    e[num].next = head[u];
    head[u] = num++;
}

// 这题难点在于建图。每个节点属于一个层，跑最短路的时候可能跨层，所以把层也当作节点，
// 层与所属节点间的花费是0，转移到相邻层的花费是1.

int main() {
    int t; scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++) {
        memset(head, -1, sizeof head);
        memset(vis, 0, sizeof vis);
        num = 0;
        scanf("%d %d %d", &n, &m, &k);
        int x;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &x);
            layer[i] = x;
            vis[x] = 1;
        }
        for(int i = 1; i < n; i++) { // 将层抽象成下标从n+1开始到2n+1的点，建边
            if(vis[i] && vis[i+1]) {
                addEdge(i+n, i+n+1, k);
                addEdge(i+n+1, i+n, k);
            }
        }
        for(int i = 1; i <= n; i++) {
            addEdge(n+layer[i], i, 0);
            //add(edge,head,i,n+layer[i],0);  有多个节点对应一个层的情况，大概。。。
            if(layer[i] > 1)
                addEdge(i, n+layer[i]-1, k);
            if(layer[i] < n)
                addEdge(i, n+layer[i]+1, k);
        }
        int u, v, w;
        for(int i = 1; i <= m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        spfa(1);
        printf("Case #%d: %d\n", cas, dis[n] == inf ? -1 : dis[n]);
    }
    return 0;
}