#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

const int maxn = 1005;

int v, p;
int a[maxn]; // 存储村庄位置
int f[maxn][maxn]; // f[i][j]表示前i个村子有j个邮局
int mi[maxn][maxn]; // mi[i][j]表示从村子i到村子j只有1个邮局

// f[i][j] = min(f[i][j], f[k][j-1] + mi[k+1][i]); 即前i个村子有j个邮局相当于前k只有k-1个邮局 + k+1到j只有一个邮局

int main() {
    cin >> v >> p;
    for(int i = 1; i <= v; i++) cin >> a[i];
    for(int i = 1; i <= v; i++) for(int j = 1; j <= p; j++) f[i][j] = inf;
    for(int i = 1; i <= v; i++) {
        for(int j = i+1; j <= v; j++) {
            mi[i][j] = mi[i][j-1] + a[j] - a[(i+j)/2]; // 初始化第i到第j个村庄只建一个邮局时的花费
        }
        f[i][1] = mi[1][i]; // 前i个村庄（1～i）只有一个邮局
    }
    for(int i = 2; i <= v; i++) {
        for(int j = 2; j <= p; j++) {
            for(int k = j-1; k < i; k++) {
                f[i][j] = min(f[i][j], f[k][j-1]+mi[k+1][i]);
            }
        }
    }
    cout << f[v][p] << endl;
    return 0;
}