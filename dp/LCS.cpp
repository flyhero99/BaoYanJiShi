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
#define inf 0x3f3f3f3f
#define infll 0x7fffffff
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1005;

int alen, blen;
char a[maxn], b[maxn];
vector<int> location[26];
int c[maxn<<2], dp[maxn], d[maxn][maxn];

int lcsn2() {
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= alen; i++) {
		for(int j = 1; j <= blen; j++) {
			if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[alen][blen];
}

int lcsnlogn() {
	for(int i = 0; i < 26; i++) location[i].clear();
  	for(int i = blen; i >= 1; i--) { // 为了得到反序的位置
      	location[b[i]-'a'].push_back(i);
    }
    // for(int i = 0; i < 26; i++) {
    // 	if(location[i].size() != 0) {
    // 		for(int j = 0; j < location[i].size(); j++) cout << location[i][j] << ' '; cout << endl;
    // 	}
    // }
  	int k = 0;
  	for(int i = 1; i <= alen; i++) { // 替换原A串
      	int t = a[i]-'a';
      	for(int j = 0; j < location[t].size(); j++) c[++k] = location[t][j];
    }
	// for(int i = 1; i <= k; i++) cout << c[i] << ' '; cout << endl;
  	dp[1] = c[1]; int m = 0;
  	for(int i = 2; i <= k; i++) { // 二分求LIS
      	if(c[i] > dp[m]) dp[++m] = c[i];
      	else {
          	int t = lower_bound(dp+1, dp+m+1, c[i]) - dp;
          	dp[t] = c[i];
        }
    }
  	return m;
}

int main() {
	while(~scanf("%s %s", a+1, b+1)) {
		alen = strlen(a+1), blen = strlen(b+1);
		int ans = lcsnlogn();
		cout << ans << endl;
	}
	return 0;
}