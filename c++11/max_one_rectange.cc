
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
//  http://blog.csdn.net/jiyanfeng1/article/details/8068676

  
int maxRectInHistogram(int hist[], int n)    
// hist: contains the heights of the bars     
// n: the number of the bars in the histogram.    
{    
        int* arr = new int[n];// 申请一个额外的数组    
        arr[0] = hist[0];    
        int max = hist[0]; // 最大面积    
    
        for(int i=1; i<n; i++)    
        {    
                arr[i] = hist[i];    
                for(int j=i-1; j>=0; j--)    
                        if(arr[j]>arr[i]){    
                                if(arr[j]*(i-j)>max)    
                                        max = arr[j]*(i-j);    
                                arr[j] = arr[i];    
                        }    
                        else break;    
                //数组arr里的元素，保持非递减的顺序。    
        }    
    
        //重新扫描一边，以更新最大面积    
        for(int i=0; i<n; i++)    
                if(arr[i]*(n-i)>max)    
                        max = arr[i]*(n-i);    
        return max;    
}   

int maximalRectangle(vector<vector<int> > &matrix) {  
// max rectangle in a 0-1 matrix  
  
    if(matrix.size()==0) return 0;  
      
    int* hist = new int[matrix[0].size()];  
    memset(hist, 0, sizeof(int)*matrix[0].size());  
      
    int max_ = 0;  
      
    for(int i=0; i<matrix.size(); i++)  
    {  
        for(int j=0; j<matrix[0].size(); j++)  
        {  
            if(matrix[i][j]==1)  
                *(hist+j) += 1;  
            else  
                *(hist+j) = 0;  
        }  
          
        max_ = max(max_, maxRectInHistogram(hist, matrix[0].size()) );  
    }  
      
    return max_;  
}  

int main() {
    vector<vector<int>> vec_input = {
        {0, 1, 0, 1, 0, 0},
        {0, 1, 1, 0, 0, 1},
        {1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
    };
	for (int i=0; i<vec_input.size(); i++) {
		for(int j=0; j<vec_input[i].size(); j++) {
			cout << vec_input[i][j] << " ";
		}
		cout << endl;
	}

	cout << maximalRectangle(vec_input) << endl;
    return 0;
}

