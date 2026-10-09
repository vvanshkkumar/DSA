class Solution {
public:
    
    int find(vector<int>& nums, vector<vector<int>>& dp, int i, bool flag){

        if(i==nums.size()-1 && flag==1) return 0; 
        if(i>=nums.size()) return 0;   
        if(dp[i][flag]!=-1) return dp[i][flag];


        int skip = find(nums, dp, i+1, flag);
        
        if(i==0) flag = 1;
        int take = nums[i] + find(nums, dp, i+2, flag);


        return dp[i][flag] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        int flag = 0;

        return find(nums, dp, 0, flag);
    }
};