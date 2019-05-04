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
#include <iomanip>
#define fi first
#define se second
#define MAXN 99
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
 
const double inf=1000.0;
const double eps=1e-10;
 
typedef class
{
    public:
        double x,y,z;
        double r;
}point;
 
/*Discuss Precision*/
 
int EPS(double k)
{
    if(fabs(k)<eps)
        return 0;
    return k>0?1:-1;
}
 
/*AB之间的距离（权值）*/
 
double dist(point A,point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z))-A.r-B.r;
}                        //AB距离是以球面为基准，而不是球心，因此要减去A球和B球的半径
 
int main(int i,int j)
{
    int n;
    while(cin>>n)
    {
        if(n<=0)
            break;
 
        /*Initial*/
 
        point* node=new point[n+1];
 
        double w[101][101];
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                w[i][j]=inf;
 
        /*Input*/
 
        for(i=1;i<=n;i++)
            cin>>node[i].x>>node[i].y>>node[i].z>>node[i].r;
 
        for(i=1;i<=n-1;i++)
            for(j=i+1;j<=n;j++)
            {
                double temp=dist(node[i],node[j]);
                if(EPS(temp)<=0)
                    w[i][j]=w[j][i]=0;  //两个球接触(相交)，则距离(权值)为0
                else
                    w[i][j]=w[j][i]=temp;
            }
 
        /*Prim Algorithm*/
 
        bool vist[101]={false};
        int s=1;
        vist[s]=true;
        int fi;
        double sum_w=0.0;
        for(int count=1;count<n;count++)
        {
            double min=inf;
 
            for(i=2;i<=n;i++)
                if(!vist[i])
                    if(min>w[s][i])
                    {
                        min=w[s][i];
                        fi=i;
                    }
 
            sum_w+=w[s][fi];
            vist[fi]=true;
 
            for(i=2;i<=n;i++)   //新源点s'继承最新合并进来的fi的性质
                if(!vist[i])    //以fi到其他点的更短路 取代旧源点s到其他点的权值
                    if(w[s][i]>w[fi][i])
                        w[s][i]=w[fi][i];
        }
 
        cout<<fixed<<setprecision(3)<<sum_w<<endl;
 
        /*Relax*/
 
        delete node;
    }
    return 0;
}