
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <stdio.h>
using namespace std;

// clang++ -std=c++11 -stdlib=libc++ median_nums_two_sorted.cc && ./a.out

char resolve(const std::string input) {
    int counters[256];
    //bzero(counters, sizeof(counters));
    memset(counters, 0, sizeof(counters));

    for(const char& c : input) {
            counters[c-'0'] ++;;
    }


    for(const char& c : input) {
            if( counters[c-'0'] == 1) {
                return c;
            }
    }
    return '\0';
}

int main() {

    cout << resolve("aaa") << endl;
    cout << resolve("google") << endl;
    return 0;
}

