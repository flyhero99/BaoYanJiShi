#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 1005;

// 最小编辑距离：把串a变为串b的最小操作次数称为串a、b的最小编辑距离
// 教程：https://blog.csdn.net/cqbzlytina/article/details/75043804
// dp[i][j]表示把串a[1..i]变为串b[1..j]的最少操作次数
// 边界情况：i=0时，增加j个字符变为b，即dp[0][j]=0; j=0时，增加i个字符变为a，即dp[i][0]=0
// 状态转移：a[i]变为b[j]想要操作次数最少，需要其前一步也操作次数最少
// 即：dp[i-1][j]+1, dp[i][j-1]+1, 或dp[i-1][j-1]+1(a[i]!=b[j]时)

int main() {
    int n; cin >> n;
    while(n--) {
        string a, b; cin >> a >> b;
        int dp[maxn][maxn];
        for(int i = 0; i <= a.length(); i++) dp[i][0] = i;
        for(int i = 0; i <= b.length(); i++) dp[0][i] = i;
        for(int i = 0; i < a.length(); i++) {
            for(int j = 0; j < b.length(); j++) {
                if(a[i] == b[j]) {
                    dp[i+1][j+1] = dp[i][j];
                }
                else {
                    dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]), dp[i][j])+1;
                }
            }
        }
        cout << dp[a.length()][b.length()] << endl;
    }
    return 0;
}