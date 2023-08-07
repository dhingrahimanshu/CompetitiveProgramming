class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag =0;   
        int i =0 ;
        int n = matrix[0].size();
        while(i<matrix.size()){
            if(target>=matrix[i][0] && target<=matrix[i][n-1]){
                break;
            }i++;
        }
        if(i>=matrix.size()){
            return 0;
        }
        
        for(int j=0;j<n;j++){
            if(matrix[i][j]==target){
                flag=1;
                break;
            }
        }


        return flag;
    }
};
