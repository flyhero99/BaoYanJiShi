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
const int maxn = 1000005;

int n, m;
int pre[maxn];
int rel[maxn]; // 代表父亲与x的性别关系。0:同性，1:异性。

void init() {
    for(int i = 0; i <= n; i++) {
        pre[i] = i; rel[i] = 0;
    }
}

int Find(int x) {
    if(x == pre[x]) return x;
    int t = pre[x];
    pre[x] = Find(pre[x]); // 这里务必记得要先Find下一层，再来更新后面的。。。
    rel[x] = (rel[x] + rel[t]) % 2; //因为要从上往下更新，先更新上面的再更新下面的，不然无限WA。。。。。。
    return pre[x];
}

int join(int a, int b) {
    int fa = Find(a), fb = Find(b);
    if(fa == fb) {
        if((rel[a]+1) % 2 != rel[b]) return 1;
        return 0;
    }
    else {
        pre[fb] = fa;
        rel[fb] = (rel[a]+1+rel[b]) % 2;
        return 0;
    }
}

int main() {
    int t; scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++) {
        scanf("%d %d", &n, &m);
        init();
        bool flag = 0;
        for(int i = 1; i <= m; i++) {
            int x, y; scanf("%d %d", &x, &y);
            if(join(x, y)) {
                flag = 1;
            }
        }
        if(!flag) printf("Scenario #%d:\nNo suspicious bugs found!\n\n", cas);
        else printf("Scenario #%d:\nSuspicious bugs found!\n\n", cas);
    }
    return 0;
}