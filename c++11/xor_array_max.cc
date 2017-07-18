
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

struct TreeNode{
    public:
        TreeNode* left;
        TreeNode* right;
        int value;
        vector<int> vector_value;
    public:
        TreeNode( int val, TreeNode* l=NULL, TreeNode* r=NULL){
            left=l;
            right=r;
            value=val;
        }
};

uint64_t resolution(uint64_t from, uint64_t to) {
    
    for (uint64_t i=from; i<=from; i++) {
        for(int k=63; k>=0; k--) {
           int val = 0;
           if (from & ((uint64_t)1 << k)) val = 1;
           cout <<  val << " " ;
        }
    }
    return 123;
}

int main() {
    cout << "input from , to" << endl;

    string from, to;
    cin >> from;
    cin >> to;

    cout << from << " " << to << ", max: " << resolution(stoull(from), stoull(to)) << endl;


    return 0;
}

