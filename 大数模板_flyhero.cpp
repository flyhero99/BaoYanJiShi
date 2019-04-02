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
#define pi acos(-1)
#define e exp(1)

#define MAXN 99
#define DLEN 2
#define MAXSIZE 1010

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 50005;

class BigNum {
public:
    ll a[MAXSIZE];
    int len;

    BigNum() { len = 1; memset(a, 0, sizeof a); }
    BigNum(const ll b);
    BigNum(const string s);
    BigNum(const BigNum &T);
    BigNum& operator = (const BigNum &T);

    friend istream& operator >> (istream &in, BigNum &T);
    friend ostream& operator << (ostream &out, BigNum &T);

    BigNum operator + (const BigNum &T) const;
    BigNum operator - (const BigNum &T) const;
    BigNum operator * (const BigNum &T) const;
    BigNum operator / (const int &b) const;
    BigNum operator ^ (const int &b) const;
    int operator % (const int &b) const;

    bool operator > (const BigNum &T) const;
    bool operator == (const BigNum &T) const;
    bool operator < (const BigNum &T) const;

    void print();
};

BigNum::BigNum(const ll b) {
    len = 0;
    memset(a, 0, sizeof a);
    ll c, d=b;
    while(d > MAXN) {
        a[len++] = d - d/(MAXN+1)*(MAXN+1);
        d = d/(MAXN+1);
    }
    a[len++] = d;
    while(a[len-1] == 0 && len > 1) len--;
}

BigNum::BigNum(const string s) {
    memset(a, 0, sizeof a);
    len = s.length() / DLEN;
    if(s.length() % DLEN) len++;
    int index = 0;
    for(int i = s.length()-1; i >= 0; i -= DLEN) {
        int t = 0, k = i-DLEN+1;
        if(k < 0) k = 0;
        for(int j = k; j <= i; j++)
            t = t*10 + s[j] - '0';
        a[index++] = t;
    }
}

BigNum::BigNum(const BigNum &T) {
    len = T.len;
    memset(a, 0, sizeof a);
    for(int i = 0; i < len; i++) a[i] = T.a[i];
}

BigNum& BigNum::operator = (const BigNum &T) {
    len = T.len;
    memset(a, 0, sizeof a);
    for(int i = 0; i < len; i++) a[i] = T.a[i];
    return *this;
}

istream& operator >> (istream &in, BigNum &T) {
    char ch[MAXSIZE*4];
    in >> ch;
    int L = strlen(ch), cnt=0;
    for(int i = L-1; i >= 0;) {
        int sum = 0, t = 1;
        for(int j = 0; j<4 && i>=0; j++, i--, t*=10) {
            sum += (ch[i]-'0')*t;
        }
        T.a[cnt++] = sum;
    }
    return in;
}

ostream& operator << (ostream &out, BigNum &T) {
    cout << T.a[T.len-1];
    for(int i = T.len-2; i >= 0; i--)
        printf("%02d", T.a[i]);
    return out;
}

BigNum BigNum::operator + (const BigNum &T) const {
    BigNum t = *this;
    int big = max(len, T.len);
    for(int i = 0; i < big; i++) {
        t.a[i] += T.a[i];
        if(t.a[i] > MAXN) {
            t.a[i] -= (MAXN+1);
            t.a[i+1]++;
        }
    }
    if(t.a[big] != 0) t.len = big+1;
    else t.len = big;
    return t;
}

BigNum BigNum::operator - (const BigNum &T) const {
    BigNum t1, t2;
    int big;
    bool flag;
    if(*this > T) {
        t1 = *this; t2 = T; flag = 0;
    }
    else {
        t1 = T; t2 = *this; flag = 1;
    }
    big = t1.len;
    for(int i = 0; i < big; i++) {
        if(t1.a[i] < t2.a[i]) {
            int j = i+1;
            while(t1.a[j] == 0) j++;
            t1.a[j--]--;
            while(j > i) t1.a[j--] += MAXN;
            t1.a[i] += MAXN+1 - t2.a[i];
        }
        else
            t1.a[i] -= t2.a[i];
    }
    while(t1.a[t1.len-1] == 0 && t1.len > 1) t1.len--;
    if(flag) t1.a[t1.len-1] = 0-t1.a[t1.len-1];
    return t1;
}

BigNum BigNum::operator * (const BigNum &T) const {
    BigNum t;
    int i, j;
    for(i = 0; i < len; i++) {
        ll up = 0;
        for(j = 0; j < T.len; j++) {
            ll temp = a[i] * T.a[j] + t.a[i+j] + up;
            if(temp > MAXN) {
                t.a[i+j] = temp - temp/(MAXN+1)*(MAXN+1);
                up = temp/(MAXN+1);
            }
            else {
                up = 0;
                t.a[i+j] = temp;
            }
        }
        if(up != 0) {
            t.a[i+j] = up;
        }
    }
    t.len = i+j;
    while(t.a[t.len-1] == 0 && t.len > 1) t.len--;
    return t;
}

BigNum BigNum::operator / (const int &b) const {
    BigNum t;
    int down=0;
    for(int i = len-1; i >= 0; i--) {
        t.a[i] = (ll) (a[i] + down*(MAXN+1)) / b;
        down = a[i]+down*(MAXN+1) - b*t.a[i];
    }
    t.len = len;
    while(t.a[t.len-1] == 0 && t.len > 1) t.len--;
    return t;
}

BigNum BigNum::operator ^ (const int &n) const {
    if(n < 0) exit(-1);
    if(n == 0) return 1;
    if(n == 1) return *this;
    int m = n;
    BigNum t = *this, ret(1);
    while(m > 0) {
        if(m & 1) {
            ret = ret * t;
        }
        m >>= 1;
        t = t*t;
    }
    return ret;
}

int BigNum::operator % (const int &b) const {
    int d = 0;
    for(int i = len-1; i >= 0; i--)
        d = ((d*(MAXN+1))%b + a[i]) % b;
    return d;
}

bool BigNum::operator > (const BigNum &T) const {
    if(len > T.len) return true;
    else if(len == T.len) {
        int ln = len-1;
        while(a[ln] == T.a[ln] && ln >= 0) ln--;
        if(ln >= 0 && a[ln] > T.a[ln]) return true;
        else return false;
    }
    else
        return false;
}

bool BigNum::operator == (const BigNum &T) const {
    if(len != T.len) return false;
    for(int i = 0; i < len; i++)
        if(a[i] != T.a[i]) return false;
    return true;
}

bool BigNum::operator < (const BigNum &T) const {
    return !(*this>T || *this==T);
}

void BigNum::print() {
    printf("%lld", a[len-1]);
    for(int i = len-2; i >= 0; i--) printf("%02lld", a[i]);
    printf("\n");
}

int main() {
    ll n, m;
    while(cin >> n >> m) {
        BigNum a(n), b(m);
        cout << "a: " << a << endl;
        // a.print();
        cout << "b: " << b << endl;
        // b.print();
        cout << "jia: "; (a+b).print();
        cout << "jian: "; (a-b).print();
        cout << "cheng: "; (a*b).print();
        cout << "chu: "; (a/m).print();
        cout << "cheng fang: "; (a^m).print();
        cout << "qu mo: "; cout << a%m << endl;
        cout << "da yu: "; printf("%s\n", (a>b) ? "True" : "False");
        cout << "deng yu: "; printf("%s\n", (a==b) ? "True" : "False");
    }
    return 0;
}