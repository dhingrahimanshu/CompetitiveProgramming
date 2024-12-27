class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int n = (int) values.size();

        int suffMax = INT_MIN;

        for (int i = n - 1; i>=0; i--) {

            ans = max(ans, values[i] + i + suffMax);

            suffMax = max(suffMax, values[i] - i);
        }
        return ans;
    }
};
