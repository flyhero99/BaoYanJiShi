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
const int maxn = 505; // maximum value of n

void print_permutation(int *a, int n, int cur) {
    if(cur == n) {
        for(int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
    }
    else {
        for(int i = 1; i <= n; i++) {
            int ok = 1;
            for(int j = 0; j < cur; j++)
                if(a[j] == i) ok = 0;
            if(ok) {
                a[cur] = i;
                print_permutation(a, n, cur+1);
            }
        }
    }
}

int main() {
    int n; scanf("%d", &n);
    int a[n+1];
    print_permutation(a, n, 0);
    return 0;
}