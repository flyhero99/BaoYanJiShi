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

int n, m;
int a[maxn];
ll tree[maxn<<2], add[maxn<<2];

void pushUp(int root) {
    tree[root] = tree[root<<1] + tree[root<<1|1];
}

void pushDown(int root, int len) {
    if(add[root] == 0) return;
    add[root<<1] += add[root];
    add[root<<1|1] += add[root];
    tree[root<<1] += add[root]*(len - (len>>1));
    tree[root<<1|1] += add[root] * (len>>1);
    add[root] = 0;
}

void build(int l, int r, int root) {
    add[root] = 0;
    if(l == r) {
        tree[root] = a[l];
        return;
    }
    int m = (l+r)/2;
    build(l, m, root<<1);
    build(m+1, r, root<<1|1);
    pushUp(root);
}

void update(int ul, int ur, int c, int l, int r, int root) {
    if(ul <= l && r <= ur) {
        add[root] += c;
        tree[root] += (ll) c * (r-l+1);
        return;
    }
    pushDown(root, r-l+1);
    int m = (l+r)/2;
    if(ul <= m) update(ul, ur, c, l, m, root<<1);
    if(ur > m) update(ul, ur, c, m+1, r, root<<1|1);
    pushUp(root);
}

ll query(int ql, int qr, int l, int r, int root) {
    if(ql <= l && r <= qr) return tree[root];
    pushDown(root, r-l+1);
    int m = (l+r)/2;
    ll ans = 0;
    if(ql <= m) ans += query(ql, qr, l, m, root<<1);
    if(qr > m) ans += query(ql, qr, m+1, r, root<<1|1);
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> n >> m) {
        for(int i = 1; i <= n; i++) cin >> a[i];
        build(1, n, 1);
        while(m--) {
            char c[2];
            cin >> c;
            if(c[0] == 'Q') {
                int x, y; cin >> x >> y;
                cout << query(x, y, 1, n, 1) << endl;;
            }
            else if(c[0] == 'C') {
                int x, y, z; cin >> x >> y >> z;
                update(x, y, z, 1, n, 1);
            }
        }
    }
    return 0;
}