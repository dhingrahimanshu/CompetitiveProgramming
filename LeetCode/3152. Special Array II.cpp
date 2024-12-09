class Solution {
public:
    int binarySearchRange (int l, int r, vector<pair<int,int>> & ranges) {
        int lo = 0, hi = (int)ranges.size() - 1;

        int ans = -1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (ranges[mid].first <= l) {
                ans = max(ans, mid);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (ans == -1) return ans;
        if (ranges[ans].first <= l && ranges[ans].second >= r) return ans;
        return -1;

    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector <bool> ans;
        int n = (int)nums.size();

        vector<pair<int,int>> ranges;

        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j]%2 != nums[j-1]%2) {
                j++;
            }
            ranges.push_back({i, j - 1});
            i = j;
        }
        for (auto & it: queries) {
            int l = it[0];
            int r = it[1];

            int num = binarySearchRange(l, r, ranges);

            if (num == -1) {
                ans.push_back(false);
            } else {
                ans.push_back(true);
            }
        }

        return ans;
    }
};
