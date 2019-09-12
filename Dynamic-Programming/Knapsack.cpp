/* 
 * 
 * 
 * 
 * 
 * */



#include<bits/stdc++.h>
using namespace std;
#define push_back pb


int KnapSack(int num_item, int C, vector<int>w, vector<int>v ){
    int K[num_item+1][C+1];
    memset(K, 0, sizeof(int) * ((num_item+1)*(C+1)) );
    for(int n = 1; n <= num_item; n++)
    {
        for(int c = 1; c <= C; c++)
        {
            K[n][c] = w[i-1] <= c ? max(K[n-1][ c - v[i-1] ] + v[i-1], K[n-1][c]) : K[n-1][c];
        }
    }

    return K[num_item][C];
}


int main(){
    int C, num_item;
    cin >> num_item >> C;
    vector<int> w, v;

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

    int ans = KnapSack()


    return 0;
}
