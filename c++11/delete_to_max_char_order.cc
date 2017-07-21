
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

string getDeleteMaxOrderStr(const string &input, int k) {
    string ret;
    set<int> deleted;
    int last_deleted  = input.size();
    
    for (int i=(k-1); i>=0; i--) {
        bool found = false;
        for(int j=i+1; j<input.size(); j++) {
            if(deleted.find(j) != deleted.end()) continue;
            if (input[j]>input[i]) {
                found = true;
                deleted.insert(i);
                break;
            } else if(input[j] < input[j+1]) {
                found = true;
                deleted.insert(j);
                last_deleted = j;
                break;
            }
        }

        if (!found) {
            deleted.insert(--last_deleted);
        }
    }

    for(auto &v : deleted) {
        cout << "val: " << v ;
    }
    cout << endl;

    for (int i=0; i<input.size(); i++) {
        if (deleted.find(i) == deleted.end()) {
            ret += input[i];
        }
    }

    return ret;
}

int main() {

    string input="cbdaba", k="3";
    cout << "please input string:" << endl;
    cin >> input;
    cout << "please input k:" << endl;
    cin >> k;


    cout << getDeleteMaxOrderStr(input, stoi(k)) << endl;
    return 0;
}


