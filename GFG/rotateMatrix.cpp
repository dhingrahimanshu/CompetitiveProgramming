class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int n = (int)mat.size();
        int m= (int)mat[0].size();
        vector<vector<int>> ans(n);
        k%=m;
        for(int i =0 ;i<n;i++){
            for(int j = k;j<m;j++){
                ans[i].push_back(mat[i][j]);
            }
            for(int j = 0;j<k;j++){
                ans[i].push_back(mat[i][j]);
            } 
        }
        
        return ans;
    }
};
