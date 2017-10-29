
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <stdio.h>
using namespace std;

// clang++ -std=c++11 -stdlib=libc++ median_nums_two_sorted.cc && ./a.out


void dfs(vector<int> & input, int len, int sub_len, int index, vector<int> & ret_tmp, vector<vector<int>> &ret) {

    if (ret_tmp.size() == sub_len)
        ret.push_back(ret_tmp);

    for(int k=index; k<len; k++) {
        ret_tmp.push_back(input[k]); 
        dfs(input, len, sub_len, k+1, ret_tmp, ret);
        ret_tmp.pop_back();
    }
}


vector<vector<int>> resolve(vector<int> & input, int sub_len) {
    vector<vector<int>> ret;
    vector<int> tmp;

    dfs(input, input.size(), sub_len, 0, tmp, ret);
    return ret;
}

int main() {
    vector<int> vec = {1, 2, 3, 5};
    sort(vec.begin(), vec.end());

    vector<vector<int>> ret = resolve(vec,3);

    vector<int> result_vec;
    for(auto &m : ret) {
        cout << " " ;
        for (auto &n : m) {
            cout << " " << n;
        }
        cout << endl;
    }


    return 0;
}

