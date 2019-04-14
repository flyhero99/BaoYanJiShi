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
const int maxn = 1005;

int n; // the number of cities
int g[15][15]; // saves the graph

/*
4
1 2 2
1 3 5
1 4 7
2 3 8
2 4 3
3 4 1
*/

int main() {
    int n;
    while(~scanf("%d", &n)) {
        string path = ""; memset(g, 0, sizeof g); // initialize
        for(int i = 0; i < n*(n-1)/2; i++) { // input the graph with format like the comment above
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g[u][v] = g[v][u] = w;
        }
        int a[n+1];
        for(int i = 0; i <= n; i++) a[i] = i;
        int ans = inf;
        long start_time = clock();
        do { // enumerate every arrangement of n cities, and calculate the distance
            int sum = 0;
            for(int i = 1; i <= n; i++) sum += g[a[i-1]][a[i]];
            sum += g[a[n]][a[1]];
            if(ans > sum) { // make the dictionary order minimum
                ans = sum;
                path = "";
                for(int i = 1; i <= n; i++) {
                    char temp = '0'+a[i];
                    path.append(1, temp);
                    if(i != n) path.append("->");
                }
            }
        } while(next_permutation(a+1, a+n+1));
        long end_time = clock();
        printf("The minimum distance is: %d\n", ans);
        printf("The path is: %s\n", path.c_str());
        printf("Execution time: %fms.\n", (double)(end_time-start_time)/1000.0);
    }
    return 0;
}