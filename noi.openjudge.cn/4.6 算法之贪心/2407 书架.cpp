#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 10005;
typedef long long ll;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0'; ch = getchar(); }
    return x*f;
}

int n, b;
priority_queue<int, vector<int>, less<int> > pq;

int main() {
    n = read(); b = read();
    while(n--) {
        int x = read(); pq.push(x);
    }
    int cnt = 0, sum = 0;
    while(sum < b) {
        sum += pq.top(); pq.pop(); cnt++;
    }
    cout << cnt << endl;
    return 0;
}