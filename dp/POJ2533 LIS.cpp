#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 10005;
const int inf = 0x3f3f3f3f;

int n;

int a[maxn], dp[maxn];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i <= n; i++) dp[i] = 1;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int maxx = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i-1; j >= 1; j--) {
                if(a[i] > a[j]) dp[i] = max(dp[i], dp[j]+1);
            }
            maxx = max(maxx, dp[i]);
        }
        cout << maxx << endl;
    }
    return 0;
}