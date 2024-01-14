class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        vector<int> ans;
        map <string ,bool> hash;
        for(int i=0 ;i<M;i++){
            string temp;
            for(int j =0 ;j<N;j++){
                temp += (char)(matrix[i][j] + 48);
            }
            if(hash[temp]){
                ans.push_back(i);
            }else{
                hash[temp]=1;
            }
        }
        return ans;
      
    } 
};
