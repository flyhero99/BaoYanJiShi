#include <bits/stdc++.h>
#define fi first
#define se second
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<string, string> pss;
typedef pair<int, int> pii;

const int maxn = 35;
const int maxm = 10005;

int n, m;
int pre[maxn];

void init() {
    for(int i = 0; i <= n; i++) pre[i] = i;
}

int findRoot(int x) {
    if(pre[x] == x)
        return x;
    else
        return findRoot(pre[x]);
}

struct Edge {
    int u, v, w;
}edge[maxm];

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

void prim() {
    init();
    int ans = 0, cnt = 0; //ans用来放最后的结果 cnt放有多个村庄已经连上了
    for(int i = 1; i <= m;i++) {
        int a = findRoot(edge[i].u);
        int b = findRoot(edge[i].v);
        if(a != b) {
            pre[a] = b;
            ans += edge[i].w;
            cnt++;
            if(cnt == n-1)//村庄都加进来 就可停止了
                break;
        }
    }
    printf("%d\n",ans);
}

int main() {
    while(scanf("%d", &n) != EOF && n) {
        m = 0;
        for(int j = 1; j < n; j++) {
            char v[2];
            int num;
            scanf("%s %d", &v, &num);

            for(int i = 1; i <= num; i++) {
                char vv[2];
                int tmp;
                scanf("%s %d", &vv, &tmp);
                m++;
                edge[m].u = (int)(*v - 'A' + 1);
                edge[m].v = (int)(*vv - 'A' + 1);
                edge[m].w = tmp;
            }
        }
        sort(edge+1, edge+m+1, cmp);
        prim();
    }
    return 0;
}