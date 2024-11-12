class Solution {
public:
    static bool mycmp(vector<int> & a, vector<int> & b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), mycmp);
        
        int n = (int)items.size();

        int q = (int) queries.size();
        vector<int> ans(q,0);
        vector<pair<int,int>> newQ(q);

        for (int i = 0; i<q;i++) {
            newQ[i] = {queries[i], i};
        }

        sort (newQ.begin(), newQ.end(),
            [](pair<int,int> & a, pair<int,int> &b) {
                return a.first < b.first;
            }
        );
        int ma = 0;
        int i = 0;
        for (int j = 0; j < q; j++) {
            int qVal = newQ[j].first;
            int oIndx = newQ[j].second;

            while (i<n && items[i][0] <= qVal) {
                ma = max(ma, items[i][1]);
                i++;
            }


            ans[oIndx] = ma;
        }


        return ans;
    }
};
