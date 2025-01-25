class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = (int) nums.size();

        vector <int> ans(n);
        vector <pair<int,int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n;) {
            int j = i + 1;

            vector <int> pos;
            pos.push_back(arr[i].second);

            while (j < n && (arr[j].first - arr[j-1].first)<= limit) {
                pos.push_back(arr[j].second);
                j++;
            }

            sort(pos.begin(), pos.end());

            // for (auto &it: pos) cout << it << ' ';
            // cout << '\n';

            for (int k = 0; k < (int)pos.size();k++) {
                ans[pos[k]] = arr[k + i].first;
            }
            i = j;
        }

        return ans;
    }
};
