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
#define MAXN 99
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;

struct edge {
    int u, v, w;
    edge() {}
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator < (const edge &r) const {
        return w < r.w;
    }
};

vector<edge> vec;

int n;
int pre[maxn];

void init() {
    for(int i = 0; i <= n; i++) pre[i] = i;
}

int Find(int x) {
    if(x == pre[x]) return x;
    int t = Find(pre[x]);
    pre[x] = t;
    return pre[x];
}

int kruskal() {
    init();
    int sum = 0, cnt = 0;
    for(int i = 0; i < vec.size(); i++) {
        int u = vec[i].u, v = vec[i].v;
        int fa = Find(u), fb = Find(v);
        if(fa != fb) {
            pre[fa] = fb;
            sum += vec[i].w;
            if(++cnt == n-1) break;
        }
    }
    return sum;
}

int main() {
    while(~scanf("%d", &n) && n) {
        vec.clear();
        for(int j = 1; j < n; j++) {
            char st[2]; int num;
            scanf("%s %d", st, &num);
            for(int i = 1; i <= num; i++) {
                char ed[2]; int val;
                scanf("%s %d", ed, &val);
                vec.push_back(edge((int)st[0]-'A', (int)ed[0]-'A', val));
            }
        }
        sort(vec.begin(), vec.end());
        printf("%d\n", kruskal());
    }
    return 0;
}