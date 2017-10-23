
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <queue> 
#include <map> 
#include <stack> 
#include <set> 
using namespace std;

// on mac: clang++ -std=c++11 -stdlib=libc++ xxx.cc && ./a.out
// http://dongxicheng.org/structure/binary_indexed_tree/

//vector<int> input = {-1111,  1, 2, 3, 4, 5, 6};
vector<int> input;
vector<int> tree_arr;
int size;

int lowit(int x) {
	return x&(-x);
}

void init() {
	tree_arr.resize(input.size());
	for (int i=1; i<=size; i++) {
		tree_arr[i] = 0;
	}

	for (int i=1; i<=size; i++) {
		tree_arr[i] = 0;

		for(int k=i-lowit(i)+1; k<=i; k++){
			tree_arr[i] += input[k];
		}
	}
}

int sum(int pos) {
	int ret = 0;
	while(pos>0) {
		ret += tree_arr[pos];
		pos -= lowit(pos);
	}
	return ret;
}

void update(int pos, int val) {

	while(pos <= size) {
		tree_arr[pos] += val;
		pos += lowit(pos);
	}
	return ;
}



int main() {

	input = {-1111,  1, 2, 3, 4, 5, 6};
	size = input.size()-1;

	init();

	for(int i=1; i<=size; i++) {
		cout << "i:" << i << " , sum: " << sum(i) << endl;
	}

    return 0;
}

