class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = (int)nums.size();
        vector<int>ans{-100000, 100000};
        int val = 2e9;

        vector<pair<int,int>> arr;
        vector<int> freq(n, 0);
        int sum = 0;
        for (int i = 0;i<n;i++) {
            for (auto & it : nums[i]) {
                arr.push_back({it, i});
            }
        }
        sort(arr.begin(), arr.end());
        

        int i = 0, j = 0;

        while (i<arr.size()) {
            while (j<arr.size() && sum<n) {
                if (!freq[arr[j].second]) {
                    sum++;
                }
                freq[arr[j].second]++;
                j++;
            }
            if (sum!=n)break;

            int val2 = arr[j - 1].first - arr[i].first;

            if (val2 < val) {
                ans = {arr[i].first , arr[j - 1].first};
                val = val2;
            }

            freq[arr[i].second]--;
            if (freq[arr[i].second] == 0) {
                sum--;
            };
            i++;
        }
        return ans;
    }
};
