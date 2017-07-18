
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

void sDisplay(TreeNode* node) {

    queue<TreeNode*> queue_node;
    queue_node.push(node);
    cout << node->value << " " ;

    bool isToLeft = true;

    while(1) {
        if(queue_node.empty()) break;
        vector<TreeNode*> vec_node;

        while(!queue_node.empty()) {
            TreeNode* nodeval = queue_node.front();
            queue_node.pop();

            if (nodeval->left) {
                vec_node.push_back(nodeval->left);
            }

            if (nodeval->right) {
                vec_node.push_back(nodeval->right);
            }
        }

        for (int i=0; i<vec_node.size(); i++) {
            int pos=i;
            if (!isToLeft) {
                pos=vec_node.size()-1-i;
            }
            cout << vec_node[pos]->value << " " ;
            queue_node.push(vec_node[i]);
        }

        isToLeft = !isToLeft;
    }
}

int main() {

    TreeNode* node = createTree();
    sDisplay(node);
    return 0;
}

