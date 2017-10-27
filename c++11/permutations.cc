
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

int n = 3;
map<int,int> book;
vector<int> a(n+1,0);

void dfs(int step){ //step表示当前要处理的盒子
      if(step == n+1){
            //输出排列
            for(int i = 1; i <= n; i++)
                  printf("%d", a[i]);
            printf("\n");
            return;
      }
      for(int i = 1; i <= n; i++){
      if(book[i] == 0){
            a[step] = i;   //将i号扑克牌放入第step个盒子中
            book[i] = 1; // 置1表示第i号扑克牌不在手中
            dfs(step+1); //递归调用
            book[i] = 0; // 非常重要，收回该盒子中的扑克牌才能进行下一次尝试。
      }
  }
}

int main() {

	dfs(1);
    return 0;
}

