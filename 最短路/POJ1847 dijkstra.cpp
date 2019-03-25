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

int n, A, B;
int G[maxn][maxn];
int dis[maxn*2];
int s[maxn*2];

void Dijkstra() {
    for(int i = 1; i <= n; i++) {
        dis[i] = G[A][i];
        s[i]=0;
    }
    s[A] = 1;
    dis[A] = 0;
    for(int i = 1; i < n; i++) {
        int Min = inf, u = A;
        for(int j = 1; j <= n; j++) {
            if(dis[j] < inf && s[j] == 0 && Min > dis[j]) {
                u = j;
                Min = dis[j];
            }
        }
        if(Min > inf) break;
        s[u] = 1;

        for(int k = 1; k <= n; k++) {
            if(s[k] == 0 && G[u][k] < inf && dis[k] > dis[u]+G[u][k])
                dis[k] = dis[u]+G[u][k];
        }
    }
}

int main() {
    while(scanf("%d %d %d", &n, &A, &B) != EOF) {
        int num;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i == j) G[i][j] = 0;
                else G[i][j] = inf;
            for(int i = 1; i <= n; i++) {
                scanf("%d", &num);
                int k, w;
                for(int j = 1; j <= num; j++) {
                    scanf("%d", &k);
                    w = 1;
                    if(j == 1) w = 0;
                    G[i][k] = w;
                }
            }
            Dijkstra();
            if(dis[B] >= inf)
                cout << "-1" << endl;
            else
                cout << dis[B] << endl; 
     }
     return 0;
}