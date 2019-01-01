
#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;

class Solution {
	public:
		int max_val;
		vector<int> lexicalOrder(int n) {
			max_val = n;
			vector<int> ret;
			for(int i=1; i<=9; i++) {
				dfs(i,i, ret);
			}
			return ret;
		}

		set<int> visited_set;

		void dfs(int prefix, int n, vector<int> &vec_ret) {
			if(n>max_val) return;
			string now = to_string(n);
			if (now.substr(0,(to_string(prefix)).size()) != to_string(prefix)) return;
			if (visited_set.count(n) == 0) {
				visited_set.insert(n);
				vec_ret.push_back(n);
			}
			if (10*n <= max_val) {
				dfs(prefix, 10*n, vec_ret);

				for (int k = 10*n+1; k< 10*n+10; k++) {
					dfs(prefix, k, vec_ret);
				}
			}
		}
};


int main() {
	int n = 13;
	vector<int> a;
	Solution *obj = new Solution();
	a = obj->lexicalOrder(n);
	for(auto& item : a) {
		cout << item << " " ;
	}
	cout << "\n";
	return 0;
}


