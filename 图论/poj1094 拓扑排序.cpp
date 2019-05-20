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
#define MAXN 99
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int inf = 0x3f3f3f3f;
const int maxn = 505; // maximum value of n

int n, m;
int g[50][50];
int in[50];
queue<int> result_q;

// void topo() {
//     queue<int> q;
//     for(int i = 0; i < n; i++) if(in[i] == 0) q.push(i);
//     vector<int> ans;
//     while(!q.empty()) {
//         int u = q.front(); q.pop();
//         for(int i = 0; i < n; i++) {
//             if(g[u][i] != inf) {
//                 in[i]--;
//                 if(in[i] == 0) q.push(i);
//             }
//         }
//     }
// }

int topo() {
    int g1[50][50];
    memcpy(g1, g, sizeof(g));
    memset(in, 0, sizeof in);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(g1[i][j] == 1) in[j]++;
    // for(int i = 0; i < n; i++) cout << in[i] << ' '; cout << endl;
    queue<int> q;
    int flag = 0;
    for(int k = 0; k < n; ) {
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(in[i] == 0) cnt++;
        if(cnt == 0) return 2;
        if(cnt > 1) flag = 3;
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) {
                k++;
                q.push(i);
                for(int j = 0; j < n; j++) {
                    if(g1[i][j] == 1) {
                        in[j]--;
                        g1[i][j] = 0;
                    }
                }
                in[i] = -1;
                break;
            }
        }
    }
    if(flag != 3) {
        result_q = q;
        return 1;
    }
    else return 3;
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        if(n == 0 && m == 0) break;
        memset(g, 0, sizeof g);
        int i, flag = 0;
        char a, b;
        for(i = 1; i <= m; i++) {
            cin >> a >> b >> b;
            g[a-'A'][b-'A'] = 1;
            if(flag == 1 || flag == 2) continue;
            flag = topo();
            if(flag == 1) {
                cout << "Sorted sequence determined after " << i << " relations: ";
                while(!result_q.empty()) {
                    int a = result_q.front();
                    result_q.pop();
                    cout << (char)('A' + a);
                }
                cout << "." << endl;
            }
            else if(flag == 2) cout << "Inconsistency found after " << i << " relations." << endl;
        }
        if(flag == 3) cout << "Sorted sequence cannot be determined." << endl;
    }
    return 0;
}