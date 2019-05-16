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

int main(){
    int red, yellow, green, N, a, b, ans=0;
    scanf("%d %d %d %d", &red, &yellow, &green, &N);
    while(~scanf("%d %d", &a, &b))
        if(a == 0 || a == 1)
            ans += b;
        else if(a == 2)
            ans += b+red;
    printf("%d", ans);
    return 0;
}