#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;

const int inf = 0x3f3f3f3f;
const int maxn = 105;

int a[maxn];
int n;

void add(int i, int d) {
    if(a[i] == -1) {
        a[i] = d;
        return;
    }
    if(d > a[i]) add(2*i, d);
    else add(2*i+1, d);
}

// 完全二叉树特点：元素序号和层数相同的满二叉树的元素序号完全一致。这里用数组存树，则表现为序号连续且最后一个元素=n+1。

int main() {
    while(~scanf("%d", &n)) {
        memset(a, -1, sizeof a);
        int x;
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            add(1, x);
        }
        int c = 0, i = 0;
        // for(int i = 0; i < 2*n+1; i++) {
        //     if(a[i] != -1) printf("(%d,%d) ", i, a[i]);
        // }
        // cout << endl;
        while(c < n) {
            while(a[i] == -1) i++;
            // cout << "i: " << i << " c: " << c << endl;
            printf("%d%c", a[i], (c==n-1) ? '\n' : ' ');
            i++, c++;
        }
        if(i == n+1) puts("YES");
        else puts("NO");
    }
    return 0;
}