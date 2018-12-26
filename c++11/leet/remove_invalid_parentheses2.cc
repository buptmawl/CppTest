#include <bits/stdc++.h>
using namespace std;
char s[100005];

int sum[100005];
int bac[100005];
int vis[100005];

int main() {
    scanf("%s", s + 1);
    int len = strlen(s + 1);

    sum[0] = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 1; i <= len; i++)
    {
        if(s[i] == '(')
        {
            sum[i] = sum[i - 1] + 1;
            cnt1++;
            vis[i] = 1;
        }
        else if(s[i] == ')')
        {
            sum[i] = sum[i - 1] - 1;
            cnt2++;
            vis[i] = -1;
        }
        else sum[i] = sum[i - 1];
    }


    if(sum[len] >= 0)
    {
       int tmp1 = sum[len];
       int tmp2 = 0;
       for(int i = 1; i <= len; i++)
       {
          if(sum[i] + tmp2 < 0)
          {
              vis[i] = 2;
              tmp2++;
          }
      }
      tmp1 += tmp2;
       for(int i = len; i >= 1; i--)
       {
           if(!tmp1) break;
           if(vis[i] == 1)
           {
               vis[i] = 2;
               tmp1--;
           }
       }
        for(int i = 1; i <= len; i++)
        {
            if(vis[i] != 2) printf("%c", s[i]);
            else continue;
        }
        puts("");
    }
    else if(sum[len] < 0)  //()())()
    {
       int tmp1 = -sum[len];
       int tmp2 = 0;
       for(int i = len; i >= 1; i--)
       {
          if(bac[i] + tmp2 < 0)
          {
              vis[i] = 2;
              tmp2++;
          }
       }
       tmp1 += tmp2;
       for(int i = 1; i <= len; i++)
       {
           if(!tmp1) break;
           if(vis[i] == -1)
           {
               vis[i] = 2;
               tmp1--;
           }
       }
        for(int i = 1; i <= len; i++)
        {
            if(vis[i] != 2) printf("%c", s[i]);
            else continue;
        }
        puts("");
    }

    return 0;
}

