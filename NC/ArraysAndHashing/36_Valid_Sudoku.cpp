class Solution {
public:
    
    bool isval(vector<vector<char>> &board , int row , int col , char filled){
        int ans =0;
        for(int i =0 ;i<9;i++){
            if(board[row][i]==filled){
                ans++;
            }
            if(board[i][col]==filled){
                ans++;
            }
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==filled){
                ans++;
            }
        }
        return ans==3;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

       for(int i =0 ;i<9;i++){
           for(int j =0 ;j<9;j++){
               if(board[i][j]!='.'){
        
                    if(isval(board , i , j , board[i][j])==false){
                        return false;
                    }
               }
           }
       }
       return true; 
    }
};
