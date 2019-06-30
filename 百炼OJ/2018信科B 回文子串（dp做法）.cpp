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

int main() {
	int n; scanf("%d", &n);
	while(n--) {
		memset(dp, 0, sizeof dp);
		string s; cin >> s;
		int len = s.length();
		int maxx = 1, st = 0;
		for(int i = 0; i < len; i++) {
			for(int j = 0; j <= i; j++) {
				if(i-j <= 1) {
					dp[j][i] = (s[i] == s[j]);
				}
				else
					dp[j][i] = (s[i] == s[j]) && dp[j+1][i-1];
				if(dp[j][i] == 1 && maxx < i-j+1) {
					if(maxx < i-j+1) {
						maxx = i-j+1;
						st = j;
					}
				}
			}
		}
		cout << s.substr(st, maxx) << endl;
	}
	return 0;
}