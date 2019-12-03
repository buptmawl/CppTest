#include <iostream>
#include <algorithm>

using namespace std;

#define max 5000

typedef struct

{

   int x;

   int mod;//存储的是余数

   int up;//-1表示没没有上级，其他数字表示索引

}Node;

Node node[max];

 

bool IsMod[max];//判断余数为i是否已经出现过了

int q[max];//q记录的是填充到node中结点的序号

int jg[max];//存储的是最终的结果，逆序输出就是最终的结果

int m,n;//不解释了

int X[11];//存储的是M个输入的数字

 

void bfs();//之所以取bfs，是因为程序的执行过程和图的广度优先搜索很类似

 

int main()

{

   while(cin>>n)

   {

       //cin>>n;//输入测试的n

       cin>>m;//输入数字的个数

       for(int i=0;i<m;i++)

       {

           cin>>X[i];

       }

       for(int i=0;i<n;i++)

       {

           //清空

           IsMod[i]=false;

       }

       sort(X,X+m);//对X按照从小到大的顺序排序，便于找出最小的数

       bfs();

   }

   return 0;

}

void bfs()

{

   if(n==0)

   {

       cout<<0<<endl;

       return ;

   }

   int cnt=0;//cnt表示当前有几个结点存储于node结点中

   int r=0;//指示结点

   for(int i=0;i<m;i++)

   {

       if(X[i]==0)

           continue;//跳过以下步骤继续执行

       int mod=X[i]%n;

       if(mod==0)

       {

           cout<<X[i]<<endl;

           return ;

       }

       if(IsMod[mod]==true)

       {

           //判断余数为mod是否已经出现过

           continue;

       }

       IsMod[mod]=true;

       node[cnt].x=X[i];

       node[cnt].mod=mod;

       node[cnt].up=-1;

       q[r]=cnt;

       cnt+=1;

       r+=1;

   }

   int f=0;//游标

   int x;//临时变量

   while(f<r)

   {

       x=q[f];

       f+=1;

       for(int i=0;i<m;i++)

       {

           int mod=(10*node[x].mod+X[i])%n;

           if(mod==0)

           {

               //输出

               int count=0;

               while(node[x].up!=-1)

               {

                   jg[count]=node[x].x;

                   count+=1;

                   x=node[x].up;

               }

               jg[count]=node[x].x;

               for(int j=count;j>=0;j--)

                   cout<<jg[j];

               cout<<X[i]<<endl;

               return ;

           }

           if(IsMod[mod]==true)

               continue;

           IsMod[mod]=true;

           node[cnt].x=X[i];

           node[cnt].mod=mod;

           node[cnt].up=x;

           q[r]=cnt;

           cnt+=1;

           r+=1;

 

       }

   }

   cout<<0<<endl;

}
