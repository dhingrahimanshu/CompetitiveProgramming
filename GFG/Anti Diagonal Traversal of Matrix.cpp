class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        vector<int> ans;
        int n = (int)matrix.size();
        for(int i =0 ;i<n;i++){
            int row = 0 , col = i;
            while(row<n && col>=0){
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        for(int i =1;i<n;i++){
            int row = i , col = n-1;
            while(row<n && col>=0){
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        
        
        return ans;
    }
};
