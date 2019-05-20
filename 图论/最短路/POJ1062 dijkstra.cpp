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
const double inf = 0x3f3f3f3f;
const int maxn = 305;

int Price[maxn], Edge[maxn][maxn], Level[maxn];
int vis[maxn], d[maxn];
int N, M, ans;

void init() {
    memset(Price, 0, sizeof Price); memset(Level, 0, sizeof Level);
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            Edge[i][j] = inf;//初始化每条边都是不连通的
        }
    }
}

void read() {
    int i, j, X, T, TP;
    for(i = 1; i <= N; i++) {
        scanf("%d %d %d", &Price[i], &Level[i], &X);
        for(j = 0; j < X; j++) {
            scanf("%d %d", &T, &TP);
            Edge[T][i] = TP;//记录边
        }
        Edge[0][i] = Price[i];
    }
}

int dijkstra() {
    for(int i = 1; i <= N; i++) d[i] = Price[i];//源点0到每个点的权值赋为这个点的价格
    for(int i = 1; i <= N; i++) {
        int temp = inf,x;
        for(int j = 1; j <= N; j++) if(!vis[j] && d[j] <= temp) temp = d[x = j];
        vis[x] = 1;
        for(int j = 1; j <= N; j++) if(d[x]+Edge[x][j] < d[j] && !vis[j]) d[j] = d[x]+Edge[x][j];//要从合法的物品中选取，加上!vis[j]
    }
    return d[1];//这里找到的最小值是未知起点的最小值
}

int main() {
    while(~scanf("%d %d", &M, &N)) {
        init();
        read();
        ans = inf;
        for(int i = 1; i <= N; i++) {
            int minLevel = Level[i];//将目前的点视作等级最高的点
            for(int j = 1; j <= N; j++) {
                if(Level[j] - minLevel > M || minLevel > Level[j])vis[j] = 1;//如果有比它还低的点，或者差超过M，视为不合法
                else vis[j] = 0;
            }
            int now = dijkstra();
            ans = min(ans, now);
        }
        printf("%d\n", ans);
    }
    return 0;
}