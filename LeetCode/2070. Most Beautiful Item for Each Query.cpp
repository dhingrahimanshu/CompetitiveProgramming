class Solution {
public:
    static bool mycmp(vector<int> & a, vector<int> & b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), mycmp);
        vector<int> ans;
        int n = (int)items.size();
        int ma = 0;

        for (auto &it : items) {
            ma = max(ma, it[1]);
            it.push_back(ma);
        }

        for (auto &it : queries) {
            int temp = 0;
            int lo = 0, hi = n-1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (items[mid][0] <= it) {
                    temp = max(temp, items[mid][2]);
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            ans.push_back(temp);
        }


        return ans;
    }
};
