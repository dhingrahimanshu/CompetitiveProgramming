class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        int n = mat.size();
        vector<pair<int,int>> temp;

        for(int i =0 ;i<n;i++){
            int sum =0;
            for(auto & it : mat[i]){
                sum+=it;
            }
            temp.push_back({sum , i});
        }

        sort(temp.begin() , temp.end());
        for(int i =0 ;i<k;i++){
            ans.push_back(temp[i].second);
        }

        return ans;
    }
};
