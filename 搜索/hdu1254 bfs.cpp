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
const int maxn = 1000005;
const int inf = 0x3f3f3f3f;

int T, n, m;
int mp[15][15];
int vis[15][15][15][15];
int dx[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

struct node {
	int px, py; // person_x, person_y
	int bx, by; // box_x, box_y
	int step;
};

bool ok_person(node s) {
	return (0 <= s.px && s.px < n && 0 <= s.py && s.py < m && mp[s.px][s.py] != 1 && s.step < vis[s.px][s.py][s.bx][s.by]);
}

bool ok_box(node s) {
	return (0 <= s.bx && s.bx < n && 0 <= s.by && s.by < m && mp[s.bx][s.by] != 1 && s.step < vis[s.px][s.py][s.bx][s.by]);
}

void init() {
	for(int i = 0; i < 15; i++)
		for(int ii = 0; ii < 15; ii++)
			for(int j = 0; j < 15; j++)
				for(int jj = 0; jj < 15; jj++)
					vis[i][ii][j][jj] = inf;
}

int bfs(node s) {
	init();
	vis[s.px][s.py][s.bx][s.by] = 0;
	int ans = inf;
	queue<node> q;
	q.push(s);

	while(!q.empty()) {
		node t = q.front(); q.pop();
		if(mp[t.bx][t.by] == 3) {
			ans = min(ans, t.step);
		}
		for(int i = 0; i < 4; i++) {
			node tt = t;
			tt.px += dx[i][0];
			tt.py += dx[i][1];
			if(ok_person(tt)) { // 人可以向前走一步
				if(tt.px == tt.bx && tt.py == tt.by) { // 人与箱子重合，将箱子向前推一格
					tt.bx += dx[i][0];
					tt.by += dx[i][1];
					tt.step++;
					if(ok_box(tt)) {
						vis[tt.px][tt.py][tt.bx][tt.by] = tt.step;
						q.push(tt);
					}
				}
				else {
					vis[tt.px][tt.py][tt.bx][tt.by] = tt.step;
					q.push(tt);
				}
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		node s;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%d", &mp[i][j]);
				if(mp[i][j] == 4) {
					s.px = i;
					s.py = j;
					s.step = 0;
				}
				else if(mp[i][j] == 2) {
					s.bx = i;
					s.by = j;
				}
			}
		}
		int ans = bfs(s);
		printf("%d\n", ans==inf ? -1 : ans);
	}
	return 0;
}