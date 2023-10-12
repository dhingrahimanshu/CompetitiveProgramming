class Solution {
public:
    int ans =0;
    vector<int> queen;

    bool valid(int row , int col){
        for(int i =0 ;i<row;i++){
            if(col==queen[i] || (abs(row-i)==abs(col-queen[i]))){
                return false;
            }
        }
        return true;
    }

    void helper(int row , int n){
        if(row==n){
            ans++;
            return;
        }
        for(int i =0 ;i<n;i++){
            if(valid(row , i)==0)continue;
            queen[row]=i;
            helper(row +1 , n);
        }
    }

    int totalNQueens(int n) {
        queen.resize(n);
        helper(0 , n);
        return ans;
    }
};
