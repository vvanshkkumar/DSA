class Solution {
public:
    
    int find(vector<int>& dp, int remain){

        if(remain==0) return 0;
        if(dp[remain]!=-1) return dp[remain];

        int count = INT_MAX;

        for(int i=1;i<=sqrt(remain);i++){

            int num = i*i;

            if(remain-num<0) break;

            count = min(count, 1 + find(dp, remain-num));
        }

        return dp[remain] = count;
    }

    int numSquares(int n) {
        
        vector<int> dp(n+1,-1);

        return find(dp, n);
    }
};