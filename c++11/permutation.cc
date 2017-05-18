
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <stdio.h>
using namespace std;

// clang++ -std=c++11 -stdlib=libc++ median_nums_two_sorted.cc && ./a.out


void dfs(vector<int> & input, int len, vector<int> & ret_tmp, vector<vector<int>> &ret) {

    if(ret_tmp.size() == len ) {
            ret.push_back(ret_tmp);
    }
    for(int k=0; k<len; k++) {
        if ( auto it = find(ret_tmp.begin(), ret_tmp.end(), input[k]) == ret_tmp.end() ) {
           ret_tmp.push_back(input[k]); 
           dfs(input,  len, ret_tmp, ret);
           ret_tmp.pop_back();
        }
    }
}


vector<vector<int>> resolve(vector<int> & input) {
    vector<vector<int>> ret;
    vector<int> tmp;

    dfs(input, input.size(), tmp, ret);
    return ret;
}

int main() {
    vector<int> vec = {1, 2, 3};

    vector<vector<int>> ret = resolve(vec);

    for(auto &m : ret) {
        for (auto &n : m) {
            cout << " " << n;
        }
        cout << endl;
    }

    return 0;
}

