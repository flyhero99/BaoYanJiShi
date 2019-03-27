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
const int maxn = 100005;

int n, m;
int pre[maxn];
bool vis[maxn];

void init() {
    for(int i = 0; i <= maxn; i++) {
        pre[i] = i; vis[i] = 0;
    }
}

int Find(int x) {
    if(x == pre[x]) return x;
    int t = Find(pre[x]);
    pre[x] = t;
    return pre[x];
}

bool join(int a, int b) {
    int fa = Find(a), fb = Find(b);
    if(fa == fb) {
        return false;
    }
    else {
        pre[fa] = fb;
        return true;
    }
}

int main() {
    while(1) {
        int x, y; scanf("%d %d", &x, &y);
        if(x == -1 && y == -1) return 0;
        if(x == 0 && y == 0) {
            puts("Yes"); continue;
        }
        init();
        join(x, y);
        vis[x] = 1, vis[y] = 1;
        bool flag = true;
        while(~scanf("%d %d", &x, &y) && x && y) {
            vis[x] = 1, vis[y] = 1;
            if(!join(x, y)) {
                flag = false;
            }
        }
        if(!flag) {
            puts("No"); continue;
        }
        int cnt = 0;
        for(int i = 0; i <= maxn; i++) {
            if(vis[i] && pre[i] == i) cnt++;
        }
        printf("%s\n", cnt==1 ? "Yes" : "No");
    }
    return 0;
}