#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 205;

int dp[maxn][maxn];

int main() {
    string a, b;
    while(cin >> a >> b) {
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < a.length(); i++) {
            for(int j = 0; j < b.length(); j++) {
                if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j]+1;
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        cout << dp[a.length()][b.length()] << endl;
    }
    return 0;
}