class Solution:
    
    def find(self, s, dp, pd, i) :

        if i == len(s) : return 0

        if dp[i] != -1 : return dp[i]

        result = len(s)

        for j in range(i, len(s)) :

            if pd[i][j] :
                result = min(result, 1 + self.find(s, dp, pd, j+1))

        dp[i] = result

        return dp[i]        

    def minCut(self, s: str) -> int:

        pd = [[False for _ in range(len(s))] for _ in range(len(s))]

        # for odd lengths palidrome
        for i in range(len(s)) :

            l = i
            m = i

            while(l>=0 and m<len(s) and s[l]==s[m]) :
                pd[l][m] = True
                l -= 1
                m += 1

        # for even lengths palindrome

        for i in range(len(s)) :
               
            l = i
            m = i+1

            while(l>=0 and m<len(s) and s[l]==s[m]) :
                pd[l][m] = True 
                l -= 1
                m += 1

        dp = [-1 for _ in range(len(s))]

        return self.find(s, dp, pd, 0)-1       







        