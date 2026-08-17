class Solution {
public:

    int find(vector<vector<int>>& events,
             int k,
             vector<vector<int>>& dp,
             int curr) {

        if(k == 0 || curr == events.size())
            return 0;

        if(dp[curr][k] != -1)
            return dp[curr][k];

        // Skip current event
        int skip = find(events, k, dp, curr + 1);

        // Take current event
        auto bound = upper_bound(
            events.begin() + curr + 1,
            events.end(),
            events[curr][1],
            [](const auto& time, const auto& event) {
                return time < event[0];
            }
        );

        int next_index = bound - events.begin();

        int take = events[curr][2];

        if(next_index < events.size()) {
            take += find(events, k - 1, dp, next_index);
        }

        return dp[curr][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end(),
            [](const auto& a, const auto& b) {
                return a[0] < b[0];
            }
        );

        vector<vector<int>> dp(
            events.size(),
            vector<int>(k + 1, -1)
        );

        return find(events, k, dp, 0);
    }
};