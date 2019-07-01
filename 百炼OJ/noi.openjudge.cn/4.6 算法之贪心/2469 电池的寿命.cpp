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

inline ll readll() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while('0' <= ch && ch <= '9') { x = x*10 + ch - '0';  ch = getchar(); }
    return x*f;
}

int main(){
    ll n;
    while(scanf("%lld", &n) != EOF) {
        // ll n = readll();
        ll maxx = -1, sum = 0;
        for(ll i = 1; i <= n; i++) {
            ll x = readll();
            sum += x*1ll;
            maxx = max(maxx, x*1ll);
        }
        printf("%.1f\n", sum-maxx < maxx ? (double)(sum-maxx) : (double)sum*0.5);
    }
    // while((scanf("%lld",&n))==1){
    //     da=-1;
    //     sum=0;
    //     for(int i=1;i<=n;i++){
    //         scanf("%lld",&dc[i]);
    //         sum+=dc[i];
    //         da=max(da,dc[i]);
    //     }
    //     if(sum-da<da) printf("%.1f\n",(double)(sum-da));
    //     else printf("%.1f\n",((double)sum)/2);
    // }
    return 0;
}