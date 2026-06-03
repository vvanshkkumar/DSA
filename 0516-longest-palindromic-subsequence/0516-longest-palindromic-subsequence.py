class Solution:

    def find(self, s, i, j, dp) -> int :

        if i==j : return 1
        
        if i > j : return 0

        if dp[i][j] != -1 : return dp[i][j]

        take = 0
        notTake = 0

        result = 0

        if s[i] == s[j] :
            take = 2 + self.find(s, i+1, j-1, dp)
            result = max(result, take)

        notTake1 = self.find(s, i+1, j, dp)
        notTake2 = self.find(s, i, j-1, dp)    

        result = max(result, notTake1, notTake2)

        dp[i][j] = result

        return dp[i][j]

    def longestPalindromeSubseq(self, s: str) -> int:

        dp = [[-1 for _ in range(len(s))] for _ in range(len(s))]

        return self.find(s, 0, len(s)-1, dp)
                