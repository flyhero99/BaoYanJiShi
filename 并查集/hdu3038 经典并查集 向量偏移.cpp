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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 200005;

// https://www.cnblogs.com/liyinggang/p/5327055.html 这篇博客讲了向量偏移思想 实在是tql

int n, m, ans;
int pre[maxn];
int sum[maxn]; // 保存从某点到其祖先节点的距离。这里祖先节点，我理解，相当于另一个端点。
// 因此，并查集中实际保存的是多个输入进来的区间段和，join的时候更新按向量偏移的思想算即可。

void init() {
    for(int i = 0; i <= n; i++) {
        pre[i] = i; sum[i] = 0;
    }
}

int Find(int x) {
    if(x != pre[x]) {
        int t = pre[x];
        pre[x] = Find(pre[x]);
        sum[x] += sum[t];
    }
    return pre[x];
}

void join(int a, int b, int v) {
    a--;
    int fa = Find(a), fb = Find(b);
    if(fa == fb) { // 二者同根，则区间和可以进行判断
        if(sum[a] - sum[b] != v) ans++;
    }
    else {
        pre[fa] = fb;
        sum[fa] = v + sum[b] - sum[a];
    }
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        ans = 0;
        init();
        for(int i = 1; i <= m; i++) {
            int a, b, v;
            scanf("%d %d %d", &a, &b, &v);
            join(a, b, v);
        }
        cout << ans << endl;
        for(int i = 1; i <= n; i++) cout << pre[i] << ' '; cout << endl;
        for(int i = 1; i <= n; i++) cout << sum[i] << ' '; cout << endl;
    }
    return 0;
}