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
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 10005;

// spfa
// struct Edge {
//     int v, c;
//     Edge() {}
//     Edge(int v, int c) : v(v), c(c) {}
// };

// vector<Edge> vec[maxn];
// int n, m, st;
// int dis[maxn], cnt[maxn];
// bool vis[maxn]; // 这里的vis表示的是在不在队列中

// bool spfa(int st) {
//     for(int i = 0; i <= n; i++) {
//         dis[i] = inf; vis[i] = 0;
//     }
//     dis[st] = 0; vis[st] = true; cnt[st] = 1;
//     queue<int> q; q.push(st);
//     while(!q.empty()) {
//         int u = q.front(); q.pop();
//         vis[u] = false;
//         for(int i = 0; i < vec[u].size(); i++) {
//             int v = vec[u][i].v, c = vec[u][i].c;
//             if(dis[v] > dis[u]+c) {
//                 dis[v] = dis[u]+c;
//                 if(!vis[v]) {
//                     vis[v] = true;
//                     q.push(v);
//                     if(++cnt[v] > n) return false; // v结点的距离被更新了n次，说明存在负权回路
//                 }
//             }
//         }
//     }
//     return true;
// }

// dijk-heap
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
int n, m, st, ed;
int dis[maxn];
bool vis[maxn];

void dijk(int st) {
    for(int i = 0; i <= n; i++) {
        dis[i] = inf; vis[i] = 0;
    }
    dis[st] = 0;
    priority_queue<qnode> q; q.push(qnode(st, 0));
    qnode tmp;
    while(!q.empty()) {
        tmp = q.top(); q.pop();
        int u = tmp.v;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i].s, c = vec[u][i].c;
            if(vis[v]) continue;
            if(dis[v] > dis[u]+c) {
                dis[v] = dis[u] + c;
                q.push(qnode(v, dis[v]));
            }
        }
    }
}

void addEdge(int u, int v, int w) {
    vec[u].push_back(Edge(v, w));
    vec[v].push_back(Edge(u, w));
}


// 更新：虽然题目数据有重边，之前以为只能改为用矩阵存图，今日发现直接将重边push进邻接表即可，
// 更新时会自动采用更短的边。因此还可以用邻接表+堆优化的dijk。
int main() {
    while(scanf("%d %d", &m, &n) != EOF) { // 注意是先m后n！！！！
        for(int i = 0; i <= n; i++) vec[i].clear();
        int u, v, w;
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            addEdge(u, v, w);
        }
        dijk(1);
        printf("%d\n", dis[n]);
    }
    return 0;
}