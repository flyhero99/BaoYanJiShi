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
#define inf 0x7fffffff
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100005;

int main() {
	ll r, g, y;
	cin >> r >> y >> g;
	ll n; cin >> n;
	ll sum = 0;
	ll a, b;
	for(int i = 1; i <= n; i++) {
		cin >> a >> b;
		if(a == 0) sum += b;
		else {
			ll ta = a, tb = b;
			bool flag = 1;
			tb += (sum-tb) / (r+g+y) * (r+g+y); // 不能上来就直接循环，否则最后一组样例会超时
			while(flag) {
				flag = 0;
				if(ta == 1 && tb < sum) {
					ta = 3; tb += g; flag = 1;
				}
				else if(ta == 2 && tb < sum) {
					ta = 1; tb += r; flag = 1;
				}
				else if(ta == 3 && tb < sum) {
					ta = 2; tb += y; flag = 1;
				}
				if(tb >= sum) flag = 0;
			}
			// cout << " i: " << i;
			// cout << " ta: " << ta << " tb: " << tb;
			if(ta == 1) sum += (tb-sum);
			else if(ta == 2) sum += (tb-sum)+r;
		}
		// cout << " sum: " << sum << endl;
	}
	cout << sum << endl;
	return 0;
}