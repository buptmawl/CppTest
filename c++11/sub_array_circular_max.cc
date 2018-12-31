#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

class Solution {
	public:
		int maxSubarraySumCircular(vector<int>& A) {
			int m = *max_element(A.begin(), A.end());
			if (m<=0) return m;
			if (A.size() == 1) {
				return A[0];
			}
			int total_sum = accumulate(A.begin(), A.end(), 0);
			int sum_positive = 0;
			int sum_negative = 0;
			int tmp_sum = 0;
			for (auto& item :A) {
				cout << item << " " ;
				tmp_sum = max(0, item+tmp_sum);
				sum_positive = max(sum_positive, tmp_sum);
			}
			cout << ":" << tmp_sum;
			for (auto& item :A) {
				tmp_sum = min(0, item+tmp_sum);
				sum_negative = min(sum_negative, tmp_sum);
			}

			cout << "->" << sum_negative << " " << sum_positive << endl;

			//for (int i=0; i<A.size(); i++) {
			//	for (int j=i; j<A.size(); j++) {
			//		int tmp =0;
			//		if (i == j) {
			//			tmp=A[i];
			//		} else {
			//			for(int k=i; k<=j; k++) {
			//				tmp += A[k];
			//			}
			//		}
			//		if (sum_positive < tmp) {
			//			sum_positive = tmp;
			//		}
			//	}
			//}
			//for (int i=1; i<A.size()-1; i++) {
			//	for (int j=i; j<A.size()-1; j++) {
			//		int tmp =0;
			//		if (i == j) {
			//			tmp=A[i];
			//		} else {
			//			for(int k=i; k<=j; k++) {
			//				tmp += A[k];
			//			}
			//		}
			//		if (sum_negative > tmp) {
			//			sum_negative = tmp;
			//		}
			//	}
			//}
			return max(total_sum-sum_negative, sum_positive);

		}
};

// 1 -1 -1 1 -1

int main() {
	vector<int> a ;
	a = {-1,2,3,1};
	std::cout << (Solution().maxSubarraySumCircular(a) == 6) << "\n";
	a = {1,-2,3,-2};
	std::cout << (Solution().maxSubarraySumCircular(a) == 3) << "\n";
	a = {5,-3,5};
	std::cout << (Solution().maxSubarraySumCircular(a) == 10) << "\n";
	a = {3,-1,2,-1};
	std::cout << (Solution().maxSubarraySumCircular(a) == 4) << "\n";
	a = {3,-2,2,-3};
	std::cout << (Solution().maxSubarraySumCircular(a) == 3) << "\n";
	a = {-2,-3,-1};
	std::cout << (Solution().maxSubarraySumCircular(a) == -1) << "\n";
	a = {-2,-3,-1};
	std::cout << (Solution().maxSubarraySumCircular(a) == -1) << "\n";
	return 0;
}


