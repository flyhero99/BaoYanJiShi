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
#include <unistd.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;

int N_MAX = 5;
const int bias = 3;
const int PROBABILITY = 30;

int n, m;
int g[maxn][maxn];
int dis[maxn];
int pre[maxn];
bool vis[maxn];

struct Edge {
    int v, c;
    Edge() {}
    Edge(int v, int c) : v(v), c(c) {}
};

struct qcmp {
    bool operator () (const pii a, const pii b) const {
        return a.fi > b.fi;
    }
};

vector<Edge> vec[maxn];

void data_generate() {
    memset(g, inf, sizeof g);
    for(int i = 0; i <= n; i++) vec[i].clear();
    n = rand() % N_MAX + bias, m = rand() % (n*(n-1)/2 - n) + n;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            g[i][j] = rand() % 100 + 10;
        }
        g[i][i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            int t = rand() % 100;
            if(t < PROBABILITY) g[i][j] = inf;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j && g[i][j] != inf) vec[i].push_back(Edge(j, g[i][j]));
        }
    }
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) cout << g[i][j] << ' ';
    //     cout << endl;
    // }
}

void dijkn2(int st) {
    // memset(dis, inf, sizeof dis);
    // memset(vis, 0, sizeof vis);
    // memset(pre, -1, sizeof pre);
    for(int i = 1; i <= n; i++) {
        dis[i] = g[st][i];
        vis[i] = 0;
        pre[i] = -1;
        // pre[i] = (g[st][i] == inf) ? -1 : st;
    }
    vis[st] = 1; dis[st] = 0; pre[st] = -1;
    for(int i = 1; i <= n; i++) {
        int minn = inf, v = -1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && minn > dis[j]) {
                minn = dis[j];
                v = j;
            }
        }
        vis[v] = 1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && dis[j] > dis[v]+g[v][j]) {
                // cout << "v: " << v << " j: " << j << endl;
                dis[j] = dis[v] + g[v][j];
                pre[j] = v;
            }
        }
    }
    return;
}

void dijknlogn(int st) {
    memset(dis, inf, sizeof dis);
    memset(vis, 0, sizeof vis);
    memset(pre, -1, sizeof pre);
    // for(int i = 1; i <= n; i++) {
    //     dis[i] = inf; vis[i] = 0;
    //     pre[i] = g[st][i] == inf ? -1 : st;
    // }
    vis[st] = 1; dis[st] = 0;
    priority_queue<pii, vector<pii>, qcmp> q;
    q.push(make_pair(dis[st], st));
    while(!q.empty()) {
        pii tmp = q.top(); q.pop();
        int u = tmp.se; // current node
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i].v, c = vec[u][i].c;
            if(dis[v] > dis[u] + c) {
                dis[v] = dis[u] + c;
                q.push(make_pair(dis[v], v));
                pre[v] = u;
            }
        }
    }
}

void print(int st, int ed) {
    stack<int> q;
    int p = ed;
    while(pre[p] != -1) {
        q.push(p); p = pre[p];
    }
    q.push(p);
    if(q.top() != st) cout << st;
    else { cout << q.top(); q.pop(); }
    while(!q.empty()) {
        cout << "->" << q.top(); q.pop();
    }
    cout << endl;
}

// void print(int st, int ed) {
//     // int cur = ed;
//     // cout << cur << " ";
//     // while(pre[cur] != -1) {
//     //     cout << "->" << pre[cur];
//     //     cur = pre[cur];
//     // }
//     stack<int> s;
//     int cur = ed;
//     s.push(cur);
//     while(cur != st) {
//         cur = pre[cur];
//         s.push(cur);
//         // cout << "aaa" << endl;
//     }
//     cout << s.top(); s.pop();
//     while(!s.empty()) {
//         cout << "->" << s.top();
//         s.pop();
//     }
//     cout << endl;
// }

int main() {
    srand(time(NULL));
    cout << "Please input a maximum limit of n: (-1 to exit) ";
    while(~scanf("%d", &N_MAX)) {
        if(N_MAX == -1) break;
        data_generate();
        cout << "nodes: " << n << " edges: " << m << endl;
        for(int i = 1; i <= n; i++) {
            cout << i << ": ";
            for(int j = 0; j < vec[i].size(); j++) {
                printf("(%d,%d) ", vec[i][j].v, vec[i][j].c);
            }
            cout << endl;
            // for(int j = 1; j <= n; j++)
            //     cout << g[i][j] << ' ';
            // cout << endl;
        }
        // usleep(2000000);
        // for(int i = 1; i <= m; i++) {
        //     int x, y, z; scanf("%d %d %d", &x, &y, &z);
        //     g[x][y] = g[y][x] = z;
        // }
        int st, ed;
        printf("Please input start and end node: ");
        scanf("%d %d", &st, &ed);
        cout << "[For the simple O(n^2) algorithm]" << endl;
        long start_time = clock();
        dijknlogn(st);
        long end_time = clock();
        printf("The shortest distance is: %d\n", dis[ed]);
        // for(int i = 0; i <= n; i++) cout << pre[i] << ' '; cout << endl;
        printf("The shortest path is: ");
        print(st, ed);
        printf("Execution time: %.4fms.\n\n", (double)(end_time - start_time)/1000.0);

        cout << "[For the heap-optimized O(nlogn) algorithm]" << endl;
        start_time = clock();
        dijkn2(st);
        end_time = clock();
        printf("The shortest distance is: %d\n", dis[ed]);
        // for(int i = 0; i <= n; i++) cout << pre[i] << ' '; cout << endl;
        printf("The shortest path is: ");
        print(st, ed);
        printf("Execution time: %.4fms.\n\n", (double)(end_time - start_time)/1000.0);

        cout << "Please input a maximum limit of n: (-1 to exit) ";
    }
    return 0;
}