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
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 105;
const int inf = 0x3f3f3f3f;

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

char mp[maxn][maxn];

int vis[maxn][maxn];
int sz[maxn], cnt;

void dfsX(int x, int y) {
	if(0 <= x && x < n && 0 <= y && y < m && vis[x][y] != 2) {
		if(mp[x][y] == 'X') {
			vis[x][y] = 2;
			dfsX(x-1, y);
			dfsX(x+1, y);
			dfsX(x, y-1);
			dfsX(x, y+1);
		}
	}
}

void dfs(int x, int y) {
	if(0 <= x && x < n && 0 <= y && y < m) {
		if(vis[x][y] != 1 && mp[x][y] != '.') {
			if(mp[x][y] == 'X' && vis[x][y] != 2) {
				sz[cnt]++;
				dfsX(x, y);
			}
			vis[x][y] = 1;
			dfs(x-1, y);
			dfs(x+1, y);
			dfs(x, y-1);
			dfs(x, y+1);
		}
	}
}

int main() {
	int cas = 0;
	while(scanf("%d %d", &m, &n) == 2) {
		if(n == 0 && m == 0) break;
		memset(mp, 0, sizeof mp);
		memset(vis, 0, sizeof vis);
		cnt = 0;
		for(int i = 0; i < n; i++) {
			scanf("%s", mp[i]);
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				// cout << "i: " << i << " j: " << j << endl;
				if(vis[i][j] != 1 && mp[i][j] != '.') {
					sz[cnt] = 0;
					dfs(i, j);
					if(sz[cnt] != 0)
						cnt++;
				}
			}
		}
		sort(sz, sz+cnt);
		printf("Throw %d\n", ++cas);
		for(int i = 0; i < cnt-1; i++)
			printf("%d ", sz[i]);
		printf("%d\n\n", sz[cnt-1]);
	}
	return 0;
}