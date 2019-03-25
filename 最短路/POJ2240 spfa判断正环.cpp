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
    int v;
    double c;
    Edge() {}
    Edge(int v, double c) : v(v), c(c) {}
};

vector<Edge> vec[maxn];

int n, m;
double dis[maxn];
bool vis[maxn];
int cnt[maxn];
map<string, int> cor;
map<int, string> uncor;

bool spfa(int st) {
    for(int i = 0; i <= n; i++) {
        dis[i] = 0.0; vis[i] = 0; cnt[i] = 0;
    }
    dis[st] = 1.0; vis[st] = true; cnt[st] = 1;
    queue<int> q; q.push(st);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i].v;
            double c = vec[u][i].c;
            if(dis[v] < dis[u] * c) {
                dis[v] = dis[u]*c;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    if(++cnt[v] > n) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int cas = 0;
    while(~scanf("%d", &n) && n) {
        cor.clear(); uncor.clear();
        int _cnt = 0;
        string name;
        for(int i = 1; i <= n; i++) {
            cin >> name;
            vec[i].clear();
            cor.insert(make_pair(name, ++_cnt));
            uncor.insert(make_pair(_cnt, name));
        }
        cin >> m;
        double r;
        string name1, name2;
        for(int i = 1; i <= m; i++) {
            cin >> name1 >> r >> name2;
            vec[cor[name1]].push_back(Edge(cor[name2], r));
        }
        bool ok = false;
        for(int i = 1; i <= n; i++) {
            if(spfa(i)) {
                ok = true;
                break;
            }
        }
        printf("Case %d: %s\n", ++cas, ok ? "Yes" : "No");
    }
    return 0;
}