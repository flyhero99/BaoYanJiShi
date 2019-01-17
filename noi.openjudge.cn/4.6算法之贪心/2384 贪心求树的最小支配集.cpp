#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 10005;
typedef long long ll;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0'; ch = getchar(); }
    return x*f;
}

int n, dfs_clock;
int pos[maxn], p[maxn];
bool vis[maxn];
vector<int> G[maxn];

/*
求树的dfs序，存到pos中。u为当前节点，fa为父节点。v != fa是为了防止递归调用
*/
void dfs(int u, int fa) {
    pos[dfs_clock++] = u;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!vis[v] && v != fa) {
            vis[v] = true;
            p[v] = u;
            dfs(v, u);
        }
    }
}

/*
贪心求树的最小支配集
选择一个点，求出dfs序列，按照其dfs序反向贪心，对于一个既不属于支配集也不与支配集中点相连的点来说，
如果他的父节点不属于支配集，将其父节点加入支配集。
*/
int greedy() {
    int ret = 0;
    bool zpxl[maxn] = {0}; // 与支配集中点相连的点
    bool zp[maxn] = {0}; // 支配集
    for(int i = n-1; i >= 0; i--) { // 倒序遍历dfs序
        int t = pos[i]; // dfs序中的第i个元素
        if(!zpxl[t]) {
            if(!zp[p[t]]) { // 如果该点的父节点不在支配集中
                zp[p[t]] = 1; // 把该点的父节点假如支配集zp
                ret++; // 支配集中点的个数++
            }
            zpxl[t] = zpxl[p[t]] = zpxl[p[p[t]]] = 1; // 该点、该点的父节点、该点的父节点的父节点加入支配集相连zpxl
        }
    }
    return ret;
}

/* 
附：
int greedy() //贪心求树的最小覆盖集
{
    bool s[maxn] = {0};
    bool set[maxn] = {0};
    int ret = 0;
    for(int i=n-1; i>=0; i--)
    {
        int t = pos[i];
        if(!s[t] && !s[p[t]])
        {
            set[p[t]] = 1;
            ret++;
            s[t] = 1;
            s[p[t]] = 1;
        }
    }
    return ret;
}

int greedy()    //贪心求树的最大独立集
{
    bool s[maxn] = {0};
    bool set[maxn] = {0};
    int ret = 0;
    for(int i=n-1; i>=0; i--)
    {
        int t = pos[i];
        if(!s[t])
        {
            set[t] = 1;
            ret++;
            s[t] = 1;
            s[p[t]] = 1;
        }
    }
    return ret;
}
*/

void addEdge(int u, int v) {
    G[u].push_back(v); G[v].push_back(u);
}

int main() {
    for( ; ~scanf("%d", &n); ) {
        for(int i = 0; i <= maxn; i++) G[i].clear();
        for(int i = 1; i < n; i++) {
            int u = read(), v = read();
            addEdge(u, v);
        }
        memset(vis, 0, sizeof(vis));
        dfs(1, -1);
        printf("%d\n", greedy());
    }
    return 0;
}