/*
https://www.geeksforgeeks.org/samsung-interview-experience-on-campus-for-r-d-noida/
A binary matrix of nxm was given, you have to toggle any column k number of times so that you can get the maximum 
number of rows having all 1’s.
for eg, n=3, m=3,
            1 0 0
            1 0 1
            1 0 0
if k=2, then we will toggle column 2 and 3 once and we will get rows 1 and 3 with 1 1 1 and 1 1 1 i.e. all 1’s so 
answer is 2 as there are 2 rows with all 1’s.
if k=3, then we will toggle column 2 thrice and we will get row 2 with 1 1 1 i.e. all 1’s so answer is 1 as there 
is 1 row with all 1’s.
*/
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
