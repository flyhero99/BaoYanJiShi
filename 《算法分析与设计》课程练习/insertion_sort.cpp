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

void insertion_sort(int *a, int n) {
    for(int i = 2; i <= n; i++) {
        for(int j = i-1; j >= 1 && a[j+1] < a[j]; j--) {
            swap(a[j+1], a[j]);
        }
    }
}

int main() {
    int n;
    while(~scanf("%d", &n) && n) {
        int a[n+1];
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        insertion_sort(a, n);
        for(int i = 1; i <= n; i++) printf("%d%c", a[i], i==n ? '\n' : ' ');
    }
    return 0;
}