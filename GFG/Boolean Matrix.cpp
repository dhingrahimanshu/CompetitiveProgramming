class Solution
{   
    public:

    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int n = (int) matrix.size() , m = (int) matrix[0].size();
        vector<int> row(n, 0) , col(m , 0);
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(matrix[i][j]){
                    row[i]=1; col[j] = 1;
                }
            }
        }
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(row[i] || col[j]) matrix[i][j]=1;
            }
        }
    
    }
};
