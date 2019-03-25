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
    int u, v;
    double c;
    Edge() {}
    Edge(int u, int v, double c) : u(u), v(v), c(c) {}
};

vector<Edge> vec;

int n, m;
double g[maxn][maxn];
double dis[maxn];
bool vis[maxn];
int cnt[maxn];
map<string, int> cor;
map<int, string> uncor;

bool bellman_ford(int st) {
    for(int i = 0; i <= n; i++)
        dis[i] = 0;
    dis[st] = 1;
    for(int j = 1; j < n; j++) { // 进行n-1次松弛
        for(int i = 0; i < vec.size(); i++) {
            int u = vec[i].u, v = vec[i].v;
            if(dis[v] < dis[u] * vec[i].c) {
                dis[v] = dis[u]*vec[i].c;
            }
        }
    }
    for(int i = 0; i < vec.size(); i++) {
        int u = vec[i].u, v = vec[i].v;
        if(dis[v] < dis[u] * vec[i].c) {
            return true;
        }
    }
    return false;
}

int main() {
    int cas = 0;
    while(~scanf("%d", &n) && n) {
        cor.clear(); uncor.clear(); vec.clear();
        int _cnt = 0;
        string name;
        for(int i = 1; i <= n; i++) {
            cin >> name;
            cor.insert(make_pair(name, ++_cnt));
            uncor.insert(make_pair(_cnt, name));
        }
        cin >> m;
        double r;
        string name1, name2;
        for(int i = 1; i <= m; i++) {
            cin >> name1 >> r >> name2;
            vec.push_back(Edge(cor[name1], cor[name2], r));
        }
        bool ok = false;
        for(int i = 1; i <= n; i++) {
            if(bellman_ford(i)) {
                ok = true;
                break;
            }
        }
        printf("Case %d: %s\n", ++cas, ok ? "Yes" : "No");
    }
    return 0;
}