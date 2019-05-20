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
const double inf = 0x3f3f3f3f;
const int maxn = 305;

int cas = 1, T;

struct Node {
    double x, y;
}node[maxn];

double dist(Node a, Node b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int n;
bool vis[maxn];
double d[maxn];
double mapp[maxn][maxn];

void dijkstra(int s) {
    for(int i = 1; i <= n; i++)
        d[i] = inf;
    memset(vis, 0, sizeof(vis));
    d[s] = 0;
    for(int i = 1; i <= n; i++) {
        int u = 0;
        double mins = inf;
        for(int j = 1; j <= n; j++)
           if(!vis[j] && d[j] < mins) {
               mins = d[j];
               u = j;
           }
        if(u == 0)
            break;
        vis[u] = 1;
        for(int j = 1; j <= n; j++)
            if(!vis[j] && d[j] > d[u]+mapp[u][j])
                d[j] = d[u]+mapp[u][j];
    }
}

int main() {
    double walk = 10000.0 / 60;
    double sub = 40000.0 / 60;
    while(scanf("%lf %lf %lf %lf", &node[1].x, &node[1].y, &node[2].x, &node[2].y) == 4) {
        n = 2;
        int cnt = 3;
        int x, y;
        memset(mapp, 0, sizeof(mapp));
        for(int i = 1; i <= 300; i++)
            for(int j = 1; j <= 300; j++) {
                if(i == j)
                    mapp[i][j] = 0;
                else
                    mapp[i][j] = inf;
            }
        while(scanf("%d %d", &x, &y) == 2) {
            if(x == -1 && y == -1) {
                cnt = n+1;
                continue;
            }
            n++;
            node[n].x = x;
            node[n].y = y;
            if(n != cnt) // 只有相邻站点才能到达
                mapp[n][n-1] = mapp[n-1][n] = min(mapp[n][n-1], dist(node[n], node[n-1])/sub);
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                mapp[i][j] = min(mapp[i][j], dist(node[i], node[j])/walk);
        dijkstra(1);
        printf("%d\n", (int)(d[2]+0.5));
    }
    return 0;
}