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
const int maxn = 5005;

int n, m, w, cnt, dis[maxn], head[maxn];

// 链式前向星存图。next表示同起点的下一条边在head中的位置；head[u]表示以u为起点的第一条（最后一条）边在数组中的位置（倒序）。
struct Edge {
    int u, v, w, next;
} e[maxn];

bool bellman_ford(int st) {
    for(int i = 0; i <= n; i++) dis[i] = inf;
    dis[1] = 0;
    for(int i = 0; i < n; i++) { // 松弛n次
        for(int j = 0; j < cnt; j++) { // 遍历每一条边
            if(dis[e[j].v] > dis[e[j].u]+e[j].w)
                dis[e[j].v] = dis[e[j].u] + e[j].w;
        }
    }
    for(int j = 0; j < cnt; j++) {
        if(dis[e[j].v] > dis[e[j].u]+e[j].w) // 如果还能松弛，说明有负环
            return 0;
    }
    return 1;
}

void addEdge(int u, int v, int w) {
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

/*
链式前向星一般遍历方法：
for(int i = head[u]; ~i; i = edge[i].next)
*/

int main() {
    int t, a, b, c;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &m, &w);
        cnt = 0;
        memset(head, -1, sizeof head);
        for(int i = 1; i <= m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            addEdge(a, b, c);
            addEdge(b, a, c);
        }
        for(int i = 1; i <= w; i++) {
            scanf("%d %d %d", &a, &b, &c);
            addEdge(a, b, -c);
        }
        printf("%s\n", bellman_ford(1) ? "NO" : "YES");
    }
    return 0;
}