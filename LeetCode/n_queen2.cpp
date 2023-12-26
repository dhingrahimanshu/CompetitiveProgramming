class Solution {
public:
    int queen[10];
    bool valid(int row , int col){
        for(int i =0 ;i<row;i++){
            if(col==queen[i] || abs(row-i)==abs(col-queen[i]))return false;
        }
        return true;
    }
    int helper(int i , int n){
        if(i==n){
            return 1;
        }
        int ans =0;
        for(int j =0 ;j<n;j++){
            if(valid(i ,j)==0)continue;
            queen[i]= j;
            ans += helper(i+1 , n);
        }
        return ans;
    }
    int totalNQueens(int n) {
        return helper(0 , n);
    }
};
