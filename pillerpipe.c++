#include <bits/stdc++.h>
using namespace std;

int n, maxi = INT_MIN;

void solve(vector<int> arr, vector<int> vis, int p1, int p2)
{
    if( p1 == p2 )
    {
        maxi = max( maxi, p1 );    
    }
    
    for(int i = 0; i < n; i++ )
    {
        if(!vis[i])
        {
            vis[i] = 1;
             solve( arr, vis, p1 + arr[i], p2 );
             solve( arr, vis, p1, p2 + arr[i] );
            vis[i] = 0;
        }
    }
    
    
    
}
int main()
{
    int t, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        
        vector<int> arr;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i ++ )
        {
            cin >> x;
            arr.push_back(x);
        }
       
        solve(arr, vis, 0, 0);
        cout << " Maximum sum possible "<< maxi << endl;
    }
    
}
