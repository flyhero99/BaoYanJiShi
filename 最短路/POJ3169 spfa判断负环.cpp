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

int n, m, k, num;
int weight[maxn], dis[maxn], cnt[maxn], head[maxn];
bool vis[maxn];

bool spfa(int st) {
    for(int i = 0; i <= n; i++) {
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

int main() {
    while(~scanf("%d %d %d", &n, &m, &k)) {
        num = 0;
        memset(head, -1, sizeof head);
        int a, b, c;
        for(int i = 1; i <= m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            addEdge(a, b, c);
        }
        for(int i = 1; i <= k; i++) {
            scanf("%d %d %d", &a, &b, &c);
            addEdge(b, a, -c);
        }
        if(spfa(1) == false) {
            cout << "-1" << endl;
        }
        else if(dis[n] == inf) {
            cout << "-2" << endl;
        }
        else {
            cout << dis[n] << endl;
        }
    }
    return 0;
}