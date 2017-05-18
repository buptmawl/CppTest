
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <queue> 
#include <stdio.h>
using namespace std;

// clang++ -std=c++11 -stdlib=libc++ median_nums_two_sorted.cc && ./a.out

struct TreeNode {
    public:
        TreeNode* left;
        TreeNode* right;
        int value;
    public:
        TreeNode( int val, TreeNode* l=NULL, TreeNode* r=NULL){
            left=l;
            right=r;
            value=val;
        }
};

TreeNode* createTree() {

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(3, node6, node7);
    TreeNode* node1 = new TreeNode(1, node2, node3);

    return node1;
}

// top to down
void resolve(TreeNode* root, vector<int> &tmp) {
    tmp.push_back(root->value);
    if (root->left == NULL && root->right == NULL) {
            for (auto &m : tmp) {
                cout << m << " ";
            }
        cout <<  endl;
    }
    if (root->left) {
        resolve(root->left, tmp);
    } 
    if (root->right) {
        resolve(root->right, tmp);
    } 
    tmp.pop_back();
}

// level to level
void resolve2(TreeNode* root) {
    std::queue<TreeNode*> queue_level;

    queue_level.push(root);

    vector<TreeNode*> vec_tmp;
    while(1) {
            while(!queue_level.empty()) {
                    vec_tmp.push_back(queue_level.front()); 
                    queue_level.pop();

            }
            for(auto &m :vec_tmp) {
                    cout << m->value << " " ;
                    if(m->left) {
                            queue_level.push(m->left);
                    }
                    if(m->right) {
                            queue_level.push(m->right);
                    }
            }
            cout << endl;
            vec_tmp.clear();
            if (queue_level.empty()) {
                break;
            }
    }

    return;
    
}

int main() {

    TreeNode* node = createTree();
    vector<int> tmp;
    cout << "traverse tree from top to down" << endl;
    resolve(node, tmp);

    cout << "traverse tree from level to level" << endl;
    resolve2(node);

    return 0;
}

