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
int tree[maxn<<2], add[maxn<<2];

void pushUp(int root) {
    tree[root] = max(tree[root<<1], tree[root<<1|1]);
}

void build(int l, int r, int root) {
    if(l == r) {
        tree[root] = a[l];
        return;
    }
    int m = (l+r)/2;
    build(l, m, root<<1);
    build(m+1, r, root<<1|1);
    pushUp(root);
}

void update(int ul, int c, int l, int r, int root) {
    if(l == r) {
        tree[root] = c;
        return;       
    }
    int m = (l+r)/2;
    if(ul <= m) update(ul, c, l, m, root<<1);
    else update(ul, c, m+1, r, root<<1|1);
    pushUp(root);
}

int query(int ql, int qr, int l, int r, int root) {
    if(ql <= l && r <= qr) return tree[root];
    int m = (l+r)/2;
    int ans = 0;
    if(ql <= m) ans = max(ans, query(ql, qr, l, m, root<<1));
    if(qr > m) ans = max(ans, query(ql, qr, m+1, r, root<<1|1));
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> n >> m) {
        for(int i = 1; i <= n; i++) cin >> a[i];
        build(1, n, 1);
        while(m--) {
            char c[2];
            int x, y;
            cin >> c >> x >> y;
            if(c[0] == 'Q') {
                cout << query(x, y, 1, n, 1) << endl;;
            }
            else if(c[0] == 'U') {
                update(x, y, 1, n, 1);
            }
        }
    }
    return 0;
}