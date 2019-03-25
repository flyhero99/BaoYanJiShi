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
const int maxn = 10005;

int n, m, k, num=0;
int g[505][505];

// 原来floyd还可以用来判断负环，学到了

int floyd() {
    for(int k = 1; k <= n; k++) {
        int i, j;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                int t = g[i][k] + g[k][j];
                if(g[i][j] > t) g[i][j] = t;
            }
            if(g[i][i] < 0) return 1; // 这里相当于枚举点k，松弛n次，如果有负的边，说明有负环
        }
    }
    return 0;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int a, b, c;
        scanf("%d %d %d", &n, &m, &k);
        memset(g, inf, sizeof g);
        for(int i = 1; i <= n; i++) g[i][i] = 0;
        for(int i = 1; i <= m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            if(c < g[a][b]) g[a][b] = g[b][a] = c;
        }
        for(int i = 1; i <= k; i++) {
            scanf("%d %d %d", &a, &b, &c);
            g[a][b] = -c;
        }
        num++;
        int f = floyd();
        if(!f) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}