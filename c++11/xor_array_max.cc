
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
        vector<uint64_t> set_value;

    public:
        TreeNode( int val, TreeNode* l=NULL, TreeNode* r=NULL){
            left=l;
            right=r;
            value=val;
        }
};

uint64_t resolution(uint64_t from, uint64_t to) {
    TreeNode* root = new TreeNode(-1);
    uint64_t max_ret_value=0;

    for (uint64_t i=from; i<=to; i++) {
        TreeNode *tmp = root;
        for(int k=63; k>=0; k--) {
            if(!tmp->left) {
                tmp->left = new TreeNode(-1);
            }
            if(!tmp->right) {
                tmp->right = new TreeNode(-1);
            }
            int val = 0;
            if (i & ((uint64_t)1 << k)) val = 1;

            if(val == 1) {
                tmp->right->set_value.push_back(i);
                tmp->value = 1;
                tmp=tmp->right;
            } else {
                tmp->left->set_value.push_back(i);
                tmp->value = 0;
                tmp=tmp->left;
            }
        }
    }


    for (uint64_t i=from; i<=to; i++) {

        TreeNode *tmp = root;
        vector<uint64_t> prev_set_intersections;

        for(int k=63; k>=0; k--) {
            vector<uint64_t> set_tmp;
            int val = 0;
            if (i & ((uint64_t)1 << k)) val = 1;

            bool toLeft    = true;
            bool needbreak = false;
            if (tmp->right->set_value.empty()){
                toLeft = true;
                needbreak = true;
            }  else if (tmp->left->set_value.empty()){
                toLeft = false;
                needbreak = true;
            } else {
                if (val == 1) {
                    toLeft = true;
                } else {
                    toLeft = false;
                }
            }
            if (toLeft) {
                if (k != 63) {
                    std::set_intersection(prev_set_intersections.begin(), prev_set_intersections.end(), tmp->left->set_value.begin(), tmp->left->set_value.end(), std::back_inserter(set_tmp));
                }
                prev_set_intersections=tmp->left->set_value;
                tmp=tmp->left;
            } else {
                if (k != 63) {
                    std::set_intersection(prev_set_intersections.begin(), prev_set_intersections.end(), tmp->right->set_value.begin(), tmp->right->set_value.end(), std::back_inserter(set_tmp));
                }
                prev_set_intersections=tmp->right->set_value;
                tmp=tmp->right;
            }

            //cout << "-from:" << i << " --" << k << "---" << set_tmp.size() << endl;
            if ((k != 63 && set_tmp.size() == 1)) {
                uint64_t max_val = set_tmp[0] ^ i;
                cout << "===found======= " << "from:" << i << ", to:" << set_tmp[0] << " " << max_val << endl;
                if (max_val > max_ret_value) {
                    max_ret_value = max_val;
                }
                break;
            }
        }
    }
    return max_ret_value;
}

int main() {
    cout << "input from , to" << endl;

    string from, to;
    cin >> from;
    cin >> to;

    cout << (1^2) << " " << (1^3) << " " << (2^3) << endl;
    cout << from << " " << to << ", max: " << resolution(stoull(from), stoull(to)) << endl;


    return 0;
}

