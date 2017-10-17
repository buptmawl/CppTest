
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <queue> 
#include <map> 
#include <stack> 
#include <set> 
using namespace std;

/*
    http://blog.csdn.net/Brian551/article/details/77071163
    http://blog.csdn.net/diudawang/article/details/27083249


   http://blog.csdn.net/acm_fighting/article/details/48342509
   题意:
   一颗N个点的树，求每个点到其他所有点的路径长度异或K的总和。
   即ANSi=sum(distance(i,j) xor K){1<=j<=N, j!=i}
   Input
   第一行一个整数t，测试数据组数
   每组数据第一行两个整数N，K 如题述。(N<=10^5,K<16)
   然后N-1 行每行三个整数a，b，c 表示a 到b 有一条长为c 的边。
   Output
   对于每组数据输出N行。
   第i 行为ANSi。
   Sample Input
   1
   4 0
   1 4 3
   1 3 2
   1 2 1
   Sample Output
   6
   8
   10
   12

   首先我们假设没有异或,那么先算出其他所有点到1的距离，然后已知所有点到他的父亲的距离，可以推知所有点到这个点的距离

   比如,sum[fa]表示所有点到这个点父亲的距离的和,sum1[v]表示他的子孙到他的距离和,设他和他的父亲之间的距离为x,他的子孙

   数目为sz[v]，]那么所有点到他的距离和便为sum[v]+(sum[fa]-sum1[v])+(n-sz[v])*x
 */

// on mac: clang++ -std=c++11 -stdlib=libc++ xxx.cc && ./a.out

const int maxn=1e5+100;  
typedef long long ll;  
typedef pair<ll,ll>pi;  
vector<pi>G[maxn];  
ll sz[maxn];  
ll dp[maxn][17];  
ll sum1[maxn],sum[maxn];  
ll rep[maxn];  
int w,n;  
  
void dfs1(int u,int p){  
    sz[u]=1;  
    sum[u]=0;  
    for(int i=1;i<16;i++)  
        dp[u][i]=0;  
    dp[u][0]=1;  
    for(int i=0;i<G[u].size();i++){  
        int v=G[u][i].first;  
        int k=G[u][i].second;  
        if(v==p)  
            continue;  
        dfs1(v,u);  
        sum1[v]=0;  
        int x=k/16,y=k%16;  
        sz[u]+=sz[v];  
        sum[u]+=sum[v]+sz[v]*16*x;         //sum[]一定为16的倍数  
        sum1[v]+=sum[v]+sz[v]*16*x;         //sum[v]-sum1[v]即为不是他的子孙到他的距离  
        for(int j=0;j<16;j++){  
            dp[u][(j+y)%16]+=dp[v][j];  
            if(j+y>=16){  
                sum[u]+=dp[v][j]*16;  
                sum1[v]+=dp[v][j]*16;  
            }  
        }  
    }  
}  
  
void dfs2(int u,int p){  
    rep[u]=sum[u];  
    //printf("u is %d sum[u] is %I64d\n",u,sum[u]);  
    for(int i=0;i<16;i++){  
        //if(u==1){  
            //printf("%d\n",dp[u][i]);  
        //}  
        rep[u]+=dp[u][i]*(i^w);  
    }  
    for(int i=0;i<G[u].size();i++){  
        int v=G[u][i].first;  
        int k=G[u][i].second;  
        if(v==p)  
            continue;  
        int x=k/16,y=k%16;  
        sum[v]+=(sum[u]-sum1[v]);  
        sum[v]+=(n-sz[v])*16*x;  
        vector<int>V;  
        V.assign(17,0);  
        for(int j=0;j<16;j++){  
            V[(j+y)%16]+=dp[u][j]-dp[v][(j-y+16)%16];  
            if(j+y>=16){  
                sum[v]+=(dp[u][j]-dp[v][(j-y+16)%16])*16;  
            }  
        }  
        for(int j=0;j<16;j++)  
            dp[v][j]+=V[j];  
        dfs2(v,u);  
    }  
}  
  
void init(int n){  
    for(int i=1;i<=n;i++)  
        G[i].clear();  
}  
  
int main(){  
    int t;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d%d",&n,&w);  
        init(n);  
        int u,v,k;  
        for(int i=1;i<n;i++){  
            scanf("%d%d%d",&u,&v,&k);  
            G[u].push_back(pi(v,k));  
            G[v].push_back(pi(u,k));  
        }  
        dfs1(1,0);  
        dfs2(1,0);  
        for(int i=1;i<=n;i++)  
            printf("%d: %lld\n", i, rep[i]-w);  
    }  
    return 0;  
}
