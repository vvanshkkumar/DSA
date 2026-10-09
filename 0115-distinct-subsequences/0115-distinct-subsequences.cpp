class Solution {
public:
    
    int find(string& s, string& t, vector<vector<int>>& dp, int i, int j){
         
         if(j==t.size()) return 1;
         if(i>= s.size() || j>=t.size()) return 0;
         

         if(dp[i][j]!=-1) return dp[i][j];
         
         int equal1 = 0;
         int equal2 = 0;
         
         if(s[i] == t[j]){
            equal1 = find(s, t, dp, i+1, j+1);
            equal2 = find(s, t, dp, i+1, j);
            
         }
         else if(s[i] != t[j]){
            equal1 = find(s, t, dp, i+1, j);
         }

         return dp[i][j] = equal1 + equal2;
    }

    int numDistinct(string s, string t) {

      vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));

      return find(s,t,dp,0,0);   
    }
};