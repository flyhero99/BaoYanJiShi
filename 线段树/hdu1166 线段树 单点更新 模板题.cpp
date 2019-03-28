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

ll add[maxn<<2]; // 记录更新量
ll tree[maxn<<2]; // 保存线段树

void pushUp(int root) {
    tree[root] = tree[root<<1] + tree[root<<1|1];
}

void pushDown(int root, int len) {
    if(add[root] != 0) {
        add[root<<1] += add[root];
        add[root<<1|1] += add[root];
        tree[root<<1] = add[root] * (len - (len>>1));
        tree[root<<1|1] = add[root] * (len>>1);
        add[root] = 0;
    }
}

void build(int l, int r, int root) {
    add[root] = 0;
    if(l == r) {
        scanf("%lld", &tree[root]);
        return;
    }
    build(l, (l+r)/2, root<<1);
    build((l+r)/2+1, r, root<<1|1);
    tree[root] = tree[root<<1] + tree[root<<1|1];
}

void update(int ul, int ur, int c, int l, int r, int root) {
    if(ul <= l && r <= ur) {
        add[root] += c;
        tree[root] += (ll) c * (r-l+1);
        return;
    }
    pushDown(root, r-l+1); // 进行更新
    if(ul <= (l+r)/2) update(ul, ur, c, l, (l+r)/2, root<<1);
    if(ur > (l+r)/2)  update(ul, ur, c, (l+r)/2+1, r, root<<1|1);
    pushUp(root);
}

ll query(int ql, int qr, int l, int r, int root) {
    if(ql <= l && r <= qr) return tree[root];
    pushDown(root, r-l+1);
    ll ans = 0;
    if(ql <= (l+r)/2) ans += query(ql, qr, l, (l+r)/2, root<<1);
    if(qr > (l+r)/2) ans += query(ql, qr, (l+r)/2+1, r, root<<1|1);
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    int n, q;
    for(int cas = 1; cas <= t; cas++) {
        memset(tree, -1, sizeof tree);
        scanf("%d", &n);
        build(1, n, 1);
        char ss[10];
        int x, y;
        printf("Case %d:\n", cas);
        while(1) {
            scanf("%s", ss);
            if(ss[0] == 'E') break;
            else if(ss[0] == 'Q') {
                scanf("%d %d", &x, &y);
                printf("%lld\n", query(x, y, 1, n, 1));
            }
            else if(ss[0] == 'A') {
                scanf("%d %d", &x, &y);
                update(x, x, y, 1, n, 1);
            }
            else if(ss[0] == 'S') {
                scanf("%d %d", &x, &y);
                update(x, x, -y, 1, n, 1);
            }
        }
    }
    return 0;
}