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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 10005;

struct node {
    char op;
    int num;
    bool f;
};

stack<node> s;
queue<node> q;

int pri(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

void trans(string str) {
    node tmp;
    for(int i = 0; i < str.length(); ) {
        if(str[i] == ' ') {
            i++;
        }
        else if(str[i] == '(') {
            tmp.f = false; tmp.op = str[i];
            q.push(tmp);
            i++;
        }
        else if(str[i] == ')') {
            while(!s.empty() && s.top().op != ')') {
                q.push(s.top());
                s.pop();
            }
            s.pop();
            i++;
        }
        else if('0' <= str[i] && str[i] <= '9') {
            tmp.num = 0; tmp.f = true;
            while(i < str.length() && '0' <= str[i] && str[i] <= '9') {
                tmp.num = tmp.num*10 + str[i] - '0';
                i++;
            }
            q.push(tmp);
        }
        else {
            tmp.f = false; tmp.op = str[i];
            while(!s.empty() && pri(s.top().op) >= pri(str[i])) {
                q.push(s.top());
                s.pop();
            }
            s.push(tmp);
            i++;
        }
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int calc(queue<node> q) {
    stack<node> s2;
    int a, b;
    node cur, tmp;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        if(cur.f == 1) {
            s2.push(cur);
        }
        else {
            b = s2.top().num; s2.pop();
            a = s2.top().num; s2.pop();
            tmp.f = true;
            if(cur.op == '+') tmp.num = a+b;
            else if(cur.op == '-') tmp.num = a-b;
            else if(cur.op == '*') tmp.num = a*b;
            else if(cur.op == '/') {
                if(b == 0) return -inf;
                tmp.num = a/b;
            }
            s2.push(tmp);
        }
    }
    return s2.top().num;
}

int main() {
    string str;
    while(getline(cin, str)) {
        while(!q.empty()) q.pop();
        trans(str);
        int num = calc(q);
        if(num != -inf) cout << num << endl;
        else cout << "err" << endl;
    }
    return 0;
}