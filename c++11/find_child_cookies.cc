#include  "bits/stdc++.h"
#include <vector>
#include <map>
//	#include <unorderd_map>
using namespace std;

class Solution {
public:     
	int findContentChildren(vector<int>& g, vector<int>& s) {
		std::sort(g.begin(), g.end());
		std::sort(s.begin(), s.end());
		int ret_number = 0;
		int interval_pos = 0;
		vector<int>::iterator begin = g.begin();
		vector<int>::iterator it;
		for(it=s.begin(); it != s.end();) {
			vector<int>::iterator bound_it = std::upper_bound(begin, g.end(), *it);
			int satisfy_count = bound_it==g.end() ?  g.size()-(begin-g.begin()) : bound_it - begin;
			int cookies_count = s.end()-it;
			int min_size = satisfy_count>cookies_count ? cookies_count : satisfy_count;

			//std::cout << *it << "ret_number:" << ret_number << " min_size:" << min_size << "cookies_count:" << cookies_count << "satisfy_count:" << satisfy_count << "begin: " << *begin << "bound_it:" << *bound_it  << "\n" ;
			if (satisfy_count == 0) {
				it++;
				continue;
			}
			ret_number += min_size;
			it += min_size;
			begin += min_size;
			if (satisfy_count>=cookies_count || begin == g.end()) break;
		}
		return ret_number;
	} 
};





int main() {
	Solution *obj = new Solution();
	int tmpg[] = {1, 2};
	vector<int> g (tmpg, tmpg+sizeof(tmpg)/sizeof(int));

	int tmps[] = {1, 2, 3};
	vector<int> s (tmps, tmps+sizeof(tmps)/sizeof(int));
	std::cout << obj->findContentChildren(g, s);
	return 0;
}
