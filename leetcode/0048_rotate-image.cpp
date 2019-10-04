#include<bits/stdc++.h>
using namespace std;

/*
 * 0048 - To rotate a 2-D image 90°
 * Intuitively recognize the loop structure and 
 * find the primitives for it. ---Problems done.
 */
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i <= n / 2; i++)
    {
        for(int j = i; j < matrix[i].size() - i - 1; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = tmp;
        }
    }
}

