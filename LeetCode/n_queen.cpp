class Solution {
public:
    vector<vector<string>> ans;
    vector<int> queen;

    bool valid(int row , int col){
        for(int i =0 ;i<row;i++){
            if(col==queen[i] || abs(row -i) == abs(col-queen[i]))return false;
        }
        return true;
    }
    
    void helper(int i  , int n , vector<string> & temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        for(int j =0 ;j<n;j++){
            if(!valid(i ,j))continue;
            queen[i] = j;
            temp[i][j]='Q';
            helper(i+1 , n , temp);
            temp[i][j] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        queen.resize(10);
        string a(n , '.');
        vector<string> temp(n , a);
        helper(0, n, temp);
        return ans;
    }
};
