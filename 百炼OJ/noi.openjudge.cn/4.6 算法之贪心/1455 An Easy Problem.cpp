#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
typedef long long ll;


inline int readint() {
    int x = 0, f = 1; char ch = getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

inline ll readll() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int n;

int cnt(int x) {
    int sum = 0;
    while(x > 0) {
        if(x & 1) sum++;
        x >>= 1;
    }
    return sum;
}

int main() {
    while(~scanf("%d", &n) && n) {
        int cntn = cnt(n);
        for(int i = n+1; ; i++) {
            if(cnt(i) == cntn) {
                cout << i << endl;
                break;
            }
        }
    }
}