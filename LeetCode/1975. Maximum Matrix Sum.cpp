class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long int sum = 0;
        long long mi = 1e15;
        long long count = 0;
        for (auto & it: matrix) {
            for (auto & it2: it) {
                if (it2 < 0) {
                    count++;
                }
                mi = min(mi, 1ll*abs(it2));
                sum += abs(it2);
            }
        }
        // cout << sum << endl;
        if (count % 2) {
            sum -= 2* abs(mi);
            
        }
        return sum;
    }
};
