class Solution
{   
    public:
    int determinantOfMatrix(vector<vector<int> > &matrix, int n)
    {
        if(n==1){
            return matrix[0][0];
        }else if(n==2){
            return (matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1]);
        }
        int det =0;
        
        for(int col =0;col<n ;col++){
            if(matrix[0][col]==0)continue;
            vector<vector<int>>temp(n-1); 
            for(int row = 1;row<n;row++){
                for(int col2 =0 ; col2<n;col2++){
                    if(col==col2)continue;
                    temp[row-1].push_back(matrix[row][col2]);
                }
            }
            int partial_det = determinantOfMatrix(temp , n-1);
            if(col%2){
                det-= matrix[0][col]*partial_det;
            }else{
                det+= matrix[0][col]*partial_det;
            }
        }
   
        return det;
    }
};
