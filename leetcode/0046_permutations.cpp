#include<bits/stdc++.h>
using namespace std;

/**
 * 0046 - Given a list of numbers, return all of the permutations
 * === ===
 * Backtracking
 */

// permute: num[begin..end]
// invariant: num[0..begin-1] have been permuted & fixed
void dfs(vector<int> &nums, int begin, vector<vector<int> > &result)
{
    if(begin >= nums.size())
    {
        result.push_back(nums);
        return;
    }

    for(int i = begin; i < nums.size(); i++)
    {
        swap(nums[begin], nums[i]);
        dfs(nums, begin + 1, result);
        swap(nums[begin], nums[i]);  /* reset */
    }
}

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > res;
    dfs(nums, 0, res);
    return res;
}

