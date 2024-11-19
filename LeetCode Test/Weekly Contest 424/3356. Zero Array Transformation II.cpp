class Solution {
public:

    bool check (int mid, vector<int>& nums, vector<vector<int>>& queries, int n) {
        vector<int> hash(n + 2, 0);
        for (int i = 0; i <mid ;i++) {
            hash[queries[i][0]]+=queries[i][2];
            hash[queries[i][1] + 1]-=queries[i][2];
        }

        for (int i = 0; i < n; i++) {
            if (i) hash[i]+=hash[i-1];
            if (nums[i] > hash[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 1e9;  
        int n = (int) nums.size();

        int lo = 0, hi = (int) queries.size();
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid, nums, queries, n)) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }


        return ((ans == 1e9)?-1:ans);
    }
};
