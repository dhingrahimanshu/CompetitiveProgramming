class Solution {
public:
    static bool mycmp (vector<int> &a, vector<int> & b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> lis, indx,below;
        sort(envelopes.begin(), envelopes.end(), mycmp);
        
        for (int i = 0; i<(int)envelopes.size(); i++) {
            if (lis.empty() || (lis.back() < envelopes[i][1])) {
                 lis.push_back(envelopes[i][1]);
            } else {
                auto it =  lower_bound(lis.begin(), lis.end(),  envelopes[i][1]);

                *it =  envelopes[i][1];
            }
        }


        return (int)lis.size();
    }
};
