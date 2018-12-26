#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

bool check(string s)
{
    int cnt=0;
    int len=s.size();
    
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(')
        {
            cnt++;
        }
        else if(s[i]==')')
        {
            if(cnt==0)return 0;
            cnt--;
        }
        else continue;
    }
    if(cnt)return 0;
    return 1;
}
typedef pair<string,int>psi;
const int maxn=1e5;
void solve()
{
    queue<psi>Q;
    Q.push(psi(s,0));
    set<string>S;
    vector<string>ans;
    int minS=1e9+7;
    while(!Q.empty())
    {
        string tmp=Q.front().first;
        int step=Q.front().second;
        Q.pop();
        if(step>minS)break;
        if(check(tmp))
        {
            minS=step;
            ans.push_back(tmp);
        }
        int len=tmp.size();
        for(int i=0;i<len;i++)
        {
            string x=tmp.substr(0,i)+tmp.substr(i+1);
            if(!S.count(x))
            {
                Q.push(psi(x,step+1));
                S.insert(x);
            }
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}
int main()
{
    cin>>s;
    int cnt=check(s);
    //cout<<cnt<<endl;
    if(cnt)
       cout<<s<<endl;
    else
        solve();
}
