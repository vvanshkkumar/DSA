class Solution:
    
    def find(self, w1, w2, i, j, dp) -> int :

        if i >= len(w1):
          return len(w2) - j

        if j >= len(w2):
          return len(w1) - i

        if dp[i][j] != -1 : return dp[i][j]

        ans = float('inf')

        if w1[i] == w2[j] : ans = min(ans, self.find(w1, w2, i+1, j+1, dp))
        
        if w1[i] != w2[j] : 
            ans = min(ans, 1 + self.find(w1, w2, i+1, j, dp))
            ans = min(ans, 1 + self.find(w1, w2, i, j+1, dp))


        dp[i][j] = ans

        return ans



    def minDistance(self, word1: str, word2: str) -> int:

        dp = [[-1 for _ in range(len(word2))] for _ in range(len(word1))]

        return self.find(word1, word2, 0, 0, dp)
        