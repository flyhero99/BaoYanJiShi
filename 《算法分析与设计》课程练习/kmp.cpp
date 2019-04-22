#include <iostream>
#include <fstream>
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
#define MAXN 99
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int inf = 0x3f3f3f3f;
const int maxn = 105; // maximum value of n

vector<string> vec;
int nxt[maxn];

void getNext(string s) {
    memset(nxt, -1, sizeof nxt);
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < s.length()) {
        if(j == -1 || s[i] == s[j]) {
            i++;
            j++;
            nxt[i] = j;
        }
        else j = nxt[j];
    }
}

int kmp(string s, string p) {
    int i = 0, j = 0;
    int slen = s.length(), plen = p.length();
    while(i < slen && j < plen) {
        if(j == -1 || s[i] == p[j]) i++, j++;
        else j = nxt[j];
    }
    if(j == p.length()) return i-j;
    else return -1;
}

int main() {
    ifstream in("1.txt");
    string s;
    while(in >> s) vec.push_back(s);
    cout << "Total number of words of the essay: " << vec.size() << endl;
    cout << "Please input a pattern string: ";
    string p;
    while(cin >> p) {
        vector<string> ans;
        long start_time = clock();
        for(int i = 0; i < vec.size(); i++) {
            getNext(vec[i]);
            if(kmp(vec[i], p) != -1) ans.push_back(vec[i]);
        }
        long end_time = clock();
        int cnt = 0;
        cout << "\nFor pattern " << p << ", there are totally " << ans.size() << " matches as below: " << endl;
        cout << "-----------------------------------------------\n" << endl;
        for(int i = 0; i < ans.size(); i++) {
            cout << i+1 << ". ";
            cout << '[' << ans[i] << "]\n";
            // cout << '[' << ans[i] << "] "; cnt++;
            // if(cnt == 5) { cout << endl; cnt = 0; }
        }
        // if(cnt != 0)
            cout << "\n";
        cout << "Totally: " << ans.size() << " matches found. ";
        printf("Execution time: %.4fms.\n", (double)(end_time - start_time)/1000.0);
        cout << "-----------------------------------------------" << endl;
        cout << "Please input a pattern string: ";
    }
    // for(int i = 0; i < vec.size(); i++) {
    //     cout << s[i] << endl;
    // }
    // while(cin >> s >> p) {
    //     memset(nxt, -1, sizeof nxt);
    //     getNext();
    //     for(int i = 0; i <= s.length(); i++) cout << nxt[i] << ' '; cout << endl;
    //     cout << kmp() << endl;
    // }
    return 0;
}