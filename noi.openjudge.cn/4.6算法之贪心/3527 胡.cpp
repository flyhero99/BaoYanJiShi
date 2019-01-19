#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define HASH 9
const int maxn = 1005;
typedef long long ll;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0'; ch = getchar(); }
    return x*f;
}

inline ll readll() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0';  ch = getchar(); }
    return x*f;
}

int cnt[11], n;
char ss[100];
ll base[11];
set<ll> s;

void init() {
    int len = strlen(ss); n = 0;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < len; i++) {
        if('0' <= ss[i] && ss[i] <= '9') {
            cnt[ss[i]-'0']++;
            n++;
        }
    }
}

bool dfs(int now, bool er, ll sta) {
    if(s.find(sta) != s.end()) return 0;
    while(!cnt[now] && now <= 9) now++;
    if(now == 10) return er;
    if(cnt[now] && cnt[now+1] && cnt[now+2]) {
        --cnt[now], --cnt[now+1], --cnt[now+2];
        if(dfs(now+1, er, sta-base[now]-base[now+1]-base[now+2])) return 1;
        ++cnt[now], ++cnt[now+1], ++cnt[now+2];
    }
    if(cnt[now] >= 3) {
        cnt[now] -= 3;
        if(dfs(now+1, er, sta-base[now]*3)) return 1;
        cnt[now] += 3;
    }
    if(cnt[now] >= 2 && !er) {
        cnt[now] -= 2;
        if(dfs(now+1, 1, sta-base[now]*2)) return 1;
        cnt[now] += 2;
    }
    s.insert(sta);
    return false;
}

void solve() {
    if((n-2) % 3) { puts("XIANGGONG"); return; }
    s.clear();
    ll sta = 0ll;
    for(int i = 1; i <= 9; i++) sta += cnt[i]*base[i];
    if(dfs(1, 0, sta)) puts("HU"); else puts("BUHU");
}

int main() {
    base[1] = 1; for(int i = 2; i <= 9; i++) base[i] = base[i-1] * HASH;
    while(1) {
        cin.getline(ss, 99);
        if(ss[0] == '0') break;
        init();
        solve();
    }
    return 0;
}