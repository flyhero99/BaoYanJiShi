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

const int inf = 0x3f3f3f3f;
const int maxn = 3005;

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

int n, m, st, ed;
int mp[maxn][maxn];
int dis[maxn];
bool vis[maxn];

// 有重边所以用矩阵存图，n^2算法
void dijkn2() {
    for(int i = 0; i <= n; i++) {
        dis[i] = mp[st][i]; vis[i] = 0;
    }
    int minn, v;
    // for(int i = 1; i <= n; i++) cout << dis[i] << ' '; cout << endl;
    for(int i = 1; i <= n; i++) {
        // for(int j = 1; j <= n; j++) cout << dis[j] << ' '; cout << endl;
        minn = inf;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && dis[j] < minn) {
                v = j;
                minn = dis[j];
            }
        }
        vis[v] = 1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && dis[j] > mp[v][j]+dis[v])
                dis[j] = mp[v][j]+dis[v];
        }
    }
}

int main() {
    while(~scanf("%d %d", &m, &n)) { // 注意这里输入是先m后n。。。。。被样例坑哭了
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == j) mp[i][j] = 0;
                else mp[i][j] = mp[j][i] = inf;
            }
        }
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if(mp[u][v] > w) {
                mp[u][v] = mp[v][u] = w;
            }
        }
        st = n, ed = 1;
        dijkn2();
        printf("%d\n", dis[ed]);
    }
    return 0;
}