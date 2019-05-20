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
ll data[maxn][maxn];
ll dis[maxn];
bool vis[maxn];

// 由于要求从1到1至少经过1个其他点的最短路，因此spfa初始化的时候不能将点1入队，而是将除1以外其余所有点入队，这样能保证至少经过一个点
ll spfa(int st) {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        dis[i] = data[st][i];
        if(i != st) {
            q.push(i);
            vis[i] = true;
        }
        else {
            vis[i] = false;
        }
    }
    dis[st] = inf;
    while(!q.empty()) {
        int t = q.front(); q.pop();
        vis[t] = false;
        for(int i = 1; i <= n; i++) {
            if(i == t) continue;
            if(dis[i] > dis[t]+data[t][i]) {
                dis[i] = dis[t] + data[t][i];
                if(!vis[i]) {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
    }
    return dis[n];
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%lld", &data[i][j]);
        ll ans, c1, cn;
        spfa(1);
        ans = dis[n], c1 = dis[1];
        spfa(n);
        cn = dis[n];
        cout << min(ans, c1+cn) << endl;
    }
    return 0;
}