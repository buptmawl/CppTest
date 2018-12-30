#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int slidingPuzzle(vector<vector<int> >& board) {
		vector<int> node_vec = makeNode(board);
		std::queue<vector<int> > queue_puzzle;
		queue_puzzle.push(node_vec);
		int step = 0;
		bool find_answer = false;
		while(1) {
			if(queue_puzzle.empty())
				break;
			vector< vector<int> > childs_node;
			while(!queue_puzzle.empty()) {
				vector<int> node = queue_puzzle.front();
				queue_puzzle.pop();
				if (check_node(node)) return step;

				for(int direction=0; direction<4; direction++) {
					vector<int> new_node = makeNewNode(direction, node);
					if (!new_node.empty() && _visits_set.count(new_node) == 0) {
						_visits_set.insert(new_node);
						childs_node.push_back(new_node);
					}
				}
			}
			step++;
			for (auto& item : childs_node) {
				queue_puzzle.push(item);
			}
		}
		return -1;
	}

	set<vector<int> > _visits_set;
	// 0:上 1：下 2：左 3：右
	vector<int> makeNewNode(int direction, vector<int>  node) {
		vector<int> ret;
		int zero_index = -1;
		for (int i =0; i<node.size(); i++) {
			if (node[i] == 0) {
				zero_index = i;
				break;
			}
		}
		if (zero_index==-1) return ret;
		int swap_index = -1;
		switch (direction) {
			case 0:{
				       if(zero_index>=3 && zero_index <=5) {
				       	       swap_index = zero_index - 3;
				       }

				       break;
			       }
			case 1:{
				       if(zero_index>=0 && zero_index <=2) {
				       	       swap_index = zero_index + 3;
				       }
				       break;
			       }
			case 2:{
				       if(zero_index!=0 && zero_index !=3) {
				       	       swap_index = zero_index -1;
				       }
				       break;
			       }
			case 3:{
				       if(zero_index!=2 && zero_index !=5) {
				       	       swap_index = zero_index + 1;
				       }
				       break;
			       }
			default: break;
		} 
		if (swap_index >=0 && swap_index <=5) {
			ret = node;
			swap(ret[zero_index], ret[swap_index]);
		}
		//std::cout << "in make new node" << zero_index << " " << swap_index << "\n";
		//std::copy (node.begin(), node.end(), ostream_iterator<int>(std::cout, " "));
		//std::cout << "\n";
		//std::copy (ret.begin(), ret.end(), ostream_iterator<int>(std::cout, " "));
		//std::cout << "\n";
		return ret;
	}
	
	vector<int> makeNode(vector<vector<int> >& board) {
		vector<int> ret_vec;
		for(int row=0; row<board.size(); row++) {
			for(int col=0; col<board[row].size(); col++) {
				ret_vec.push_back(board[row][col]);
			}
		}
		return ret_vec;
	}

	int check_node(vector<int>  node) {
		if(node[0] == 1 && node[1] == 2 && node[2] == 3 
				&& node[3] == 4 && node[4] == 5 && node[5] == 0) 
			return true;
		return false;
	}
	
	int check(vector<vector<int> >& board) {
		if(board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 
				&& board[1][0] == 4 && board[1][1] == 5 && board[1][2] == 0) 
			return true;
		return false;
	}
};

int main() {
	int i,j,k;
	//vector<vector<int> > board = {{1, 2, 3}, {4, 0, 5}};
	//vector<vector<int> > board = {{1, 2, 3}, {5, 4, 0}};
	//vector<vector<int> > board = {{4, 1, 2}, {5, 0, 3}};
	vector<vector<int> > board = {{3, 2, 4}, {1, 5, 0}};
	Solution *obj = new Solution();
	std::cout << obj->slidingPuzzle(board);
	return 0;
}
