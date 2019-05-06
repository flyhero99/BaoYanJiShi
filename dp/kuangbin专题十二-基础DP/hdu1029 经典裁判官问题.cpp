#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
const int inf = 0x3f3f3f3f;

// 思路：如果这个数列中存在一个出现次数超过n/2的数字，只要每次拿出两个不同的数，最后剩下的一定是那个出现次数最多的数字。
// 因此，当cnt=0时更新ans，否则当当前数等于ans的时候cnt++，否则cnt--。

int main() {
	int n, num, cnt, ans;
	while(~scanf("%d", &n)) {
		cnt = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &num);
			if(cnt == 0) {
				ans = num;
				cnt++;
			}
			else {
				if(ans == num) cnt++;
				else cnt--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}