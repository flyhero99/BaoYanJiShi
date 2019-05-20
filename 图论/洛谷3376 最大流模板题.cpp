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
const int maxn = 100005;
// const int maxm = 1005;
const int inf = 0x3f3f3f3f;

int n, m, s, t;

struct Edge {
    int to, cap, rev;
};

vector<Edge> vec[maxn];
bool vis[maxn];

void addEdge(int u, int v, int cap) {
    vec[u].push_back((Edge) {v, cap, vec[v].size()});
    vec[v].push_back((Edge) {u, 0, vec[u].size()-1});
}

int dfs(int u, int f) {
    if(u == t) return f;
    vis[u] = true;
    for(int i = 0; i < vec[u].size(); i++) {
        Edge &e = vec[u][i];
        // int v = vec[u][i].v, cap = vec[u][i].cap, rev = vec[u][i].rev;
        if(!vis[e.to] && e.cap > 0) {
            int d = dfs(e.to, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                vec[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxFlow() {
    int flow = 0;
    for( ; ; ) {
        memset(vis, 0, sizeof vis);
        int f = dfs(s, inf);
        if(f == 0) return flow;
        flow += f;
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(int i = 1; i <= m; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    int ans = maxFlow();
    cout << ans << endl;
    return 0;
}