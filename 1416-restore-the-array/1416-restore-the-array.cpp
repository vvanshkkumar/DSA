class Solution {
public:
    
    int find(string& s, int k, vector<int>& dp, int start){

        
        if(start==s.size()) return 1;
        if(s[start]=='0') return 0;

        if(dp[start]!=-1) return dp[start];

        int result = 0;
        long long num = 0;

        for(int i=start;i<s.size();i++){
                
                num = num*10 + (s[i]-'0');

                if(num > k) break;
            
                result = (result + find(s, k, dp, i+1)%(1000000000+7))%(1000000000+7);
        }
        return dp[start] = result;
    }

    int numberOfArrays(string s, int k) {
        
        vector<int> dp(s.size()+1, -1);

        return find(s, k, dp, 0);
    }
};