class Solution {
public:
    
    bool find(string s1, string s2, string s3, vector<vector<int>>& dp, int i, int j){

        if(i==s1.size() && j==s2.size()) return true;

        if(dp[i][j] != -1) return dp[i][j];

        bool result = false;

        if(i<s1.size() && (s1[i] == s3[i+j])) result = find(s1, s2, s3, dp, i+1, j) || result;

        if(j<s2.size() && (s2[j] == s3[i+j])) result = find(s1, s2, s3, dp, i, j+1) || result;

        dp[i][j] = result;

        return result;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size()) return false;
        
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));

        return find(s1, s2, s3, dp, 0, 0);
    }
};