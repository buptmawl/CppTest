
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <stdio.h>
using namespace std;

// clang++ -std=c++11 -stdlib=libc++ median_nums_two_sorted.cc && ./a.out


int merge(vector<char>& vec, int left, int mid, int right) {
    int ret = 0;
    vector<char> vectmp;

    int k = left;
    int j = mid+1;
    while(k<=mid && j <= right) {
        if (vec[k] <= vec[j]) {
            vectmp.push_back(vec[k++]);
        } else {
            ret += (mid-k+1);
            vectmp.push_back(vec[j++]);
        }
    }
    while(k<=mid) {
        vectmp.push_back(vec[k++]);
    }
    while(j<=right) {
        vectmp.push_back(vec[j++]);
    }

    for(int m=0; m<vectmp.size(); m++) {
       vec[left+m] = vectmp[m]; 
    }
   
    return ret;
}

int mergeSort(vector<char>& vec, int left, int right) {
    int tmp = 0;
    if (left >= right) return tmp;
    int mid = left + (right-left)/2;

    tmp += mergeSort(vec, left, mid);
    tmp += mergeSort(vec, mid+1, right);
    tmp += merge(vec, left, mid, right);
    return tmp;
}

int revers(vector<char>& vec) {
    int len = vec.size();
    if (len == 0) {
        return 0;
    }

    int ret = 0;
    ret += mergeSort(vec, 0, len-1);
    return ret;
}

int resolve(const std::string& str) {
    vector<char> vec;
    for (int i=0; i<str.size(); i++) {
        vec.push_back(str[i]);
    }

    cout << "before:";
    for (const char& c : vec) {
        cout << c ;
    }
    cout << "    ";

    int ret = revers(vec);

    cout << "after:";
    for (const char& c : vec) {
        cout << c ;
    }
    cout << "    ";

    return ret;
}

int main() {

    cout << resolve("sadhas") << endl;
    cout << resolve("abc") << endl;
    cout << resolve("dcba") << endl;
    cout << resolve("624387436") << endl;

    return 0;
}

