
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <queue> 
#include <stdio.h>
using namespace std;

// on mac: clang++ -std=c++11 -stdlib=libc++ xxx.cc && ./a.out

void resolve(const vector<vector<int>>& matrix, int val) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int begin = -1;
        int end = rows*cols;
        int mid;

        while( begin + 1 < end) {
                mid = begin + (end-begin)/2;

                if (matrix[mid/cols][mid%cols] < val) {
                        begin = mid;
                } else {
                        if (matrix[mid/cols][mid%cols] == val) {
                            break;
                        }
                        end = mid;
                }
        }
        if (matrix[(mid)/cols][(mid)%cols] == val) {
                cout << val << " found! row:" << mid/cols << ",col:" << mid%cols << endl;
        } else {
                cout << val << " not found" << endl;
        }
        return ;
}

void resolve2(const vector<vector<int>>& matrix, int val) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0;
        int col = cols-1;
        bool find = false;
        while( row < rows && col >= 0 ) {
            if (matrix[row][col] == val) {
                find = true;
                break;
            } else if (matrix[row][col] < val) {
                ++row;
            } else {
                --col;
            }
        }
        if (find) {
                cout << val << " found! row:" << row << ",col:" << col << endl;
        } else {
                cout << val << " not found" << endl;
        }
        return ;
}

int main() {
    vector<vector<int>> matrix = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9},
        };


    resolve(matrix, 6);
    resolve(matrix, 4);
    resolve(matrix, 1);
    resolve(matrix, 5);
    resolve(matrix, 29);
    resolve(matrix, 2);

    vector<vector<int>> matrix2 = {
                {1, 3, 9},
                {2, 4, 11},
                {5, 7, 29},
        };
    resolve2(matrix2, 6);
    resolve2(matrix2, 4);
    resolve2(matrix2, 1);
    resolve2(matrix2, 5);
    resolve2(matrix2, 29);
    resolve2(matrix2, 2);
    return 0;
}

