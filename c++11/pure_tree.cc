
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

bool isPure(TreeNode* node) {
    if (!node) return true;

    queue<TreeNode*> queue_node;
    queue_node.push(node);

    bool isSign = false;
    while(!queue_node.empty()) {
        TreeNode *tmp = queue_node.front();
        queue_node.pop();

        if (!tmp) {
            isSign = true;
        } else if (isSign) {
            return false;
        } else {
            queue_node.push(tmp->left);
            queue_node.push(tmp->right);
        }
    }
    return true;
}

int main() {

    TreeNode* node = createTree();
    cout << isPure(node) << endl;

    return 0;
}

