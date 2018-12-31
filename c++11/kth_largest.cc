#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;
class KthLargest {
public:

	KthLargest(int k, vector<int> nums) {
		m_k = k;
		for(auto& item :nums) {
			add(item);
		}
	}

	int add(int val) {
		if (my_queue.size() < m_k) {
			my_queue.push(val);
		} else {
			if(my_queue.top() < val) {
				my_queue.pop();
				my_queue.push(val);
			}
		}
		return my_queue.top();

	}

	std::priority_queue<int, std::vector<int>, std::greater<int>> my_queue;
	int m_k;
};

int main() {
	vector<int> arr = {4,5,8,2};
	KthLargest *kthLargest = new KthLargest(3, arr);
	std::cout << kthLargest->add(3);   // returns 4
	std::cout << kthLargest->add(5);   // returns 5
	std::cout << kthLargest->add(10);  // returns 5
	std::cout << kthLargest->add(9);   // returns 8
	std::cout << kthLargest->add(4);   // returns 8
	return 0;
}

