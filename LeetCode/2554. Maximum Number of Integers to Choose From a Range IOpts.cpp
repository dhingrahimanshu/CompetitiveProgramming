class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int sum = 0;
        int ans = 0;
        for (int i = 1; i <=n ;i++) {
            if (customBinarySearch(banned, i)) continue;
            sum += i;
            if (sum > maxSum) break;
            ans++;
        }
        return ans;
    }

    int customBinarySearch (vector<int> & arr, int target) {
        int lo = 0, hi = (int)arr.size() - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] == target) return true;
            if (arr[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return false;
    }
};
