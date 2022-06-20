class Solution {
public:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int ans = -1e9;
        
        for(int k=i;k<j;k++){
            int steps = nums[i-1] * nums[k] * nums[j] + f(i,k,nums,dp) + f(k+1,j,nums,dp);
            ans = max(ans,steps);
        }
        
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        // Add 1 at start and end to take care of out of bond situations
        nums.insert(nums.begin(),1);
        nums.push_back(1);
		
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(1,n-1,nums,dp);
		}
	};
