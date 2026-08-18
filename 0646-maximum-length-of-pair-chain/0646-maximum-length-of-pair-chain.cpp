class Solution {
public:
    
    int find(vector<vector<int>>& pairs, vector<int>& dp, int i){

         if(i==pairs.size()) return 0;

         if(dp[i]!=-1) return dp[i];

         int take = 1;

         for(int j=i+1;j<pairs.size();j++){

         if(pairs[j][0]>pairs[i][1]){
            take = max(take, 1 + find(pairs, dp, j));
         }
         }
        
         dp[i] = take;

         return dp[i];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        
        vector<int> dp(pairs.size()+1,-1);

        sort(pairs.begin(), pairs.end(), 
        [](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        int ans = 0;

        for(int i=0;i<pairs.size();i++){

            ans = max(ans, find(pairs, dp, i));
        }

        return ans;

    }
};