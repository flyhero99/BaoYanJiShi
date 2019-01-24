#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 505;

int n, m, a[maxn], b[maxn];

struct node {
    int val = 0;
    vector<int> v;
} dp[maxn];

// 博客讲解见：http://blog.csdn.net/wall_f/article/details/8279733
// 最长公共上升子序列 LCIS
// dp[i][j]表示a数组前i个、b数组前j个且以b[j]为结尾的LCIS的长度
// 转移方程为：dp[i][j] = dp[i-1][j] (a[i] != b[j]时)
//           dp[i][j] = max(dp[i-1][k]) (1 <= k <= j-1 && b[j] > b[k]) (前j-1里最大的以b[k]结尾的LCIS长度，且b[k]<b[k])
// 由于每次更新只用到了上一次的dp值即dp[i-1][j]，因此可以借鉴背包问题中滚动数组的方法把dp数组降为1维
// 
int main() {
    cin >> n; for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    cin >> m; for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
    // memset(dp, 0, sizeof dp);
    // vector<int> ans;
    for(int i = 1; i <= m; i++) {
        node maxx;
        for(int j = 1; j <= n; j++) {
            // if(b[i] > a[j]) maxx = max(maxx, dp[j]); // 更新maxx值
            if(b[i] > a[j] && dp[j].val > maxx.val) maxx = dp[j];
            if(b[i] == a[j]) {
                dp[j].val = maxx.val+1;
                dp[j].v = maxx.v;
                dp[j].v.push_back(b[i]);
            }
        }
    }
    node maxx = dp[1];
    for(int i = 2; i <= n; i++) if(dp[i].val > maxx.val) maxx = dp[i];
    cout << maxx.val << endl;
    for(int i = 0; i < maxx.v.size(); i++) printf("%d%c", maxx.v[i], i == maxx.v.size()-1 ? '\n' : ' ');
    return 0;
}