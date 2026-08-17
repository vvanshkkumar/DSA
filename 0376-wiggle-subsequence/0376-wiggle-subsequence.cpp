class Solution {
public:
    
    int find(vector<int>& nums, vector<vector<int>>& dp, int index, int cond){

        if(index==nums.size()) return 0;

        if(dp[index][cond]!=-1) return dp[index][cond];

        int length = 0;
         
        for(int i=index+1;i<nums.size();i++){

            int num = nums[index] - nums[i];

            if(num == 0) continue;

            int tempCond = num<0?0:1;

            if(cond == 2 || cond!=tempCond)  length = max(length , 1 + find(nums, dp, i, tempCond));

            }

        dp[index][cond] =  length;   

            return length;
        }
    


    int wiggleMaxLength(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size(), vector<int>(3, -1));

        return 1 + find(nums, dp, 0, 2);
    }
};