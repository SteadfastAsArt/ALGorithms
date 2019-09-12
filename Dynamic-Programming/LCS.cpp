/* Longest Common Subsequence 
 * -------------------------------
 * Definition: A subsequence is a sequence that appears in the same relative order, 
 * but not necessarily contiguous.
 * 
 * Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. 
 * 
 * Solving:
 * Brute force: O(n*2^n)
 * DP: O(n^2) roughly
 * 
 */

#include<bits/stdc++.h>
using namespace std;


// L[i][j]: length of LSC(a[0..i-1], b[0..j-1])

int LCS(string a, string b)
{
    size_t m = a.length(), n = b.length();
    int L[m+1][n+1];
    memset(L, 0, sizeof(int) * ((m+1)*(n+1)));

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // If find equal digit, update by both stepping back plus one
            // else inherit the nearest value
            L[i][j] = a[i-1] == b[j-1] ? L[i-1][j-1] + 1 : max(L[i-1][j], L[i][j-1]);
        }
    }

    return L[m][n];
}


int main(){
    string a, b;
    cin >> a >> b;
    int ans = LCS(a, b);
    
    cout << ans << endl;
    
    return 0;
}
