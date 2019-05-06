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
const int inf = 0x3f3f3f3f;

/*分析：对于n种家庭作业，全部做完有n!种做的顺序
但是n!太大了，且对于完成作业1,2,3和1,3,2和2,1,3和3,2,1和3,1,2来说
完成它们消耗的天数一定是一样的，只是完成的顺序不同从而扣的分不同
所以可以将完成相同的作业的所有状态压缩成一种状态并记录扣的最少分即可
即：状态压缩dp
对于到达状态i,从何种状态到达i呢？只需要枚举所有的作业
假如对于作业k,i中含有作业k已完成，那么i可以由和i状态相同的状态仅仅是k未完成的
状态j=i-(1<<k)来完成k到达,并且j一定比i小，如果状态从0枚举到2^n-1那么j一定是在i之前已经计算过的 
*/

const int maxn = 1<<15+10;

int n;
int dp[maxn]; // dp[i]记录到达状态i时扣的最少分
int t[maxn]; // t时相应的花去了多少天
int pre[maxn], dea[20], fin[20];
char s[20][110];

void output(int x) {
    if(x == 0) return;
    output(x - (1<<pre[x]));
    printf("%s\n", s[pre[x]]);
}

int main() {
    int tt; scanf("%d", &tt);
    while(tt--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%s %d %d", &s[i], &dea[i], &fin[i]);
        int bit = 1<<n;
        for(int i = 1; i <= bit-1; i++) {
            dp[i] = inf;
            for(int j = n-1; j >= 0; j--) {
                int temp = 1<<j;
                if(i & temp) {
                    int score = t[i-temp] + fin[j] - dea[j];
                    score = max(0, score);
                    if(dp[i] > dp[i-temp]+score) {
                        dp[i] = dp[i-temp]+score;
                        t[i] = t[i-temp]+fin[j];
                        pre[i] = j;
                    }
                }
            }
        }
        printf("%d\n", dp[bit-1]);
        output(bit-1);
    }
    return 0;
}
