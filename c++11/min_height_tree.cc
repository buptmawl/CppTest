#include <iostream>
#include<vector>
using namespace std;
const int maxn=1000;
vector<int>v[maxn];
int d1[maxn],d2[maxn],dep[maxn];
void dfs(int rt,int f){
    for(auto var:v[rt]){
        if(var==f)continue;
        dfs(var,rt);
        if(d1[var]>d1[rt]){
            d2[rt]=d1[rt];
            d1[rt]=d1[var];
        }
        else if(d1[var]>d2[rt]){
            d2[rt]=d1[var];
        }
    }
    d1[rt]++;
    d2[rt]++;
}
int mindep;
void dfs2(int rt,int f){
    if(f!=-1){
        if(d1[f]==d1[rt]+1){
            dep[rt]=max(dep[rt],d2[f]);
            if(d2[f]+1>d1[rt]){
                d2[rt]=d1[rt];
                d1[rt]=d2[f]+1;
            }
            else if(d2[f]+1>d2[rt]){
                d2[rt]=d2[f]+1;
            }
        }
        else {
            dep[rt]=max(dep[rt],d1[f]);
            if(d1[f]+1>d1[rt]){
                d2[rt]=d1[rt];
                d1[rt]=d1[f]+1;
            }
            else if(d1[f]+1>d2[rt]){
                d2[rt]=d1[f]+1;
            }
        }
    }
    for(auto var:v[rt]){
        if(f==var)continue;
        dep[rt]=max(dep[rt],d1[var]);
        dfs2(var,rt);
    }
    
    dep[rt]=max(dep[rt],d1[rt]);
    
}
int main() {
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(0,-1);
    dfs2(0,-1);
   for(int i=0;i<n;i++)
   {    
       cout<<"i="<<i<<" "<<d1[i]<<" "<<d2[i]<<endl;
       //cout<<dep[i]<<endl;
   }
    return 0;
}


