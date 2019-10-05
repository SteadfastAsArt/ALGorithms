#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3;

/*
 * 0011 - To find the maximum volume of water given the 
 * bars diagram.
 * === ===
 * This problem can be solved in O(N) with two pointers.
 */

int maxArea(vector<int>& height) {
    int v = 0;
    for(int i = 0; i < height.size(); i++)
        for(int j = 0; j < height.size(); j++)
        {
            if(i < j)
            {
                int v_now = min(height[i], height[j]) * (j - i);
                cout << v_now << " " << endl;
                if(v < v_now) v = v_now;
            }

        }
    return v;
}

int main(){
    int arr[9] = {1, 8, 6, 2, 5, 4, 1, 3, 7};
    vector<int> h(arr, arr+9);
    int res = maxArea(h);
    cout << res;
    
    return 0;
}
