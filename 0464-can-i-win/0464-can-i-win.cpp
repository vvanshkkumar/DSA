class Solution {
public:
    bool find(vector<int>& dp, int mask, int remain, int n) {

        if (remain <= 0) return false;
        if (dp[mask] != -1) return dp[mask];

        for (int i = 1; i <= n; i++) {

            int visited = mask & (1 << i);

            if (visited == 0) {
                int newMask = mask | (1 << i);

                if (i >= remain || !find(dp, newMask, remain - i, n))
                    return dp[mask] = true;
            }
        }

        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        int n = maxChoosableInteger;

        if (desiredTotal <= 0) return true;
        if (n * (n + 1) / 2 < desiredTotal) return false;

        vector<int> dp(1 << (n + 1), -1);

        return find(dp, 0, desiredTotal, n);
    }
};