#include<bits/stdc++.h>
using namespace std;


int dp[301][301];
    int util(vector <int> &nums, int i, int j){
        if(i>j) 
            return 0;
            
        if(dp[i][j]!=-1) 
            return dp[i][j];
            
        int ans=0, n= nums.size();
        for(int k=i+1; k<j; k++) 
        {    
            //new added
            int cs = util(nums, i, k)+util(nums, k, j);
            if(i == 0 and j == n)
                cs += nums[k];
            else
                cs += nums[i]*nums[j];
            
            ans = max(ans, cs);
        }
        
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums){
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));
        return util(nums, 0, nums.size()+1); //changed
    }
int main()
{
    vector<int> arr;
    int n, x;
    cin>>n;
    
    for(int i = 0 ;i < n ; i ++ )
    {
        cin>>x;
        arr.push_back(x);
    }
    
    cout<<maxCoins(arr);
    
}
