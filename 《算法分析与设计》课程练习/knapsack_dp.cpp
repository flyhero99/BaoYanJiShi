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

int n; // the number of items
int m; // the pack's capacity
int v[maxn]; // the value of each item
int c[maxn]; // the cost of each item
int dp[maxm]; // the dp array

void zero_one_pack() {
	for(int i = 1; i <= n; i++) { // enumerate every item
		for(int j = m; j >= c[i]; j--)
			dp[j] = max(dp[j], dp[j-c[i]]+v[i]);
	}
}

int main() {
	printf("Please input the number of items (input -1 to exit): ");
	while(~scanf("%d", &n)) {
		if(n == -1) break;
		printf("Please input the capacity of the pack: ");
		scanf("%d", &m);
		printf("Please input the value and cost of every item, in pair:\n");
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= n; i++) scanf("%d %d", &v[i], &c[i]);
		long start_time = clock();
		zero_one_pack();
		long end_time = clock();
		printf("The maximum value of the pack is: %d\n", dp[m]);
		printf("Execution time: %fms.\n", (double)(end_time-start_time)/1000.0);
		printf("\nPlease input the number of items (input -1 to exit): ");
	}
	return 0;
}