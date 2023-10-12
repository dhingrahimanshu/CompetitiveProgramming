class Solution{
public:
    vector<vector<int>> ans;
    vector<int> queens;
    
    bool check(int row , int col){
        for(int i =0 ; i<row;i++){
            if(queens[i]==col || abs(row-i)==abs(queens[i]-col))return false;
        }
        return true;
    }
    
    void helper(int row , int n){
        if(row==n){
            vector<int> temp;
            for(auto & it : queens)temp.push_back(it+1);
            ans.push_back(temp);
            return;
        }
        for(int i =0 ;i<n;i++){
            if(check(row , i)==0)continue;
            queens[row] = i;
            helper(row +1 , n);
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        
        queens.resize(n);
        helper(0 , n);
        return ans;
    }
};
