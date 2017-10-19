
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

// on mac: clang++ -std=c++11 -stdlib=libc++ xxx.cc && ./a.out

#include<cstdio>
#include<cstring>
const int N=300050;
struct node
{
	int next,to,c;
}e[N*2];
int first[N];
int cnt=0;
long long int f[N];
int	 n;
void insert(int u,int v,int c)
{
	e[++cnt]=(node){first[u],v,c};first[u]=cnt;
	e[++cnt]=(node){first[v],u,c};first[v]=cnt;
}
long long int big[N];
int size[N],visit[N];
void dfs1(int x)
{
	visit[x]=1;size[x]=1;
	for(int k=first[x];k;k=e[k].next)
	if(!visit[e[k].to])
	{
		dfs1(e[k].to);
		size[x]+=size[e[k].to];
		big[x]+=big[e[k].to]+(long long )e[k].c*size[e[k].to];
	}
}
void dfs2(int x)
{
	visit[x]=1;
	for(int k=first[x];k;k=e[k].next)
	if(!visit[e[k].to])
	{
		f[e[k].to]=f[x]+(big[x]-big[e[k].to]-(long long )size[e[k].to]*e[k].c)+(n-size[e[k].to])*(long long )e[k].c;
		dfs2(e[k].to);
	}
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&n);
	int u,v,c;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&c);
		insert(u,v,c);
	}
	dfs1(1);
	memset(visit,0,sizeof(visit));
	dfs2(1);
	long long min=1e17;
	
	for(int i=1;i<=n;i++)
	min=min<big[i]+f[i]?min:big[i]+f[i];
	printf("%lld\n",min);
	return 0;
}
