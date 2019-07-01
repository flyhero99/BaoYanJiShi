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

// 题目链接：// 题目链接：http://bailian.openjudge.cn/xly2017/A/
// 提交链接：http://noi.openjudge.cn/ch0113/10/

bool pd(int x) {
	if(x == 1) return false;
	if(x == 2 || x == 3) return true;
	for(int i = 2; i*i <= x; i++)
		if(x % i == 0) return false;
	return true;
}

int main() {
	int a, b;
	while(cin >> a >> b) {
		if(a > b) swap(a, b);
		int cnt = 0;
		for(int i = a; i <= b; i++) {
			if(pd(i)) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}