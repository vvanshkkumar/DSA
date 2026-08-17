class Solution {
public:
    
    int find(int numLeft, vector<int>& dp, int n){

        if(numLeft==0) return 1;
        if(numLeft<0) return 0;

        if(dp[numLeft]!=-1) return dp[numLeft];

        int result = 1;

        for(int i=1;i<=numLeft;i++){

            if(i!=n){
            result = max(result, i*find(numLeft-i, dp, n));
            }
        }

        return dp[numLeft]=result;
    }

    int integerBreak(int n) {
        
        vector<int> dp(n+1, -1);

        return find(n, dp, n);
    }
};