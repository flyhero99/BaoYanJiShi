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
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 200005;
const int inf = 0x3f3f3f3f;

int a[maxn], t[maxn];
ll ans = 0;

void merge_sort(int l, int r) {
	if(l >= r) return;
	int mid = l + (r-l)/2;
	merge_sort(l, mid);
	merge_sort(mid+1, r);
	int i = l, j = mid+1, cnt = l;
	while(i <= mid && j <= r) {
		if(a[i] <= 2*a[j]) i++;
		else {
			j++;
			ans += mid-i+1;
		}
	}
	i = l, j = mid+1, cnt = l;
	while(i <= mid && j <= r) {
		if(a[i] <= a[j]) t[cnt++] = a[i++];
		else {
			t[cnt++] = a[j++];
		}
	}
	while(i <= mid) t[cnt++] = a[i++];
	while(j <= r) t[cnt++] = a[j++];
	for(int i = l; i <= r; i++) a[i] = t[i];
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	ans = 0;
	merge_sort(0, n-1);
	cout << ans << endl;
	return 0;
}