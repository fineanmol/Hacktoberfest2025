// Set Matrix Zeroes

// Problem: Set entire row and column to 0 if an element is 0.

// Solution:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false, firstColZero = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) firstColZero = true;
        }
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) firstRowZero = true;
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowZero) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[0][j] = 0;
            }
        }
        if (firstColZero) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};