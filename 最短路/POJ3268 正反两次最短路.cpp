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
const int maxn = 1005;

int n, m, x;

int g[maxn][maxn];
int dis[maxn], dis2[maxn];
bool vis[maxn];

void init() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                g[i][j] = 0;
            else
                g[i][j] = inf;
        }
    }
}

void change() {
    int g2[maxn][maxn];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            g2[i][j] = g[i][j];
        }
    }
    init();
    for(int i = 1; i <= n; i++) {
        dis2[i] = dis[i];
        for(int j = 1; j <= n; j++) {
            g[i][j] = g2[j][i];
        }
    }
}

struct cmp {
    bool operator () (pii a, pii b) {
        return a.fi > b.fi; // 注意：C++的pq默认大根堆
    }
};

void print(priority_queue<pii, vector<pii>, cmp> q) {
    pii tmp;
    cout << "current in queue: ";
    while(!q.empty()) {
        tmp = q.top(); q.pop();
        cout << tmp.se << ' ';
    }
    cout << endl;
}

void dijk(int st) {
    int minn, v;
    for(int i = 1; i <= n; i++) {
        dis[i] = inf; vis[i] = 0;
    }
    priority_queue<pii, vector<pii>, cmp> q;
    dis[st] = 0;
    q.push(make_pair(0, st)); // second表示v, first表示dis[v]
    while(!q.empty()) {
        pii tmp = q.top(); q.pop();
        int u = tmp.se, c = tmp.fi;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 1; i <= n; i++) {
            if(g[u][i] != inf) {
                if(!vis[i] && dis[i] > c+g[u][i]) {
                    dis[i] = c+g[u][i];
                    q.push(make_pair(dis[i], i));
                }
            }
        }
    }
}

int main() {
    while(~scanf("%d %d %d", &n, &m, &x)) {
        int u, v, w;
        init();
        for(int i = 1; i <= m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            g[u][v] = w;
        }
        dijk(x);
        change();
        dijk(x);
        int maxx = -1;
        for(int i = 1; i <= n; i++) {
            if(maxx < dis[i]+dis2[i])
                maxx = dis[i]+dis2[i];
        }
        cout << maxx << endl;
    }
    return 0;
}