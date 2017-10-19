
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
const int N=100005;
struct node
{
	int to,next,c;
}e[N*2];
int first[N],visit[N],size[N];
int cnt=0;
int n;
void insert(int u,int v,int c)
{
	e[++cnt].to=v;e[cnt].next=first[u];first[u]=cnt;e[cnt].c=c;
	e[++cnt].to=u;e[cnt].next=first[v];first[v]=cnt;e[cnt].c=c;
}
long long ans=0;long long sum=0;
void dfs(int x)
{	
	cout << "now:" << x <<endl; 
	visit[x]=1;size[x]=1;
	for(int k=first[x];k;k=e[k].next) {
		cout << "here:"  <<x << " -> " << e[k].to << " , visit: " << visit[e[k].to] <<endl; 
		if(!visit[e[k].to])
		{
			dfs(e[k].to);
			size[x]+=size[e[k].to];
		}
	}
}
void dfs2(int x)
{
	visit[x]=1;
	for(int k=first[x];k;k=e[k].next)
	{
		if(!visit[e[k].to])
		{
			cout << "dfs2, weight:" << e[k].c << " ,from: " << x << " ,to:" << e[k].to << " ,size: " << size[e[k].to] << " ,other-count: " << (n-size[e[k].to]) << "*: " << size[e[k].to]*(n-size[e[k].to])*e[k].c<< endl;
			ans+=e[k].c*size[e[k].to]*(n-size[e[k].to]);
			//ans+=e[k].c*(size[e[k].to]+(n-size[e[k].to]));
			dfs2(e[k].to);
		}	
	}
}
int main()
{
	scanf("%d",&n);
	int u,v,c;
	for(int i=1;i<n;i++)	
	{
		scanf("%d %d %d",&u,&v,&c);
		insert(u,v,c);
	}
	dfs(1);
	memset(visit,0,sizeof(visit));
	dfs2(1);
	printf("%lld\n",ans);
	return 0;
}
