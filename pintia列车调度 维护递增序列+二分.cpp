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
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;

const int inf = 0x3f3f3f3f;
const int maxn=1e5+5;

int a[maxn];

//这里有个一定性：就是在数组len-1之前的元素一定都比 a[len-1]小；反证法一下，如果不比a[len-1]小，那a[len-1]大可放到前面去。
//所以a[len-1]一定是当前数组中最小的元素，然后插入K 的时候，直接和len-1比较一下就可以，满足插入条件的话就二分check一下找最接近k
//的并且大于k的位置插入 

int main() {
    int n; cin >> n;
    int k, len=0;
    while(n--) {
        cin >> k;
        if(len == 0 || a[len-1] < k) {
            a[len++] = k;
        }
        else {
            int l = 0, r = len-1;
            while(l < r) {
                int mid = (l + r)/2;
                if(a[mid] > k)
                    r = mid-1;
                else
                    l = mid+1;
            }
            a[l] = k;
        }
    }
    cout << len << endl;
    return 0;
}
