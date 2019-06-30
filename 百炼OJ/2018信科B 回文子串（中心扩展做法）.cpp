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

int dp[1005][1005];

int expand(string s, int l, int r) {
	while(l >= 0 && r < s.length() && s[l] == s[r])
		l--, r++;
	return r-l-1;
}

int main() {
	int n; scanf("%d", &n);
	while(n--) {
		memset(dp, 0, sizeof dp);
		string s; cin >> s;
		int len = s.length();
		int st = 0, ed = 0;
		for(int i = 0; i < len; i++) {
			int len1 = expand(s, i, i);
			int len2 = expand(s, i, i+1);
			int len = max(len1, len2);
			if(len > ed - st) {
				st = i - (len-1)/2;
				ed = i + len/2;
			}
		}
		cout << s.substr(st, ed-st+1) << endl;
	}
	return 0;
}