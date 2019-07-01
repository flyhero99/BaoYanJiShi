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
const int maxn = 1005;
const int inf = 0x3f3f3f3f;

// 题目链接：http://bailian.openjudge.cn/xly2017/G/
// 提交链接：http://jsrgzx.openjudge.cn/dynamic1/06/

int n;
priority_queue<int, vector<int>, greater<int> > q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--) {
		while(!q.empty()) q.pop();
		cin >> n;
		while(n--) {
			int x; cin >> x;
			if(x == 1) {
				int y; cin >> y;
				q.push(y);
			}
			else if(x == 2) {
				cout << q.top() << endl;
				q.pop();
			}
		}
	}
	return 0;
}