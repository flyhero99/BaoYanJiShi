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

int getMax(string str) {
    char s = 1; int index = -1;
    for(int i = 0; i < str.length(); i++) {
        if(s < str[i]) {
            s = str[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int t = read();
    while(t--) {
        string str; int k; cin >> str >> k;
        for(auto it = str.begin(); it != str.end(); ) {
            if(*it == '0') str.erase(it);
            else it++;
        }
        while(k--) {
            bool flag = false;
            for(auto it = str.begin(); it != str.end(); ) {
                if(!flag) {
                    if(*it > *(it+1)) {
                        str.erase(it);
                        flag = true;
                        break;
                    }
                    else it++;
                }
            }
            if(!flag) str.pop_back();
        }
        cout << str << endl;
    }
    return 0;
}