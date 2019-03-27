#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int par[100+5],ranks[100+5];

void init(){
    for(int i = 0; i<100; i++){
        par[i] = i;
        ranks[i] = 0;
    }
}

int find(int x){
    if(par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;

    if(ranks[x] < ranks[y])
        par[x] = y;
    else {
        par[y] = x;
        if(ranks[x] == ranks[y]) ranks[x]++;
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

int main()
{
    int cas = 1;
    bool over = false;
    while(1)
    {
        int a,b;
        bool OK = true;
        set<int> s;
        init();
        while(1)
        {
            scanf("%d%d",&a,&b);
            if(a == b && a == 0) break;
            if(a == b && a == -1){
                over = true;
                break;
            }
            s.insert(a);
            s.insert(b);
            if(!same(a,b) && OK) unite(a,b);
            else{
                OK = false;
                continue;
            }
        }
        if(over) break;
        set<int>::iterator ite;
        ite = s.begin();
        int root = find(*ite);
        for(; ite!=s.end(); ite++){
            if(root != find(*ite)) OK = false;
        }
        if(OK) printf("Case %d is a tree.\n",cas);
        else   printf("Case %d is not a tree.\n",cas);
        cas++;
    }
    return 0;
}
