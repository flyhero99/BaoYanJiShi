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
const int maxn = 505; // maximum kinds of items
const int maxm = 100005; // maximum capacity of the pack

void merge(int *a, int left, int mid, int right, int *temp) {
    int i = left, j = mid+1, cnt = 0;
    while(i <= mid && j <= right) {
        if(a[i] <= a[j]) temp[cnt++] = a[i++];
        else temp[cnt++] = a[j++];
    }
    while(i <= mid) temp[cnt++] = a[i++];
    while(j <= right) temp[cnt++] = a[j++];
    for(int i = left; i <= right; i++) a[i] = temp[i-left];
}

void merge_sort(int *a, int left, int right, int *temp) {
    if(left >= right) return;
    int mid = (left + right) >> 1;
    merge_sort(a, left, mid, temp);
    merge_sort(a, mid+1, right, temp);
    merge(a, left, mid, right, temp);
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        int a[n], t[n];
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        merge_sort(a, 1, n, t);
        for(int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
    }
    return 0;
}