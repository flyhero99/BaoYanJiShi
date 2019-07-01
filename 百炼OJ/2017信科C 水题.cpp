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

// 题目链接：http://bailian.openjudge.cn/xly2017/C/
// 提交链接：http://oucee.openjudge.cn/17b1/4/

int n, m;
int a[maxn][maxn];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool pd(int x, int y) {
	if(x < 0 || x >= n || y < 0 || y >= m) return true;
	if(a[x][y] == 0) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(cin >> n >> m) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j] == 1) {
					for(int t = 0; t < 4; t++) {
						int x = i+dx[t], y = j+dy[t];
						if(pd(x, y)) ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}