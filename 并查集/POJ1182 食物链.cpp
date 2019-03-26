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
const int maxn = 50005;

// https://blog.csdn.net/niushuai666/article/details/6981689 这篇博客讲解的非常详细。

// 这题他妈的居然不能用while ~scanf多组输入，不然会WA！！！！！！调了特么的快两个小时！！！！！！！
// 血坑！！！！！！！！！！！！！！！！！！

int n, m, ans;
int pre[maxn];
int rel[maxn]; // 这里的rel表示根节点对当前节点x的关系。 0: x与根结点同类；1: 根结点吃x；2: 根节点被x吃。

void init() {
    ans = 0;
    for(int i = 1; i <= n; i++) {
        pre[i] = i; rel[i] = 0;
    }
}

int Find(int x) {
    if(x == pre[x]) return x;
    int t = pre[x];
    pre[x] = Find(pre[x]);
    rel[x] = (rel[t] + rel[x])%3;
    return pre[x];
}

void join(int a, int b, int d) {
    int fa = Find(a), fb = Find(b);
    if(fa == fb) {
        if((rel[a]+d-1)%3 != rel[b]) ans++;
    }
    else {
        pre[fb] = fa;
        rel[fb] = (rel[a] + d-1 + 3-rel[b]) % 3;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    init();
    for(int i = 1; i <= m; i++) {
        int d, a, b; scanf("%d %d %d", &d, &a, &b);
        if(a > n || b > n) { // 条件2
            ans++; continue;
        }
        if(d == 2 && a == b) { // 条件3
            ans++; continue;
        }
        join(a, b, d);
    }
    printf("%d\n", ans);
    return 0;
}