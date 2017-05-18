
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <stdio.h>
using namespace std;

// clang++ -std=c++11 -stdlib=libc++ median_nums_two_sorted.cc && ./a.out


void dfs(vector<int> & input, int indx, int len, vector<int> & ret_tmp, vector<vector<int>> &ret) {

    ret.push_back(ret_tmp);
    //if(ret_tmp.size() == len ) {
    //    //cout << "result:";
    //    //for (auto &n : ret_tmp) {
    //    //    cout << " " << n;
    //    //}
    //    //cout << endl;
    //}
    for(int k=indx; k<len; k++) {
        ret_tmp.push_back(input[k]); 
        dfs(input, k+1, len, ret_tmp, ret);
        ret_tmp.pop_back();
    }
}


vector<vector<int>> resolve(vector<int> & input) {
    vector<vector<int>> ret;
    vector<int> tmp;

    dfs(input, 0, input.size(), tmp, ret);
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

