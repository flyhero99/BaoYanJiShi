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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int inf = 0x3f3f3f3f;
const int maxn = 1000005;

struct qnode {
    int v, c;
    qnode() {}
    qnode(int v, int c) : v(v), c(c) {}
    bool operator < (const qnode &r) const {
        return c > r.c;
    }
};

struct Edge {
    int s, c;
    Edge() {}
    Edge(int s, int c) : s(s), c(c) {}
};

vector<Edge> vec[maxn];
int n, m;
ll sum;
ll dis[maxn];
bool vis[maxn];
int a[maxn][3];

// 时限是8s，这题用堆优化的dijk(nlogn) 和 链式前向星优化的spfa 都能过
// 堆优化dijk：5204 ms；链式前向星+spfa：2204 ms。

void dijk(int st) {
    for(int i = 0; i <= n; i++) {
        vis[i] = 0; dis[i] = inf;
    }
    dis[st] = 0;
    priority_queue<qnode> q;
    q.push(qnode(st, 0));
    while(!q.empty()) {
        qnode tmp = q.top(); q.pop();
        int u = tmp.v;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i].s, c = vec[u][i].c;
            if(dis[v] > (ll) c + dis[u]) {
                dis[v] = (ll) c + dis[u];
                q.push(qnode(v, dis[v]));
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        sum = (ll) dis[i] + sum;
    }
}

void addEdge(int uu, int vv, int ww) {
    vec[uu].push_back(Edge(vv, ww));
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        sum = 0;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++) {
            scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
        }
        for(int i = 0; i <= n; i++) vec[i].clear();
        for(int i = 1; i <= m; i++)
            addEdge(a[i][0], a[i][1], a[i][2]);
        dijk(1);

        for(int i = 0; i <= n; i++) vec[i].clear();
        for(int i = 1; i <= m; i++)
            addEdge(a[i][1], a[i][0], a[i][2]);
        dijk(1);
        printf("%lld\n", sum);
    }
    return 0;
}