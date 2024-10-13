class Solution {
public:
    int dp[1001][2001][3];
    int const MOD = 1e9 + 7;
    int check (char a, char b) {
        if (a == b)return 0;
        if (a == 'F' && b == 'E') return 1;
        if (a == 'W' && b == 'F') return 1;
        if (a == 'E' && b == 'W') return 1;
        return -1;
    }
    vector<char> uf = {'F', 'W', 'E'};
    int helper (int level, int score, int last_used, string & s) {
        if (level == (int)s.size()) {
            // cout << score - 1000 << endl;
            return ((score-1000) > 0);
        }
        if (dp[level][score][last_used] != -1) return dp[level][score][last_used];

        dp[level][score][last_used] = 0;
        
        for (int i = 0;i<3;i++) {
            if (i == last_used)continue;
            int now = check(uf[i], s[level]);
            dp[level][score][last_used] = (dp[level][score][last_used]%MOD + helper (level +1, score + now, i, s)%MOD)%MOD;
        }

        return dp[level][score][last_used];
    }
    int countWinningSequences(string s) {
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for (int i = 0;i<3;i++) {
            int now = check(uf[i], s[0]);
            // cout << uf[i] << ' ' <<s[0] << ' ' << now << endl;
            ans =  (ans%MOD + helper(1, now + 1000,i,s)%MOD)%MOD;
        }
        return ans;
    }
};
