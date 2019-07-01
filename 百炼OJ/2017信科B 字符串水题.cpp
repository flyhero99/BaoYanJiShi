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

// 题目链接：http://bailian.openjudge.cn/xly2017/B/
// 提交链接：http://sdsy.openjudge.cn/21/39/

bool pd(int x) {
	if(x == 1) return false;
	if(x == 2 || x == 3) return true;
	for(int i = 2; i*i <= x; i++)
		if(x % i == 0) return false;
	return true;
}

struct node {
	char c;
	int n;
	node() {}
	node(char c, int n) : c(c), n(n) {}
};

vector<node> vec;

int main() {
	string s;
	while(cin >> s) {
		vec.clear();
		for(int i = 0; i < s.length(); i++) {
			s[i] = tolower(s[i]);
		}
		int cnt = 1;
		for(int i = 1; i < s.length(); i++) {
			if(s[i-1] == s[i]) cnt++;
			else {
				vec.push_back(node(s[i-1], cnt));
				cnt = 1;
			}
		}
		vec.push_back(node(s.back(), cnt));
		for(int i = 0; i < vec.size(); i++) {
			printf("(%c,%d)", vec[i].c, vec[i].n);
		}
		puts("");
	}
	return 0;
}