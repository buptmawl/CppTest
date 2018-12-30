#include  "bits/stdc++.h"
#include <vector>
using namespace std;

class Solution { 
	public:     
		int integerReplacement(int n) {
			min_step = 0;
			//std::cout << n << std::endl;			
			if (n == 1) return 1;
			vector< vector<int> > vec_ret;
			vector<int> vec_tmp;
			vec_tmp.push_back(n);
			bool ret = dfs(n, vec_tmp, vec_ret); 
			std::cout << vec_ret.size() << " xx ";
			for (int i=0; i< (vec_ret).size(); i++) {
				for (int j=0; j<(vec_ret[i]).size(); j++) {
					std::cout << vec_ret[i][j] << " -> " ;
				}
				std::cout << std::endl;
			}
			return min_step;
		} 
	private:
		bool dfs(int n, vector<int> vec_tmp, vector< vector<int> >& vec_ret) {
			if (n <=0 || (min_step!=0 && (vec_tmp).size() > min_step)) {
				return false;
			}
			if (n == 1) {
				//for (int k=0; k<vec_tmp.size(); k++) {
				//	std::cout << vec_tmp[k] << " -> ";
				//}
				//std::cout << std::endl;
				if ((vec_tmp).size()<min_step || min_step == 0) {
					min_step = (vec_tmp).size();
				}
				vec_ret.push_back(vec_tmp);
				return true;
			}
			if (n%2 == 0) {
				vec_tmp.push_back(n/2);
				dfs(n/2, vec_tmp, vec_ret);
				vec_tmp.pop_back();
			} else {
				vec_tmp.push_back(n-1);
				dfs(n-1, vec_tmp, vec_ret);
				vec_tmp.pop_back();
				vec_tmp.push_back(n+1);
				dfs(n+1, vec_tmp, vec_ret);
				vec_tmp.pop_back();
			}
		}
		int min_step;
	
};

int main() {
	int n;
	cin >> n;
	Solution *obj = new Solution();
	std::cout << obj->integerReplacement(n);
	return 0;
}
