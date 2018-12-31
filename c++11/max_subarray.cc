
#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int tmp = 0;
			int max_sum = INT_MIN;

			for(auto& item :nums) {
				tmp += item;
				if (tmp > max_sum) {
					max_sum = tmp;
				}
				if (tmp <0) {
					tmp = 0;
				}
			}
			return max_sum;

		}
};

int main() {
	vector<int> a ;
	a = {-2,1,-3,4,-1,2,1,-5,4};
	std::cout << (Solution().maxSubArray(a) == 6) << "\n";
	return 0;
}


