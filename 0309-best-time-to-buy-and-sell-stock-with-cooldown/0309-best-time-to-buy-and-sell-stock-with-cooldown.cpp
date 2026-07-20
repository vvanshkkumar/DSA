class Solution {
public:
   int find(vector<int>& prices, vector<vector<int>>& dp, int i, int buy){

    if(i>=prices.size()) return 0;

    if(dp[i][buy]!=-1) {
      return dp[i][buy];
    }

      int profit = 0;
        
      if(buy==0){

        int profit1 = -prices[i] + find(prices, dp, i+1, 1);

        int profit2 = find(prices, dp, i+1, 0);

        profit = max(profit1, profit2);

      }
      else {

        int profit1 = prices[i] + find(prices, dp, i+2, 0);
        int profit2 = find(prices, dp, i+1, 1);

        profit = max(profit1, profit2);
        
      }

      dp[i][buy] = profit;

      return profit;
   }

    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));

        return find(prices, dp, 0, 0);
        // u can buy -> 0, u can sell -> 1

    }
};