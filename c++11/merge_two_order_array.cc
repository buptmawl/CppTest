
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

vector<int> merge(const vector<int> &input) {
    vector<int> res;
    int peak;

    for(int i=1;i<input.size(); i++) {
        if (input[i]>input[i-1] && input[i]>input[i+1]) {
            peak = i;
            break;
        }
    }

    int i,j;
    for(i=0,j=input.size()-1; i<=peak&&j>=peak; ) {
        if (input[i] > input[j]) {
            res.push_back(input[j]);
            j--;
        } else if( input[i] < input[j]) {
            res.push_back(input[i]);
            i++;
        } else {
            res.push_back(input[i]);
            i++;
            j--;
        }
    }

    while(i<=peak) {
        res.push_back(input[i++]);
    }
    while(j>=peak) {
        res.push_back(input[j--]);
    }

    return res;
}

int main() {
    vector<int> input = {2,3,4,6,8,7,4,2,1};
    vector<int> result = merge(input);

    for(auto &v : result) {
        cout << " " << v ;
    }

    return 0;
}

