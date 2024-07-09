class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long int ans = 0;
        long long int n = customers.size();
        long long int waiting = 0;
        for(int i = 0;i<n;i++){
            waiting = max((int)waiting,customers[i][0]) + customers[i][1];
            ans += waiting - customers[i][0];
        }
        double ans2 = (1.0*ans/n);

        return ans2;
    }
};
