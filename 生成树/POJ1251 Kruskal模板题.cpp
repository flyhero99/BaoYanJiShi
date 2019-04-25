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
const int maxn = 1005;

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator < (const Edge &r) const {
        return w < r.w;
    }
};

int n;
int pre[maxn];
vector<Edge> vec;

void init() {
    for(int i = 0; i <= n; i++) pre[i] = i;
}

int Find(int x) {
    if(x == pre[x]) return x;
    int t = pre[x];
    pre[x] = Find(pre[x]);
    return pre[x];
}

int kruskal() {
    int sum = 0, cnt = 0;
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++) {
        int u = vec[i].u, v = vec[i].v, w = vec[i].w;
        int fx = Find(u), fy = Find(v);
        if(fx != fy) {
            sum += w;
            pre[fy] = fx;
            cnt++;
        }
        if(cnt == n-1) break;
    }
    return sum;
}

int main() {
    while(~scanf("%d", &n) && n) {
        init(); vec.clear();
        for(int i = 1; i < n; i++) {
            string st; cin >> st;
            int num; cin >> num;
            while(num--) {
                string tt; int cost;
                cin >> tt >> cost;
                vec.push_back(Edge(st[0]-'A', tt[0]-'A', cost));
                vec.push_back(Edge(tt[0]-'A', st[0]-'A', cost));
            }
        }
        // for(int i = 0; i < vec.size(); i++) cout << vec[i].u << ' ' << vec[i].v << ' ' << vec[i].w << endl;
        cout << kruskal() << endl;
    }
    return 0;
}