#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<string, string> pss;
typedef pair<int, int> pii;

const int maxn = 100005;

struct node {
    int x, y, z, step;
    node(int _x, int _y, int _z, int _step) : x(_x), y(_y), z(_z), step(_step) {}
};

int l, r, c, sx, sy, sz, ex, ey, ez;
char mp[35][35][35];
bool vis[35][35][35];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int check(node a) {
    if(a.x<0 || a.y<0 || a.z<0 || a.x>=l || a.y>=r || a.z>=c || mp[a.x][a.y][a.z] == '#' || vis[a.x][a.y][a.z])
        return 0;
    return 1;
}

int bfs(int x, int y, int z) {
    queue<node> q;
    q.push(node(sx, sy, sz, 0));
    vis[sx][sy][sz] = 1;
    while(!q.empty()) {
        node a = q.front(); q.pop();
        if(a.x == ex && a.y == ey && a.z == ez) return a.step;
        for(int i = 0; i < 6; i++) {
            node tmp(a.x+dx[i], a.y+dy[i], a.z+dz[i], a.step+1);
            if(check(tmp)) {
                vis[tmp.x][tmp.y][tmp.z] = 1;
                q.push(tmp);
            }
        }
    }
    return 0;
}

int main() {
    while(~scanf("%d %d %d", &l, &r, &c)) {
        if(l+r+c == 0) break;
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                scanf("%s", mp[i][j]);
                for(int k = 0; k < c; k++) {
                    if(mp[i][j][k] == 'S') {
                        sx = i, sy = j, sz = k;
                    }
                    else if(mp[i][j][k] == 'E') {
                        ex = i, ey = j, ez = k;
                    }
                }
            }
        }
        memset(vis, 0, sizeof vis);
        int ans = bfs(sx, sy, sz);
        if(ans) printf("Escaped in %d minute(s).\n", ans);
        else printf("Trapped!\n");
    }
    return 0;
}