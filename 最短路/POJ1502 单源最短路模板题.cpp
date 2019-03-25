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

int n;
int g[505][505];
int dis[maxn];
bool vis[maxn];

struct qcmp {
    bool operator () (const pii a, const pii b) const {
        return a.fi > b.fi;
    }
};

void init() {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            g[i][j] = inf;
        }
        g[i][i] = 0;
    }
}

int tran(string s) {
    int num = 0;
    for(int i = 0; i < s.length(); i++) num = num*10 + s[i]-'0';
    return num;
}

void dijk(int st) {
    priority_queue<pii, vector<pii>, qcmp> q;
    for(int i = 0; i <= n; i++) {
        dis[i] = inf;
        vis[i] = 0;
    }
    dis[st] = 0;
    q.push(make_pair(0, st));
    while(!q.empty()) {
        pii tmp = q.top(); q.pop();
        int u = tmp.se, c = tmp.fi;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 1; i <= n; i++) {
            if(g[u][i] != inf) {
                if(dis[i] > c+g[u][i]) {
                    dis[i] = c+g[u][i];
                    q.push(make_pair(dis[i], i));
                }
            }
        }
    }
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i-1; j++) {
                string s; cin >> s;
                if(s == "x") g[i][j] = g[j][i] = inf;
                else g[i][j] = g[j][i] = tran(s);
            }
        }
        dijk(1);
        int maxx = -inf;
        for(int i = 1; i <= n; i++) maxx = max(maxx, dis[i]);
        cout << maxx << endl;
        // for(int i = 1; i <= n; i++) cout << dis[i] << ' '; cout << endl;
    }
    return 0;
}