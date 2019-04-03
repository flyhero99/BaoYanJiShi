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
#define MAXN 99
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;

void print_permulation(int n, int *p, int *a, int cur) {
	if(cur == n) {
		for(int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1 ? '\n' : ' ');
	}
	else {
		for(int i = 0; i < n; i++) {
			if(!i || p[i] != p[i-1]) {
				int c1 = 0, c2 = 0;
				for(int j = 0; j < cur; j++) if(a[j] == p[i]) c1++;
				for(int j = 0; j < n; j++) if(p[i] == p[j]) c2++;
				if(c1 < c2) {
					a[cur] = p[i];
					print_permulation(n, p, a, cur+1);
				}
			}
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	int a[n], p[n];
	for(int i = 0; i < n; i++) scanf("%d", &p[i]);
	sort(p, p+n);
	print_permulation(n, p, a, 0);
	return 0;
}