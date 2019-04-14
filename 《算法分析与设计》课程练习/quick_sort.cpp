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

void quick_sort(int *a, int left, int right) {
    // cout << "left: " << left << " right: " << right << endl;
    if(left > right) return;
    int i = left, j = right, pivot = a[left];
    while(i < j) {
        while(i < j && a[j] >= pivot) j--; // find an element smaller than the pivot from the right
        while(i < j && a[i] <= pivot) i++; // find an element greater than the pivot from the left
        if(i < j) swap(a[i], a[j]); // avoid the circumstance that i==j
    }
    // i is already equal to j
    a[left] = a[i];
    a[i] = pivot;
    quick_sort(a, left, i-1);
    quick_sort(a, i+1, right);
}

/*
10
6 1 2 7 9 3 4 5 10 8
*/

int main() {
    int n;
    while(~scanf("%d", &n) && n) {
        int a[n];
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        quick_sort(a, 1, n);
        for(int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
    }
    return 0;
}