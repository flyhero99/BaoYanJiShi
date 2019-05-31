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
const int maxn = 40005;
// const int maxm = 1005;
const int inf = 0x3f3f3f3f;

struct Edge {
    int v, w, nxt;
} e[maxn*2];

int n, q, num;
int pre[maxn], head[maxn], dis[maxn], ans[maxn];
bool vis[maxn];
vector<int> vec[maxn], no[maxn];

void init() {
    num = 0;
    memset(vis, 0, sizeof vis);
    // memset(dis, inf, sizeof dis);
    memset(head, -1, sizeof head);
    for(int i = 0; i <= n; i++) {
        pre[i] = i;
        vec[i].clear();
    }
}

int Find(int x) {
    if(pre[x] == x) return x;
    return pre[x] = Find(pre[x]);
}

void merge(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if(fx != fy) pre[fy] = fx;
}

void addEdge(int u, int v, int w) {
    e[num].v = v; e[num].w = w; e[num].nxt = head[u]; head[u] = num++;
    swap(u, v);
    e[num].v = v; e[num].w = w; e[num].nxt = head[u]; head[u] = num++;
}

void tarjan(int u) {
    // cout << "u: " << u << endl;
    vis[u] = 1;
    for(int i = head[u]; ~i; i = e[i].nxt) {
        int v = e[i].v, w = e[i].w;
        if(!vis[v]) {
            dis[v] = dis[u] + w;
            tarjan(v);
            merge(u, v);
        }
    }
    for(int i = 0; i < vec[u].size(); i++) {
        int v = vec[u][i];
        if(vis[v]) {
            ans[no[u][i]] = dis[u] + dis[v] - 2*dis[Find(v)];
            // cout << "LCA(" << u << ", " << v << "): " << Find(v) << endl;
        }
    }
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &q);
        init();
        int u, v, w;
        for(int i = 1; i <= n-1; i++) {
            scanf("%d %d %d", &u, &v, &w);
            addEdge(u, v, w);
        }
        for(int i = 1; i <= q; i++) {
            scanf("%d %d", &u, &v);
            vec[u].push_back(v);
            vec[v].push_back(u);
            no[u].push_back(i);
            no[v].push_back(i);
        }
        dis[1] = 0;
        tarjan(1);
        for(int i = 1; i <= q; i++) cout << ans[i] << endl;
    }
    return 0;
}