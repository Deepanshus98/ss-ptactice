#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0 ; i < n ; i++ )
    {
        for(int j = 0 ; j < m ; j++ )
        {
            cin >> mat[i][j];
        }
    }
    
    map<string, int> mp;
    
    for(int i = 0; i < n ; i++ )
    {
        string temp = "";
        for(int j =0 ; j < m; j++ )
        {
            temp += to_string(mat[i][j]);
        }
        if(mp.find(temp) != mp.end() )
        {
            int oldFreq = mp[temp];
            mp[temp] = oldFreq + 1 ;
        }
        else
            mp[temp] = 1;
    }
    int ans = INT_MIN;
    
    for(auto it : mp)
    {
        int num_zeroes = 0;
        for(int i = 0 ; i < (int)it.first.length() ; i ++ )
        {
            if(it.first[i] == '0') num_zeroes++;
        }
        if( num_zeroes <= k && (k - num_zeroes)%2 == 0 )
            ans = max(it.second, ans);
    }
    
    cout<<ans<<endl;
}
