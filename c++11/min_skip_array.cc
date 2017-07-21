
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

const int INT_MAX_ = 1000000;


int getMinSkip(const vector<int> &input) {
    
    // dp[i]代表
    vector<int> dp;
    //dp.reserve(input.size());
    dp.resize(input.size());

    for(int i=0; i<input.size(); i++) {
        dp[i] = INT_MAX_;
    }

    dp[0] = 0;
    for(int i=1; i<input.size(); i++) {
        for(int j=0; j<i; j++) {
            if(dp[j] != INT_MAX_ && (input[j]+j) >= i) {
                dp[i] = dp[j]+1;
                break;
            }
        }
    }

    
    //for(auto &v : dp) {
    //    cout << " " << v;
    //}
    return dp[input.size()-1];
}

int getMinSkip2(const vector<int> &input) {

    int steps=0;
    int start=0, end=0, fastest = 0;

    while(end<(input.size()-1)) {
        steps++;
        fastest = end;

        for(int i=start; i<=end; i++) {
            if( (input[i] + i) > fastest) {
                fastest = input[i]+i;
            }
        }
        start = ++end;
        end = fastest;
    }
    return steps;

    
}

int main() {
    vector<int> input_array = {3,1,2,1,1};

    cout << getMinSkip(input_array) << endl;
    cout << getMinSkip2(input_array) << endl;
    return 0;
}

