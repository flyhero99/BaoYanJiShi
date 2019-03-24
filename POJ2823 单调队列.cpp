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

const int maxn = 1e6+5;

// 题目大意：给定一个数列，从左至右输出每个长度为m的数列段内的最小数和最大数。n,m范围1e6。

struct node {
    int x, index; // x代表元素的值，index代表其下标
} v[maxn];

int n, m;
int a[maxn]; // 原数组
int maxx[maxn]; // 维护n-m+1个区间的最大值
int minn[maxn]; // 维护n-m+1个区间的最小值

void getmin() {
    int head=1, tail=0;
    for(int i = 1; i < m; i++) { // 前m-1个直接进入队列
        while(head <= tail && v[tail].x >= a[i])
            tail--;
        v[++tail].x = a[i];
        v[tail].index = i;
    }
    for(int i = m; i <= n; i++) {
        while(head <= tail && v[tail].x >= a[i])
            tail--;
        v[++tail].x = a[i];
        v[tail].index = i;
        while(v[head].index < i-m+1) head++;
        minn[i-m+1] = v[head].x;
    }
}

void getmax() {
    int head=1, tail=0;
    for(int i = 1; i < m; i++) { // 前m-1个直接进入队列
        while(head <= tail && v[tail].x <= a[i])
            tail--;
        v[++tail].x = a[i];
        v[tail].index = i;
    }
    for(int i = m; i <= n; i++) {
        while(head <= tail && v[tail].x <= a[i])
            tail--;
        v[++tail].x = a[i];
        v[tail].index = i;
        while(v[head].index < i-m+1) head++;
        maxx[i-m+1] = v[head].x;
    }
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        getmin();
        getmax();
        for(int i = 1; i <= n-m+1; i++)
            printf("%d%c", minn[i], (i==n-m+1) ? '\n' : ' ');
        for(int i = 1; i <= n-m+1; i++)
            printf("%d%c", maxx[i], (i==n-m+1) ? '\n' : ' ');
    }
}