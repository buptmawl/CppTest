#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    	_nums = nums;
		std::vector<int>::iterator result;
		result = std::max_element(_nums.begin(), _nums.end());
		TreeNode *root = new TreeNode(*result);
		int maxIndex = std::distance(_nums.begin(), result);
		root->left  = doDeep(0, maxIndex);
		root->right = doDeep(maxIndex+1, _nums.size());
		return root;
    }

    TreeNode* doDeep(int leftIndex, int rightIndex) {
    	if(leftIndex<0 || leftIndex>=rightIndex) {
    		return NULL;
    	}


		std::vector<int>::iterator result;
		if (rightIndex - leftIndex == 1) {
			result = _nums.begin()+leftIndex;
		} else {
			result = std::max_element(_nums.begin()+leftIndex, _nums.begin()+rightIndex);
		}
		TreeNode *node = new TreeNode(*result);
    	if (leftIndex == rightIndex-1) {
    		return node;
    	}

    	int maxIndex = std::distance(_nums.begin(), result);
    	if (maxIndex > leftIndex) {
				node->left  = doDeep(leftIndex, maxIndex);
    	}
    	if (rightIndex > maxIndex+1) {
			node->right = doDeep(maxIndex+1, rightIndex);
    	}
    	return node;
    }

	void printTree(TreeNode *node) {
		queue<TreeNode*> queueNode;
		queueNode.push(node);
		while(1) {

			vector<TreeNode*> tmpVec;
			while(!queueNode.empty()) {
				TreeNode *node = queueNode.front();
				queueNode.pop();
				cout << " " << node->val;
				if (node->left) {
					tmpVec.push_back(node->left);
				}
				if (node->right) {
					tmpVec.push_back(node->right);
				}
			}
			if (tmpVec.empty()) {
				break;
			}
			cout << endl;
			for(auto& v :tmpVec) {
				queueNode.push(v);
			}
		}
		return ;
	}

private:
	vector<int> _nums;
};

int main() {
	vector<int> board = {3,2,1,6,0,5};
	Solution *obj = new Solution();
	TreeNode * node =  obj->constructMaximumBinaryTree(board);
	obj->printTree(node);
	return 0;
}
