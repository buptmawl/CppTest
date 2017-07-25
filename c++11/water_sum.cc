
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


int getSumWater(const vector<int> &input) {
    int res = 0;

    map<int, int> map_right_max_val;

    map_right_max_val[input.size()-1] = 0;

    for(int i=input.size()-2; i>=0; i--) {
        map_right_max_val[i] = max(map_right_max_val[i+1], input[i+1]);
    }
#ifdef _DEBUG_
    map<int, int>::iterator it;
    for (it=map_right_max_val.begin(); it != map_right_max_val.end(); it++) {
        cout << " " << it->first << ":" << it->second << " " ;
    }
    cout << endl;
#endif
    
    int max_left=input[0];
    for(int i=1; i<input.size(); i++) {
       int gap = min(map_right_max_val[i], max_left) - input[i]; 
       if (input[i] > max_left) max_left = input[i];
#ifdef _DEBUG_
       cout << " gap:" << gap << " ";
#endif
       if (gap >0) res += gap;
    }

    return res;
}

int main() {

    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "result: " << getSumWater(input) << endl;
    return 0;
}

