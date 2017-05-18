
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

// clang++ -std=c++11 -stdlib=libc++ median_nums_two_sorted.cc && ./a.out

class Node {
    public:
        Node(int val, int indx) {
            _val = val;
            _indx = indx;
        }

        friend bool operator<(const Node& l, const Node& r) {
           return l._val > r._val;
        }

       // Node& operator=(const Node& n) {
       //     _val  = n._val;
       //     _indx = n._indx; 
       //     return *this;
       // }
    public:
        int _val;
        int _indx;
};
//
//struct less1{
//        bool operator()(const Node& a,const Node& b) const{
//                return a._val < b._val;
//                //return a < b;
//        }
//};

vector<int> resolveHeap(vector<vector<int>> input, int k) {
    vector<int> ret;

    vector<Node> vecNode;
    vector<int> index_arr;

    int len = input.size();
    for(int m = 0; m < len; m++) {
        vecNode.push_back(Node(input[m][0], m));
        index_arr.push_back(1);
    }
    //make_heap(vecNode.begin(), vecNode.end(), less1());
    make_heap(vecNode.begin(), vecNode.end());

    while(1) {
        Node topNode = vecNode.front();
        //cout << "=== " << ret.size() << "===top:" << topNode._val << "===vec.size:" << vecNode.size() << " "  ;
        //for(auto &m : vecNode) {
        //    cout << m._val << "-" << m._indx <<" ";
        //}
        //cout  << endl;
        ret.push_back(topNode._val);
        if (ret.size() == k) {
            break;
        }
        pop_heap(vecNode.begin(), vecNode.end());
        vecNode.pop_back();

        if (index_arr[topNode._indx] < input[topNode._indx].size()) {
            vecNode.push_back( Node(input[topNode._indx][index_arr[topNode._indx]], topNode._indx ) );
            push_heap(vecNode.begin(), vecNode.end());
            index_arr[topNode._indx]++;
        }
    }

    
    return ret;
}

vector<int> resolve(vector<vector<int>> input, int k) {
    vector<int> ret;


    int len = input.size();
    vector<int> index_arr;
    int totalsize = 0;
    for(int m=0; m<len; m++) {
        index_arr.push_back(0);
        totalsize += input[m].size();
    }

    if (totalsize<k) return ret;

    while(1) {
            int minval   = INT_MAX;
            int minindex = -1;
            for (int i=0; i <len; i++) {
                if (index_arr[i]< input[i].size() && input[i][index_arr[i]] < minval) {
                    minval = input[i][index_arr[i]];
                    minindex = i;
                }
            }
            ret.push_back(minval);
            index_arr[minindex]++;
            if (ret.size() == k) {
                break;
            }
    }

    return ret;
}

// http://xfhnever.com/2014/10/21/algorithm-findkinarrays/
int main() {

    vector<vector<int>> multi_arr;
    vector<int> vec1 = {1, 5, 10};
    vector<int> vec2 = {2, 7, 11};
    vector<int> vec3 = {3, 8, 12};
    multi_arr.push_back(vec1);
    multi_arr.push_back(vec2);
    multi_arr.push_back(vec3);

    int k = 8;
   vector<int> ret = resolve(multi_arr, k);

   cout << "iterator top " << k << " is: ";
   for(const int& a : ret) {
       cout << a << " " ;
   }
   cout << endl;

    vector<int> ret2 = resolveHeap(multi_arr, k);
    cout << "heap top " << k << " is: ";
    for(const int& a : ret2) {
        cout << a << " " ;
    }
    cout << endl;
    return 0;
}

