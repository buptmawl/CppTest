
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

TreeNode* createTree2() {

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(5);
    TreeNode* node7 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(2, node6, node7);
    TreeNode* node1 = new TreeNode(1, node2, node3);

    return node1;
}

bool isSymmetry(TreeNode* node1, TreeNode* node2) {

    if (node1 == NULL && node2 == NULL) {
        return true;
    } else if (!node1 || !node2) {
        return false;
    } else {
        if (node1->value != node2->value) return false;
        return isSymmetry(node1->left, node2->right) && isSymmetry(node1->right, node2->left);
    }
    return true;

}

int main() {

    TreeNode* node = createTree();
    cout << isSymmetry(node->left, node->right) << endl;

    TreeNode* node2 = createTree2();
    cout << isSymmetry(node2->left, node2->right) << endl;
    return 0;
}

