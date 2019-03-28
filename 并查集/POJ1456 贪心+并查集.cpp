/*
POJ 1456
贪心处理。
按照获利p从大到小排序。
处理的时候选择最后的一个不冲突点。

用并查集实现链表的作用，快速找到不冲突点
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=10010;
int F[MAXN];
struct Node
{
    int p,d;
}node[MAXN];
bool cmp(Node a,Node b)//按p从大到小排序。d没有关系
{
    return a.p>b.p;
}
int find(int x)
{
    if(F[x]==-1)return x;
    return F[x]=find(F[x]);
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(F,-1,sizeof(F));
        for(int i=0;i<n;i++)
          scanf("%d%d",&node[i].p,&node[i].d);
        sort(node,node+n,cmp);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int t=find(node[i].d);
            if(t>0)
            {
                ans+=node[i].p;
                F[t]=t-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}