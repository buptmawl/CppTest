
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <queue> 
#include <stdio.h>
using namespace std;

// on mac: clang++ -std=c++11 -stdlib=libc++ xxx.cc && ./a.out

int binary_search(const vector<int> &vec, int target) {
    int low  = 0;
    int high = vec.size()-1;
    int mid;

    while(low+1 < high) {
        mid = low + (high-low)/2;   

        if (vec[mid] == target) {
            low = mid;
        } else if (vec[mid] < target) {
            low = mid;
        } else {
            high = mid;
        }
    }

    if (vec[low] == target) {
        return low;
    } 
    if (vec[high] == target) {
        return high;
    }
    return -1;
}

int lower_bound(const vector<int> &vec, int target) { 
    int low  = -1;
    int high = vec.size();
    int mid;
    while( low + 1 < high) {
       mid = low + (high-low)/2; 
       if (vec[mid] < target) {
            low = mid;
       } else {
            high = mid; 
       }
    }
    return low+1;
}

int upper_bound(const vector<int> &vec, int target) { 
    int low  = -1;
    int high = vec.size();
    int mid;
    while( low + 1 < high) {
       mid = low + (high-low)/2; 
       if (vec[mid] > target) {
            high = mid;
       } else {
            low = mid; 
       }
    }
    return high-1;
}


void resolve(const vector<int> &vec, int target) {
    int ret   = binary_search(vec, target);
    int lower = lower_bound(vec, target);
    int upper = upper_bound(vec, target);
    int std_lower = std::lower_bound(vec.begin(), vec.end(), target) - vec.begin(); 
    int std_upper = std::upper_bound(vec.begin(), vec.end(), target) - vec.begin();

    cout << target << " indx:" << ret << " ,lower: " << lower << " ,upper: " << upper << " std_low: " << std_lower << " std_upper: " << std_upper << endl;
    return;
}

int main() {
    vector<int> input = {1, 2, 4, 5 , 7 , 9, 100};
    for (auto &m : input) {
        cout << " " << m; 
    }
    cout << endl;
    resolve(input, 1);
    resolve(input, 5);
    resolve(input, 6);
    resolve(input, 7);
    resolve(input, 100);

    return 0;
}

