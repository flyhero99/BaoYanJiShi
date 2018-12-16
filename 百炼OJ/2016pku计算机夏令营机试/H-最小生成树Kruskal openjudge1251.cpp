#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <sstream>
using namespace std;

const int maxn = 100005;

int n, m;

struct edge {
    int s, t, v;
    edge() {}
    edge(int _s, int _t, int _v) : s(_s), t(_t), v(_v) {}

    bool operator < (const edge &rhs) const {
        return v < rhs.v;
    }
};

vector<edge> edges;

int pre[maxn];

void init() {
    for(int i = 0; i <= maxn; i++) pre[i] = i;
}

int fd(int x) {
    if(pre[x] == x) return x;
    return pre[x] = fd(pre[x]);
}

int kruskal() {
    init();
    int sum = 0, cnt = 0;
    for(int i = 0; i < edges.size(); i++) {
        int x = fd(edges[i].s), y = fd(edges[i].t);
        if(x != y) {
            sum += edges[i].v;
            pre[x] = y;
            if(++cnt == n-1) break;
        }
    }
    return sum;
}

int main() {
    while(~scanf("%d", &n) && n) {
        edges.clear();
        for(int j = 1; j < n; j++) {
            char st[2]; int num;
            scanf("%s %d", st, &num);
            for(int i = 1; i <= num; i++) {
                char ed[2]; int val;
                scanf("%s %d", ed, &val);
                edges.push_back(edge((int)st[0]-'A', (int)ed[0]-'A', val));
            }
        }
        sort(edges.begin(), edges.end());
        printf("%d\n", kruskal());
    }
    return 0;
}