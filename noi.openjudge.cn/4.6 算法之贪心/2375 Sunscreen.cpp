#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 3005;
typedef long long ll;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0'; ch = getchar(); }
    return x*f;
}

int c, l;
pii cows[maxn];
pii lot[maxn];

bool cmp1(const pii &lhs, const pii &rhs) {
    if(lhs.fi == rhs.fi) return lhs.se < rhs.se;
    return lhs.fi < rhs.fi;
}

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    c = read(); l = read();
    for(int i = 1; i <= c; i++) {
        cows[i].fi = read(); cows[i].se = read();
    }
    for(int i = 1; i <= l; i++) {
        lot[i].fi = read(); lot[i].se = read();
    }
    sort(cows+1, cows+1+c, cmp1);
    sort(lot+1, lot+1+l, cmp1);
    int j = 0, ans = 0;
    for(int i = 1; i <= l; i++) {
        while(j <= c && cows[j].fi <= lot[i].fi) {
            pq.push(cows[j].se);
            j++;
        }
        while(!pq.empty() && lot[i].se != 0) {
            int t = pq.top(); pq.pop();
            if(t >= lot[i].fi) {
                ans++;
                lot[i].se--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}