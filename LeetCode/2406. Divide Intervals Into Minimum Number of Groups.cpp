class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int ans = 1;
        int cons = 0;
        vector<pair<int,int>> events;

        for (auto & it : intervals) {
            events.push_back({it[0], 1});
            events.push_back({it[1] + 1, -1});
        }
        sort(events.begin(), events.end());

        for (auto  & it : events) {
            if (it.second == -1) {
                cons--;
            } else {
                cons++;
            }
            ans = max(ans, cons);
        }

        return ans;
    }
};
