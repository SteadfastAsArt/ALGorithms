/* 
 * Knapsack Problem:
 * ------------------------
 * Definition: 
 * Given a set of n items, each with a weight w_i and a value v_i, 
 * determine the number of each item to include in a collection so that 
 * the total weight is less than or equal to a given limit W and the total 
 * value is as large as possible.
 * 
 * Solving:
 * Brute force: O(2^n)
 * DP: O(n*W) [bottom-up manner]
 * 
 * */



#include<bits/stdc++.h>
using namespace std;
#define push_back pb


// K[n][c]: maximum value achieved weight <= c using items up to n
int KnapSack(int num_item, int C, vector<int>w, vector<int>v ){
    int K[num_item+1][C+1];
    memset(K, 0, sizeof(int) * ((num_item+1)*(C+1)) );
    for(int n = 1; n <= num_item; n++)
    {
        for(int c = 1; c <= C; c++)
        {
            // With certain number of items n and certain capacity c,
            // if it can be placed, compare the value between pack / non-pack,
            // else inherit from the n-1 item status (non-pack that is)
            // **note that in "pack" condition, vital to go back to weight state "(n-1, c - v[n-1])"
            K[n][c] = w[n-1] <= c ? max(K[n-1][ c - v[n-1] ] + v[n-1], K[n-1][c]) : K[n-1][c];
        }
    }

    return K[num_item][C];
}


int main(){
    int C, num_item;
    cin >> num_item >> C;
    vector<int> v, w;

    for(int i = 0; i < num_item; i++){
        int tmp;
        cin >> tmp;
        v.pb(tmp);
    }
    
    for(int i = 0; i < num_item; i++){
        int tmp;
        cin >> tmp;
        w.pb(tmp);
    }

    int ans = KnapSack(num_item, C, w, v);


    return 0;
}
