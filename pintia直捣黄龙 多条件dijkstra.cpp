#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;
const int inf = 0x3f3f3f3f;
const int maxn = 305;

struct Edge {
    int v, dis;
};

int n, m, cnt=0;
int people[maxn]; // 每个城市敌军数量
int dis[maxn];
bool vis[maxn];
int kill[maxn]; // 杀敌数量
int path[maxn]; // 路径前驱节点
int city[maxn]; // 解放城镇数量
int line_num[maxn]; // 路径条数

vector<Edge> vec[maxn]; // 邻接表

map<string, int> cor;
map<int, string> uncor;

bool cmp(int a, int b) {
    if(b == -1 || dis[a] < dis[b] || (dis[a]==dis[b] && city[a]>city[b]) || (dis[a]==dis[b] && city[a]==city[b] && kill[a]>kill[b]))
        return true;
    return false;
}

void dijk() {
    for(int i = 0; i <= n; i++) {
        dis[i] = inf; vis[i] = 0; path[i] = 0; city[i] = 0; kill[i] = 0; line_num[i] = 0;
    }
    dis[0] = 0;
    kill[0] = people[0];
    city[0] = 1;
    line_num[0] = 1;
    for(int i = 0; i < n; i++) {
        int u = -1;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && cmp(j, u)) {
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = -1;
        for(int j = 0; j < vec[u].size(); j++) {
            int v = vec[u][j].v;
            // 最短路径
            if(!vis[v] && dis[u] + vec[u][j].dis < dis[v]) {
                dis[v] = dis[u] + vec[u][j].dis;
                kill[v] = kill[u] + people[v];
                city[v] = city[u] + 1;
                path[v] = u;
                line_num[v] = line_num[u];
            }
            // 最短路径不唯一时，选择解放城市最多的路径
            else if(dis[v] == dis[u] + vec[u][j].dis && city[v] < city[u]+1) {
                dis[v] = dis[u] + vec[u][j].dis;
                city[v] = city[u]+1;
                kill[v] = kill[u] + people[v];
                path[v] = u;
                line_num[v] += line_num[u];
            }
            // 前二者不唯一时，选择杀敌最多的路径
            else if(dis[v] == dis[u] + vec[u][j].dis && city[v] == city[u]+1 && kill[v] < kill[u]+people[v]) {
                dis[v] = dis[u] + vec[u][j].dis;
                city[v] = city[u] + 1;
                kill[v] = kill[u] + people[v];
                path[v] = u;
                line_num[v] += line_num[u];
            }
            // 最短路不唯一时，记录路径条数
            else if(dis[v] == dis[u] + vec[u][j].dis) {
                line_num[v] += line_num[u];
            }
        }
    }
}

void find_line(int find_line_temp) {
    if (find_line_temp == 0) {
        cout << uncor[find_line_temp];
    }
    else {
        find_line(path[find_line_temp]);
        cout << "->" << uncor[find_line_temp];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    string start_road, end_road;
    cin >> start_road >> end_road;
    cor[start_road] = cnt++;
    uncor[cnt - 1] = start_road;
    cor[end_road] = cnt++;
    uncor[cnt - 1] = end_road;
    for(int i = 0; i < n - 1; ++i) {
        string name;
        int num_peo;
        cin >> name >> num_peo;
        if (!cor[name]) {
            cor[name] = cnt++;
            uncor[cnt - 1] = name;
        }
        people[cor[name]] = num_peo;
    }
    while (m--) {
        string input_u, input_v;
        int distance;
        cin >> input_u >> input_v >> distance;
        Edge add;
        add.v = cor[input_v];
        add.dis = distance;
        vec[cor[input_u]].push_back(add);
        add.v = cor[input_u];
        vec[cor[input_v]].push_back(add);
    }
    dijk();
    find_line(1);
    cout << endl;
    cout << line_num[1] << " " << dis[1] << " " << kill[1] << endl;
    return 0;
}