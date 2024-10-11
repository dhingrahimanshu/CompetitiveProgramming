class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int target = 0;
        int n = (int)times.size();
        vector<vector<int>> intervals;
        for (int i = 0; i<n;i++) {
            if (i == targetFriend) {
                target = times[i][0];
            }
            intervals.push_back({times[i][0], 1, i});
            intervals.push_back({times[i][1], -1, i});
        }
        sort(intervals.begin(), intervals.end());

        set <int> st;
        vector<int> mp(n, 0);
        for (int i = 0;i<n;i++) {
            st.insert(i);
        }
        for (int i = 0;i<intervals.size(); i++) {
            if (intervals[i][1] == -1) {
                int seatLeft = mp[intervals[i][2]];
                st.insert(seatLeft);
            } else {
                int seatOccupied = *st.begin();
                if (intervals[i][0] == target) return seatOccupied;
                st.erase(st.begin());
                mp[intervals[i][2]] = seatOccupied;
            }
        }
        return -1;
    }
};
