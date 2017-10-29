
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <unordered_set>
#include <queue> 
#include <map> 
#include <stack> 
#include <set> 
using namespace std;

// on mac: clang++ -std=c++11 -stdlib=libc++ xxx.cc && ./a.out

// http://www.jianshu.com/p/897f2a9e33cd

void PermutationHelp(vector<string> &ans, int k, string str)
{
    if(k == str.size() - 1)  // 结束条件
        ans.push_back(str);
    unordered_set<char> us; //记录出现过的字符
    sort(str.begin() + k, str.end()); //保证按字典序输出
    for(int i = k; i < str.size(); i++){   
        if(us.find(str[i]) == us.end())//只和没交换过的换
        {  
            us.insert(str[i]);
            swap(str[i], str[k]);
            PermutationHelp(ans, k + 1, str);
            swap(str[i], str[k]); //复位
        }
    }
    return;
}
vector<string> Permutation(string str) {
    vector<string> ans;
    PermutationHelp(ans, 0, str);
    return ans;
}

int main() {
    vector<string> ret = Permutation("aabc");

    for (auto &v : ret) {
        cout << v << endl;
    }
    return 0;
}

