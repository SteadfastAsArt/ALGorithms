#include<bits/stdc++.h>
using namespace std;


/*
 * 0076 - Given two strings, there are 3 ways to operate on 
 * the first one to make it identical to the second one, which 
 * are "insert", "delete", "replace". It is required to find 
 * minimal number of operations.
 * === ===
 * DP:
 * the state dp[i][j] to be the minimum number of operations 
 * to convert word1[0..i) to word2[0..j), then consider all the 
 * situations and propagate up.
 */

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    // for the base case to convert from a string to an empty one:
    // the min(|op|) = len(string), simply doing deletion.
    for(int i = 1; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for(int j = 1; j <= n; j++)
    {
        dp[0][j] = j;
    }

    // table filling stage
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(word1[i-1] == word2[j-1])  // 1) nop
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else  // | replace | delete | insert |
            {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }
    }

    return dp[m][n];
}
