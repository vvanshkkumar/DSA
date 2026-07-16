class Solution {
public:
   
   int find(string s, string t, vector<vector<int>>& dp, int i, int j){
      
      if(j==t.size()) return 1;
      else if(i==s.size() && j<t.size()) return 0;

      if(dp[i][j]!=-1) return dp[i][j];

      int ways = 0;

      if(s[i] == t[j]) ways += (find(s,t,dp,i+1,j+1)  + find(s,t,dp,i+1,j));
      else ways += find(s,t,dp,i+1,j);

      dp[i][j] = ways;

      return dp[i][j];

   }

    int numDistinct(string s, string t) {
        
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size(),-1));

        return find(s,t,dp,0,0);
    }
};