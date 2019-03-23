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
using namespace std;
typedef long long ll;

const int maxn = 5001;

struct edge {
    int x, y;
} e[maxn];

int n, m, k;
bool flag[maxn];
int pre[maxn];

void init() {
    for(int i = 0; i <= n; i++)
        pre[i] = i;
}

int fi(int x) {
    if(x == pre[x]) return x;
    return pre[x] = fi(pre[x]);
}

void join(int x, int y) {
    int fx = fi(x), fy = fi(y);
    if(fx == fy) return;
    else
        pre[fx] = fy;
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        init();
        memset(flag, 0, sizeof flag);
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &e[i].x, &e[i].y);
            join(e[i].x, e[i].y);
        }
        int cnt = 0; // 连通块个数
        for(int i = 0; i < n; i++) {
            if(pre[i] == i) cnt++;
        }
        scanf("%d", &k);
        for(int cas = 0; cas < k; cas++) {
            init();
            int cnt1 = 0;
            int city; scanf("%d", &city);
            flag[city] = 1;
            for(int i = 0; i < m; i++) {
                if(!flag[e[i].x] && !flag[e[i].y]) {
                    join(e[i].x, e[i].y);
                }
            }
            for(int i = 0; i < n; i++) {
                if(pre[i] == i && !flag[i])
                    cnt1++;
            }
            if(cnt == cnt1 || cnt == cnt1+1)
                printf("City %d is lost.\n",city);
            else
                printf("Red Alert: City %d is lost!\n",city);
            cnt = cnt1;
        }
        if(k == n) printf("Game Over.\n");
    }
    return 0;
}