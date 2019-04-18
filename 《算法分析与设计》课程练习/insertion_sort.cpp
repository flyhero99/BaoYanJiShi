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

void insertion_sort1(int *a, int n) {
    for(int i = 2; i <= n; i++) {
        for(int j = i-1; j >= 1 && a[j+1] < a[j]; j--) {
            swap(a[j+1], a[j]);
        }
    }
}

void insertion_sort2(int *a, int n) {
    for(int i = 2; i <= n; i++) {
        int k = a[i], j = i-1;
        for( ; j > 0 && a[j] > k; j--)
            a[j+1] = a[j];
        a[j+1] = k;
    }
}

int main() {
    int n;
    srand(time(NULL));
    while(~scanf("%d", &n) && n) {
        int a[n+1];
        // int time = rand() % n;
        // int cnt = 0;
        // do {
        //     if(cnt++ >= time) break;
        // } while(next_permutation(a+1, a+n+1));
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        printf("Please input the version of insertion_sort: ");
        int x; scanf("%d", &x);
        long start_time = clock();
        if(x == 1) insertion_sort1(a, n);
        else if(x == 2) insertion_sort2(a, n);
        long end_time = clock();
        for(int i = 1; i <= n; i++) printf("%d%c", a[i], i==n ? '\n' : ' ');
        printf("Execution time: %fms.\n", (double)(end_time-start_time)/1000.0);
    }
    return 0;
}