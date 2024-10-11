class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = (int)times.size();
        vector<pair<int,int>> intervals;
        for (int i = 0; i<n;i++) {
            intervals.push_back({times[i][0], (i+1)});
            intervals.push_back({times[i][1], -1*(i+1)});
        }
        sort(intervals.begin(), intervals.end());

        priority_queue<int,vector<int>, greater<int>> pq;
        vector<int> mp(n, 0);
        for (int i = 0;i<n;i++) {
            pq.push(i);
        }
        for (int i = 0;i<intervals.size(); i++) {
            if (intervals[i].second < 0) {
                int seatLeft = mp[-1*(intervals[i].second + 1)];
                pq.push(seatLeft);
            } else {
                int seatOccupied = pq.top();
                if (intervals[i].second - 1 == targetFriend) return seatOccupied;
                pq.pop();
                mp[intervals[i].second - 1] = seatOccupied;
            }
        }
        return -1;
    }
};
