#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;

int n;

int dp[maxn][maxn];

string a, b;

int main() {
    while(cin >> a >> b) {
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < a.length(); i++) {
            for(int j = 0; j < b.length(); j++) {
                if(a[i] == b[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
                else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        cout << dp[a.length()][b.length()] << endl;
    }
    return 0;
}