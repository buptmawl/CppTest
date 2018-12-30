#include  <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution { 
public:     
	long integerReplacement(long n) {
		min_step = 0;
		vector< vector<long> > vec_ret;
		vector<long> vec_tmp;
		dfs(n, vec_tmp, vec_ret); 
		//std::cout << vec_ret.size() << " : ";
		//for (long i=0; i< (vec_ret).size(); i++) {
		//	for (long j=0; j<(vec_ret[i]).size(); j++) {
		//		std::cout << vec_ret[i][j] << " -> " ;
		//	}
		//	std::cout <<vec_ret[i].size() << std::endl;
		//}
		return min_step;
	} 
private:
	void dfs(long n, vector<long>& vec_tmp, vector< vector<long> >& vec_ret) {
		//if (n <=0 || (min_step!=0 && (vec_tmp).size() > min_step)) {
		if (n <=0 ) {
			return ;
		}
		if (n == 1) {
			if ((vec_tmp).size()<min_step || min_step == 0) {
				min_step = (vec_tmp).size();
			}
			vec_ret.push_back(vec_tmp);
			return ;
		}
		if (n%2 == 0) {
			vec_tmp.push_back(n/2);
			dfs(n/2, vec_tmp, vec_ret);
			vec_tmp.pop_back();
		} else {
			vec_tmp.push_back(n-1);
			dfs(n-1, vec_tmp, vec_ret);
			vec_tmp.pop_back();
			if (n != 2<<31-1) {
				vec_tmp.push_back(n+1);
				dfs(n+1, vec_tmp, vec_ret);
				vec_tmp.pop_back();
			}
		}
		return ;
	}
	long min_step;
	
};

int main() {
	long n;
	cin >> n;
	Solution *obj = new Solution();
	std::cout << obj->integerReplacement(n);
	return 0;
}
