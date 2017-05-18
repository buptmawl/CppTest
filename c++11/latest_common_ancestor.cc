
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <queue> 
#include <stdio.h>
using namespace std;

// clang++ -std=c++11 -stdlib=libc++ xxx.cc && ./a.out


struct TreeNode {
    public:
        TreeNode* left;
        TreeNode* right;
        int value;
    public:
        TreeNode(){
            left=NULL;
            right=NULL;
            value=0;
        }
        TreeNode( int val, TreeNode* l=NULL, TreeNode* r=NULL){
            left=l;
            right=r;
            value=val;
        }
};

TreeNode* getLca(TreeNode* root, TreeNode* l, TreeNode* r) {
    
    if (root == NULL) return NULL;
    if ( root == l || root == r) {
        return root;
    }

    TreeNode* node1 = getLca(root->left, l , r);
    TreeNode* node2 = getLca(root->right, l , r);

    if (node1 && node2) {
        return root;
    } else if (node1) { 
        return node1;
    } else if ( node2) {
        return node2;
    } else {
        return NULL;
    }
}

void resolve(TreeNode* root, TreeNode* l, TreeNode* r) {
    TreeNode* lca = getLca(root, l , r);
    cout << "l:" << l->value << " r:" << r->value << " lca:" << lca->value << endl;
}

int main() {
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(3, node6, node7);
    TreeNode* node1 = new TreeNode(1, node2, node3);

    resolve(node1, node6, node7);
    resolve(node1, node4, node5);
    resolve(node1, node1, node5);
    resolve(node1, node3, node2);
    resolve(node1, node2, node6);

    return 0;
}

