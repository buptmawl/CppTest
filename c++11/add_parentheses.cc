#include <bits/stdc++.h>
using namespace std;
const int maxn=100+50;
typedef long long ll;


void dfs(int num[],char opt[],int n,vector<int> &v){
    if(n==1){
        v.push_back(num[1]);
        return ;
    }
    int a[100]
    char b[100];
    /*cout<<" n="<<n<<endl;
    for(int i=1;i<=n;i++)cout<<num[i]<<" ";
    for(int j=1;j<=n-1;j++)cout<<opt[j]<<" ";
    cout<<endl;*/
    for(int i=1;i<=n-1;i++){
        int now;
        if(opt[i]=='+')now=num[i]+num[i+1];
        if(opt[i]=='-')now=num[i]-num[i+1];
        if(opt[i]=='*')now=num[i]*num[i+1];
        int cnt1=0,cnt2=0;
        for(int j=1;j<=i-1;j++)
            a[++cnt1]=num[j];
        a[++cnt1]=now;
        for(int j=i+2;j<=n;j++){
            a[++cnt1]=num[j];
        }
        for(int j=1;j<=i-1;j++)
            b[++cnt2]=opt[j];
        for(int j=i+1;j<=n-1;j++){
            b[++cnt2]=opt[j];
        }
        dfs(a,b,n-1,v);
    }
}
vector<int> diffWaysToCompute(string input){
    int n=input.size();
    int now=0;
    int a[100];
    char op[100];
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(input[i]>='0'&&input[i]<='9'){
            now=now*10+input[i]-'0';
        }
        else{
            a[++cnt1]=now;
            op[++cnt2]=input[i];
            now=0;
        }
    }
    a[++cnt1]=now;
    vector<int>ans;
    dfs(a,op,cnt1,ans);
    return ans;
}

int main() {
    string s="2-1-1";
    string ss="2*3-4*5";
    vector<int>ans=diffWaysToCompute(ss);
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
    return 0;
}

