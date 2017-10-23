
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


// http://dongxicheng.org/structure/binary_indexed_tree/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn=100005;
int n;
int c[maxn];

int lowbit(int x){
    return x&(-x);
}
void update(int i,int a){
    while(i){
        c[i]+=a;
        i-=lowbit(i);
    }
}

int sum(int x){
    int res=0;
    while(x<=n){
        res+=c[x];
        x+=lowbit(x);
    }
    return res;
}
int main()
{
    int a,b;
    while(scanf("%d",&n),n){
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a,&b);
            update(b,1);
            update(a-1,-1);
        }
        printf("%d",sum(1));
        for(int i=2;i<=n;i++)
            printf(" %d",sum(i));
        printf("\n");
    }
    return 0;
}
