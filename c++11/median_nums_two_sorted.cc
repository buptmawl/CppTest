#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int findKthNum(std::vector<int>::iterator it1, int size1, std::vector<int>::iterator it2, int size2, int k) {
		if(size1>size2) {
			return findKthNum(it2, size2, it1, size1, k);
		}
		if (size1 == 0) return *(it2+(k-1));
		if (k == 1) return min(*it1, *it2);
		int leftmid = min(size1, k/2);
		int rightmid = k-leftmid;
		if ( *(it1+leftmid-1) < *(it2+rightmid-1)) return findKthNum(it1+leftmid, size1-leftmid, it2, size2, k-leftmid);
		else if ( *(it1+leftmid-1) > *(it2+rightmid-1)) return findKthNum(it1, size1, it2+rightmid, size2-rightmid, k-rightmid);
		else return *(it1+leftmid-1);
}


int resolve(std::vector<int> v1, std::vector<int> v2) {
	int len = v1.size()+v2.size();
	int mid = len/2;
	if (len & 0x1 ) {
		return findKthNum(v1.begin(), v1.size(), v2.begin(), v2.size(), mid+1);
	} else {
		return (findKthNum(v1.begin(), v1.size(), v2.begin(), v2.size(), mid) + findKthNum(v1.begin(), v1.size(), v2.begin(), v2.size(), mid+1))/2;
	}
}

int main() {
	    std::vector<int> v1 = {1, 9, 10, 11, 100};
	    std::vector<int> v2 = {2, 3, 4, 6};
		std::cout << resolve(v1, v2) << '\n';
		return 0;
}
