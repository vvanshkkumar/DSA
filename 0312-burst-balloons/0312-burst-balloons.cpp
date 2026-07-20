class Solution {
public:
   int find(vector<int>& nums, vector<vector<int>>& dp, int l, int r){

       if(l>r) return 0;

       if(dp[l][r]!=-1) return dp[l][r];

       int maxBurst = 0;

       for(int k=l;k<=r;k++){

        int left = (l-1)<0?1:nums[l-1];
        int right = (r+1)>(nums.size()-1)?1:nums[r+1];

        maxBurst = max(maxBurst, find(nums, dp, l, k-1) + ( left * nums[k] * right ) + find(nums, dp, k+1, r));
       }

       dp[l][r] = maxBurst;

       return dp[l][r]; 
   }


    int maxCoins(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(),-1));

        return find(nums, dp, 0, nums.size()-1);
        
    }
};