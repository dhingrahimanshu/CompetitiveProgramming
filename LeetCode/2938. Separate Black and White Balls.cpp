class Solution {
public:
    long long minimumSteps(string s) {
        int n = (int)s.size();
        long long ans = 0;
        int oneCount = 0;

        for (int i = n-1;i>=0;i--) {
            if (s[i] == '1') {
                oneCount++;
                ans += (n - oneCount - i);
            }
        }


        return ans;
    }
};
