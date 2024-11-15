class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = (int) arr.size();
        int right = n - 1;

        while (right > 0 && (arr[right - 1] <= arr[right])) {
            right--;
        }

        int ans = (n - right);

        int left = 0;

        while (left < right && (!left || arr[left] >= arr[left-1])) {
            while (right < n && arr[right] < arr[left]) {
                right++;
            }

            ans = max(ans, left + 1 + (n - right));
            left++;
        }


        return n - ans;
    }
};
