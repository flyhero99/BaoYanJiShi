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

int n, m, ans;
int pre[maxn];
int rel[maxn]; // 这里的rel表示根节点对当前节点x的关系。 0: x与根结点同类；1: 根结点吃x；2: 根节点被x吃。

void init() {
    ans = 0;
    for(int i = 1; i <= maxn; i++) {
        pre[i] = i; rel[i] = 0;
    }
}

int Find(int x) {
    if(x == pre[x]) return x;
    int t = pre[x];
    pre[x] = Find(pre[x]);
    rel[x] = (rel[t] + rel[x]) % 2;
    // rel[x] = rel[t] ^ rel[x];
    return pre[x];
}

int join(int x, int y, int d) {
    int fx = Find(x), fy = Find(y);
    if(fx == fy) {
        // if(rel[x] ^ rel[y] != d) return 1;
        if((rel[x]+rel[y])%2 != d) return 1;
        return 0;
    }
    else {
        pre[fy] = fx;
        rel[fy] = (rel[x]+rel[y]+d) % 2;
    }
    return 0;
}

map<int, int> mp;

int main() {
    scanf("%d %d", &n, &m);
    mp.clear();
    init();
    int cnt = 1, ans = 0;
    for(int i = 1; i <= m; i++) {
        int x, y, d;
        char ch[10];
        scanf("%d %d %s", &x, &y, ch);
        if(!mp[x-1]) mp[x-1] = cnt++; // 离散化，由于是[x,y]闭区间，因此变为(x-1,y]
        if(!mp[y]) mp[y] = cnt++;
        if(strstr(ch, "even")) d = 0;
        else d = 1;
        if(join(mp[x-1], mp[y], d) && ans == 0) ans = i;
    }
    if(ans == 0) ans = m+1;
    printf("%d\n", ans-1);
    return 0;
}