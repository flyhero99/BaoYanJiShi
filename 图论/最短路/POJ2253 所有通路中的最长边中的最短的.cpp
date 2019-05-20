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
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;

const int inf = 0x3f3f3f3f;
const int maxn = 305;

pdd a[maxn];

int n, st, ed;
double mp[maxn][maxn];
double dis[maxn]; // dis[i]表示到达i点路上最短的最长边
bool vis[maxn];

void dijk() {
    for(int i = 1; i <= n; i++) {
        vis[i] = 0; dis[i] = mp[st][i];
    }
    double minn;
    int v;
    for(int i = 1; i <= n; i++) {
        minn = inf;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && dis[j] < minn) {
                v = j;
                minn = dis[j];
            }
        }
        vis[v] = 1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j]) {
                dis[j] = min(dis[j], max(dis[v], mp[v][j]));
            }
            if(!vis[j] && dis[j] > dis[v] + mp[v][j]) {
                dis[j] = dis[v] + mp[v][j];
            }
        }
    }
}

double distanc(pdd a, pdd b) {
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main() {
    int cnt = 0;
    while(~scanf("%d", &n) && n) {
        for(int i = 1; i <= n; i++) {
            double xx, yy;
            scanf("%lf %lf", &a[i].first, &a[i].second);

        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) mp[i][j] = 0.0;
                else mp[i][j] = mp[j][i] = distanc(a[i], a[j]);
            }
        }
        st = 1, ed = 2;
        dijk();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++cnt, dis[ed]);
    }
}