typedef long long ll;
class Solution {
public:
    ll dp[101][101];

    ll helper (int curFactory, int curRobot, vector<int>& robot, vector<vector<int>>& factory)  {
        if (curRobot == (int)robot.size()) return 0;
        if (curFactory == (int)factory.size()) return 1e15;

        if (dp[curFactory][curRobot] != -1) return dp[curFactory][curRobot];
        dp[curFactory][curRobot] = helper(curFactory + 1, curRobot, robot, factory);

        long long sum = 0;
        for (int i = curRobot; i < min((int)robot.size(), curRobot + factory[curFactory][1]); i++) {
            sum += abs(robot[i] - factory[curFactory][0]);
            dp[curFactory][curRobot] = min(dp[curFactory][curRobot], sum + helper(curFactory + 1, (i  + 1), robot , factory));
        }

        return dp[curFactory][curRobot];
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        memset(dp, -1, sizeof dp);
        return helper(0, 0, robot, factory);

    }
};
