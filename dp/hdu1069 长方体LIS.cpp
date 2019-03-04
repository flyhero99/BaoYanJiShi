#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
const int inf = 0x3f3f3f3f;

struct box {
	int x, y, z, dp;

	box(int _x, int _y, int _z) : x(_x), y(_y), z(_z), dp(_z) {}
	
	bool operator < (const box &rhs) const {
		if(x != rhs.x) return x > rhs.x;
		else return y > rhs.y;
	}
};

vector<box> vec;

int main() {
	int n, cas=0;
	while(~scanf("%d", &n) && n) {
		vec.clear();
		for(int i = 1; i <= n; i++) {
			int x, y, z; scanf("%d %d %d", &x, &y, &z);
			vec.push_back(box(x, y, z));
			vec.push_back(box(x, z, y));
			vec.push_back(box(y, x, z));
			vec.push_back(box(y, z, x));
			vec.push_back(box(z, x, y));
			vec.push_back(box(z, y, x));
		}
		sort(vec.begin(), vec.end());
		int maxx = vec[0].dp;
		for(int i = 1; i < vec.size(); i++) {
			for(int j = 0; j < i; j++) {
				if(vec[j].x > vec[i].x && vec[j].y > vec[i].y) {
					vec[i].dp = max(vec[i].dp, vec[j].dp+vec[i].z);
				}
				maxx = max(maxx, vec[i].dp);
			}
		}
		printf("Case %d: maximum height = %d\n", ++cas, maxx);
	}
	return 0;
}
