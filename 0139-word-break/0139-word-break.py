class Solution:

    def find(self, s, wordSet, i, dp) -> int :

        if i == len(s) : return True

        if dp[i] != -1 : return dp[i]

       
        result = False

        for j in range(i, len(s)) :

            outcome1 = False
            outcome2 = False

            if s[i:j+1] in wordSet : outcome2 = True
            else : False

            if outcome2 == True : outcome1 = outcome1 or self.find(s, wordSet, j+1, dp)

            

            result = result or (outcome1 and outcome2)

        dp[i] = result

        return dp[i]


    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        dp = [-1 for _ in range(len(s))]

        wordSet = set(wordDict)

        return self.find(s, wordSet, 0, dp)