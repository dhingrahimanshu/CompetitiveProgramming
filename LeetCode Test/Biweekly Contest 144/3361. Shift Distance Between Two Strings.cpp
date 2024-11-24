class Solution {
    public:

    long long forwardCost (vector<int>& nextCost, int a, int b) {
        long long ans = 0;

        if (a < b) {
            for (int i = a; i < b; i++) {
                ans += nextCost[i];
            }
        } else {
            for (int i = a; i < 26; i++) {
                ans += nextCost[i];
            }
            
            for (int i = 0; i < b; i++) {
                ans += nextCost[i];
            }
        }

        return ans;
    }


    long long backwardCost (vector<int>& nextCost, int a, int b) {
        long long ans = 0;

        if (a > b) {
            for (int i = a; i > b; i--) {
                ans += nextCost[i];
            }
        } else {
            for (int i = a; i >=0 ; i--) {
                ans += nextCost[i];
            }
            
            for (int i = 25; i > b; i--) {
                ans += nextCost[i];
            }
        }

        return ans;
    }
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;
        int n = (int) s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;

            
            int indx = s[i]-'a';
            int indx2 = t[i] - 'a';

            long long cost = forwardCost(nextCost, indx, indx2);
            long long cost2 = backwardCost(previousCost, indx, indx2);

            ans += min(cost, cost2);
        }


        return ans;
    }
};
