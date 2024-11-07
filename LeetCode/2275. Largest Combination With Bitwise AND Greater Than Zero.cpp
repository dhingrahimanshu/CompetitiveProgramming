class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 1;

        for (int i = 0; i < 30; i++) {
            int sum = 0;
            for (auto & it : candidates) {
                sum += ((it>>i)&1);
            }
            ans = max(ans, sum);
        }

        return ans;
    }
};
