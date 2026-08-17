class Solution {
public:
   
   int find(int stones, vector<int>& dp){

      if(stones==0) return 0;
      if(stones < 0) return 0;
  
      if(dp[stones]!=-1) return dp[stones];

      for(int i=1;i*i<=stones;i++){
         
         if(find(stones - i*i, dp)==0){
            return dp[stones] = 1;
         }
      }

      return dp[stones] = 0;
   }

    bool winnerSquareGame(int n) {
        
        vector<int> dp(n+1, -1);

        return find(n, dp);

    }
};