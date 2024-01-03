class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = (int)matrix.size() , m = (int) matrix[0].size();
        for(int i = n-2;i>=0;i--){
            for(int j =0 ;j<m;j++){
                if(matrix[i][j]==0)continue;
                matrix[i][j]+=matrix[i+1][j];
            }
        }
        int ans =0;
        for(auto & it : matrix){
            sort(it.begin() , it.end() , greater<int>());
            for(int j =0 ;j<m;j++){
                ans = max(ans , it[j]*(j+1));
            }
        }
        return ans;
    }
};
