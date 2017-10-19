
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
const int N=200005;
struct node
{
	int next,to,c;
}e[N*2];
int qu[N+100],dis[N];int cnt=0;int first[N],visit[N];
int l[N*31][2];
int h[N*31];
void insert(int u,int v,int c)
{
	e[++cnt].to=v;e[cnt].next=first[u];e[cnt].c=c;first[u]=cnt;
	e[++cnt].to=u;e[cnt].next=first[v];e[cnt].c=c;first[v]=cnt;
}
void bfs()
{
	int head=1,tail=2;
	qu[1]=1;
	while(head<=tail)
	{
		int rr=qu[head++];visit[rr]=1;
		for(int k=first[rr];k;k=e[k].next)
		if(!visit[e[k].to])
			visit[e[k].to]=1,qu[tail++]=e[k].to,dis[e[k].to]=dis[rr]^e[k].c;
	}
}
int k=0;
int tot=0;
void insert(int x)
{
	int ro=0;
	for(int i=30;i>=0;i--)
	{
		int cnt=(x&(1<<i))>>i;
		if(!l[ro][cnt])	l[ro][cnt]=++tot;
		ro=l[ro][cnt];
	}
	h[ro]++;
}
int find(int x)
{
	int ro=0;
	for(int i=30;i>=0;i--)
	{
		int cnt=(x&(1<<i))>>i;
		if(l[ro][!cnt])	ro=l[ro][!cnt],k+=(1<<i);
		else ro=l[ro][cnt];
	}
	return h[ro];
}
int main()
{
	freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n;
	scanf("%d",&n);
	int u,v,c;
	for(int i=1;i<n;i++)
		scanf("%d %d %d",&u,&v,&c),insert(u,v,c);
	bfs();
	for(int i=1;i<=n;i++)	insert(dis[i]);
	long long int max=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		k=0;int p=find(dis[i]);
		cout << "dist:" << dis[i] << " , k=" << k  << endl;
		if(k>max)		max=k,sum=p;
		else if(k==max)	sum+=p;
	}
	printf("%lld %lld\n",max,sum>>1);
	fclose(stdin);
	//fclose(stdout);
	return 0;
}

