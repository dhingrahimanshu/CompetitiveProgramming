class Solution {
public:
    int dp[365];

    int helper (int level, vector<int>& days, vector<int>& costs) {
        if (level == (int)days.size()) return 0;
        if (dp[level] != -1) return dp[level];

        int startDay = days[level];
        int level1 = lower_bound(days.begin(), days.end(), startDay + 1) - days.begin();
        int level2 = lower_bound(days.begin(), days.end(), startDay + 7) - days.begin();
        int level3 = lower_bound(days.begin(), days.end(), startDay + 30) - days.begin();

        // cout << startDay + 30 << ' ' << level3 << endl;

        int ans1 = costs[0] + helper(level1, days, costs);

        int ans2 =  costs[1] + helper(level2, days, costs);

        int ans3 =  costs[2] + helper(level3, days, costs);

        // cout << ans1  << ' ' << ans2 << ' ' << ans3 << endl;

        return dp[level] = min({ans1, ans2, ans3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof dp);
        return helper(0, days, costs);
    }
};
