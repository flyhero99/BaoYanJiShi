#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
#define rep0(i, a, b) for(int i = a; i < b; i++)
#define rep1(i, a, b) for(int i = a; i <= b; i++)
typedef long long ll;

const int maxn = 15;

int n;
int mp[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

int main() {
    cin >> n; memset(mp, 0, sizeof mp); memset(dp, 0, sizeof dp);
    int x, y, v;
    while(~scanf("%d %d %d", &x, &y, &v) && (x+y+v)) {
        mp[x][y] = v;
    }
    rep1(i, 1, n) {
        rep1(j, 1, n) {
            rep1(k, 1, n) {
                rep1(l, 1, n) {
                    dp[i][j][k][l] = max(
                        max(dp[i-1][j][k-1][l], dp[i-1][j][k][l-1]),
                        max(dp[i][j-1][k-1][l], dp[i][j-1][k][l-1])
                        ) + mp[i][j] + mp[k][l];
                    if(i == k && j == l) dp[i][j][k][l] -= mp[i][j];
                }
            }
        }
    }
    cout << dp[n][n][n][n] << endl;
    return 0;
}