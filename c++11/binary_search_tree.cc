
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

TreeNode* createTree2() {

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(3, node6, node7);
    TreeNode* node1 = new TreeNode(1, node2, node3);

    return node1;
}
TreeNode* createTree() {

    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(5);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(6, node6, node7);
    TreeNode* node1 = new TreeNode(4, node2, node3);

    return node1;
}

int  getMax(TreeNode* node) {
    int ret = 0;
    TreeNode *tmp = node->left;
    if (!tmp) return -1;

    while(tmp) {
        if (tmp->value > ret) {
            ret = tmp->value;
        }
        tmp = tmp->right;
    }
    return ret;

}

int  getMin(TreeNode* node) {
    int ret = 0;
    TreeNode *tmp = node->right;
    if (!tmp) return -1;

    while(tmp) {
        if (tmp->value > ret) {
            ret = tmp->value;
        }
        tmp = tmp->left;
    }
    return ret;

}

bool isBinarySearchTree(TreeNode* node) {
    if (!node) return true;
    TreeNode *node1 = node->left;
    TreeNode *node2 = node->right;

    if (node1 == NULL && node2 == NULL) {
        return true;
    } else {
        int val1 = getMax(node);
        int val2 = getMin(node);
        //cout << val1 << " " << val2 << endl;
        if ( (val1 != -1 && val1 > node->value) || (val2 != -1 && val2 < node->value) ) return false;
        return isBinarySearchTree(node1) && isBinarySearchTree(node2);
    }
    return true;

}

bool isBinarySearchTree2(TreeNode* node, int val_min, int val_max) {
    if (!node) return true;
    
    if (node->value > val_max || node->value < val_min) {
        return false;
    } else {
        return isBinarySearchTree2(node->left, val_min, node->value) && isBinarySearchTree2(node->right, node->value, INT_MAX);
    }

}

int main() {

    TreeNode* node = createTree();
    cout << isBinarySearchTree(node) << endl;
    cout << isBinarySearchTree2(node, INT_MIN, INT_MAX) << endl;

    TreeNode* node2 = createTree2();
    cout << isBinarySearchTree(node2) << endl;
    cout << isBinarySearchTree2(node2, INT_MIN, INT_MAX) << endl;

    return 0;
}

