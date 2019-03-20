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
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;

const int maxn = 200005;

struct node {
	double num; //操作数
	char op; //操作符
	bool flag; //true表示操作数，false表示操作符
	node() {}
	node(double num, char op, bool flag) : num(num), op(op), flag(flag) {}
};
 
stack<node> s;//操作符栈
queue<node> q;//后缀表达式队列

int pri(char x) {
	if(x == '(' || x == ')') return 0;
	if(x == '+' || x == '-') return 1;
	return 2;
}

void trans(string str) {
	node tmp;
	for(int i = 0; i < str.length(); ) {
		// cout << "i: " << i << " " << str[i] << endl;
		if(str[i] == ' ') {
			// cout << "aaaa" << endl;
			i++;
		}
		else if(str[i] == '(') {
			tmp.flag = 0; tmp.op = str[i];
			s.push(tmp);
			i++;
		}
		else if(str[i] == ')') {
			while(!s.empty() && s.top().op != '(') {
				q.push(s.top());
				s.pop();
			}
			s.pop(); // 弹出左括号
			i++;
		}
		else if('0' <= str[i] && str[i] <= '9') {
			tmp.flag = 1; tmp.num = 0;
			while(i < str.length() && '0' <= str[i] && str[i] <= '9') {
				tmp.num = 10.0*tmp.num + str[i]-'0';
				i++;
			}
			q.push(tmp);
		}
		else {
			tmp.flag = 0; tmp.op = str[i];
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

double calc(queue<node> q) {
	double a, b;
	node cur, tmp;
	stack<node> nums;
	while(!q.empty()) {
		cur = q.front(); q.pop();
		if(cur.flag == true) {
			nums.push(cur);
		}
		else {
			b = nums.top().num; nums.pop();
			a = nums.top().num; nums.pop();
			tmp.flag = true;
			if(cur.op == '+') tmp.num = a+b;
			else if(cur.op == '-') tmp.num = a-b;
			else if(cur.op == '*') tmp.num = a*b;
			else if(cur.op == '/') tmp.num = a/b;
			nums.push(tmp);
		}
	}
	return nums.top().num;
}

int main() {
	string str;
	getline(cin, str);
	trans(str);
	node cur;
	int cnt = 0;
	queue<node> q2 = q;
	while(!q.empty()) {
		cur = q.front();
		if(cur.flag)
			cout << cur.num << " "; 
		else cout << cur.op << " ";	
		q.pop();
	}
	cout << endl << "result: " << calc(q2) << endl;
	return 0;
}