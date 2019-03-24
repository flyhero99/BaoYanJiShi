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

struct Edge {
    int u, v;
    double r, c;
} e[maxn];

int n, m, st;
double stv;
double dis[maxn];
bool vis[maxn];

bool bellman_ford(int st) {
    for(int i = 1; i <= n; i++) dis[i] = 0;
    dis[st] = stv;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 2*m; j++) { // 松弛每条边
            if(dis[e[j].v] < (dis[e[j].u] - e[j].c) * e[j].r)
                dis[e[j].v] = (dis[e[j].u] - e[j].c) * e[j].r;
        }
    }
    for(int j = 0; j < 2*m; j++) {
        if(dis[e[j].v] < (dis[e[j].u] - e[j].c) * e[j].r)
            return 1;
    }
    return 0;
}

int main() {
    while(~scanf("%d %d %d %lf", &n, &m, &st, &stv)) {
        for(int i = 1; i <= 2*m; i += 2) {
            scanf("%d %d %lf %lf %lf %lf", &e[i].u, &e[i].v, &e[i].r, &e[i].c, &e[i+1].r, &e[i+1].c);
            e[i+1].u = e[i].v;
            e[i+1].v = e[i].u;
        }
        if(bellman_ford(st)) puts("YES");
        else puts("NO");
    }
    return 0;
}