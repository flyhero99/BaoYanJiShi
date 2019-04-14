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
const int maxn = 505; // maximum kinds of items
const int maxm = 100005; // maximum capacity of the pack

int n; // the number of items
int m; // the pack's capacity
int v[maxn]; // the value of each item
int c[maxn]; // the cost of each item

/*
4
10
42 7
12 3
40 4
25 5
*/

int main() {
    printf("Please input the number of items (input -1 to exit): ");
    while(~scanf("%d", &n)) {
        if(n == -1) break;
        printf("Please input the capacity of the pack: ");
        scanf("%d", &m);
        printf("Please input the value and cost of every item, in pair:\n");
        for(int i = 0; i < n; i++) scanf("%d %d", &v[i], &c[i]);
        int ans = 0; // the answer
        vector<int> selected;
        long start_time = clock();
        for(int i = 0; i < (1 << n); i++) {
            int tempv = 0, tempc = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) { // the j-th bit of i is 1, which means this bit is selected
                    // cout << j << ' ';
                    tempv += v[j];
                    tempc += c[j];
                }
            }
            if(tempc <= m) {
                if(ans < tempv) {
                    ans = tempv; // update the answer
                    selected.clear();
                    for(int j = 0; j < n; j++) // record the selected items
                        if(i & (1<<j)) selected.push_back(j);
                }
            }
        }
        long end_time = clock();

        // output
        printf("The maximum value of the pack is: %d\n", ans);
        printf("The selected items are: ");
        for(int i = 0; i < selected.size()-1; i++)
            printf("[%d], ", selected[i]+1);
        printf("[%d]\n", selected.back()+1);
        printf("Execution time: %fms.\n", (double)(end_time-start_time)/1000.0);
        printf("\nPlease input the number of items (input -1 to exit): ");
    }
    return 0;
}