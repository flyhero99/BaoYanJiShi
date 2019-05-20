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

int n, m;
int v[110][110];

void floyd() { // 求图的闭包，把所有可以确定的关系都求出来
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(v[i][j] == 1 || (v[i][k] == 1 && v[k][j] == 1))
                    v[i][j] = 1;
            }
        }
    }
}

int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
        memset(v, 0, sizeof(v));
        for(int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            v[x][y] = 1;
        }
        floyd();
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int du = 0;
            for(int j = 1; j <= n; j++) { // 对于每头牛， 求是否有唯一排名
                if(i == j) continue;
                if(v[i][j] == 1 || v[j][i] == 1)
                    du++;
            }
            if(du == n-1)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}