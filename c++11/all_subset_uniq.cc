
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <stdio.h>
using namespace std;

// clang++ -std=c++11 -stdlib=libc++ median_nums_two_sorted.cc && ./a.out


void dfs(vector<int> & input, int len, int index, vector<int> & ret_tmp, vector<vector<int>> &ret) {
    ret.push_back(ret_tmp);

    for(int k=index; k<len; k++) {
        if (k != index && input[k] == input[k-1]) 
            continue;
        ret_tmp.push_back(input[k]); 
        dfs(input, len, k+1, ret_tmp, ret);
        ret_tmp.pop_back();
    }
}


vector<vector<int>> resolve(vector<int> & input) {
    vector<vector<int>> ret;
    vector<int> tmp;

    dfs(input, input.size(), 0, tmp, ret);
    return ret;
}

int main() {
    vector<int> vec = {1, 2, 2};
    sort(vec.begin(), vec.end());

    vector<vector<int>> ret = resolve(vec);

    vector<int> result_vec;
    for(auto &m : ret) {
        int kk=0;
        cout << " " ;
        for (auto &n : m) {
            kk = 10*kk+n;
            cout << " " << n;
        }
        cout << endl;
        result_vec.push_back(kk);
    }

    return 0;
}

