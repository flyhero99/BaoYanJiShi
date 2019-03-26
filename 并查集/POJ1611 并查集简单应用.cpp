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
const int maxn = 30005;

int n, m;
int pre[maxn];

void init() {
    for(int i = 0; i <= n; i++) {
        pre[i] = i;
    }
}

int Find(int x) {
    if(pre[x] == x) return x;
    return pre[x] = Find(pre[x]);
}

void join(int a, int b) {
    int fa = Find(a), fb = Find(b);
    if(fa == fb) return;
    pre[fb] = fa;
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        if(n == 0 && m == 0) return 0;
        init();
        int k, x, y;
        for(int i = 1; i <= m; i++) {
            scanf("%d", &k);
            scanf("%d", &x);
            for(int i = 1; i <= k-1; i++) {
                scanf("%d", &y);
                join(x, y);
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(Find(i) == Find(0)) {
                sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}