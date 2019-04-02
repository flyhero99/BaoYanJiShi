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
#define MAXN 9999999999 // 每一位表示10个数字，所以是1e11进制
#define MAXLEN 50
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 1000005;

// 题意：求2p−12p−1的位数和最后500位结果，保留前导0，1000<=p<=3e61000<=p<=3e6
// 个人思路：2^p和2^p-1位数一样，为p*log(2)/log(10) + 1 
// 500位用高精度模拟 
// 开a[50]，一个数代表10位即可，只需要实现*2 和-1方法

struct BigNum {
    ll a[MAXLEN];
    int len;
};

BigNum b;

void mul2() {
    int i;
    ll up=0;
    int big = b.len;
    for(i = 0; i < big; i++) {
        ll temp = b.a[i]*2 + up;
        // cout << "i: " << i << " temp: " << temp << endl;
        if(temp > MAXN) {
            b.a[i] = temp - temp/(MAXN+1)*(MAXN+1);
            up = temp / (MAXN+1);
            // cout << "i: " << i << " b.a[i]: " << b.a[i] << " up: " << up << endl;
        }
        else {
            up = 0;
            b.a[i] = temp;
        }
        // cout << "b.a[i]: " << b.a[i] << endl;
    }
    b.len = big;
    if(up != 0) {
        if(i < MAXLEN) { b.a[i] = up; b.len++; }
    }
    // cout << "b.a[i]: " << b.a[0] << endl;
}

void sub1() {
    int big = b.len;
    for(int i = 0; i < big; i++) {
        if(b.a[i] < 1) {
            int j = i+1;
            while(b.a[j] == 0) j++;
            b.a[j--]--;
            while(j > i) b.a[j--] += MAXN;
            b.a[i] += MAXN+1-1;
        }
        else
            b.a[i]--;
        break;
    }
    b.len = big;
    while(b.a[b.len-1] == 0 && b.len > 1) b.len--;
}

int main() {
    ll p;
    while(~scanf("%lld", &p)) {
        memset(b.a, 0, sizeof b.a);
        b.a[0] = 1; b.len = 1;
        ll st = clock();
        for(int i = 1; i <= p; i++)
            mul2();
        sub1();
        for(int i = b.len-1; i >= 0; i--) {
            printf("%0lld", b.a[i]);
        }
        // for(int i = b.len-1; i >= 0; i--) {
        //     printf("bit %d: ", b.len-i);
        //     printf("%010lld\n", b.a[i]);
        // }
        puts("");
        ll ed = clock();
        printf("AC time = %fms\n", (double) (ed-st)/1000.0);
    }
    return 0;
}