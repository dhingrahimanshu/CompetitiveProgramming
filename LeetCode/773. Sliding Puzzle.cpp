class Solution {
public:
    vector<pair<int,int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isValid (int a) {
        if (a < 0 || a >= 6) return false;
        return true;
    }

    vector<int> getMoves (int a) {
        int row = a / 3;
        int col = a % 3;

        vector<int> ans;
        for (auto &it: dir) {
            int x = row + it.first;
            int y = col + it.second;
            
            if (x < 0 || y < 0 || x >= 2 || y>=3) continue;
            int conv = (3 * x) + (y % 3);
            if (isValid(conv)) {
                ans.push_back(conv);
            }


        }
        return ans;

    }

    

    void helper (int level, string & board, unordered_map <string,int> &mpp, int moves) {
        if (mpp.count(board) && mpp[board] <= moves) return;

        mpp[board] = moves;

        for (auto & it: getMoves(level)) {
            int newLevel = it;
            if (!isValid(newLevel)) continue;
            swap(board[level], board[newLevel]);
            helper(newLevel, board, mpp, moves + 1);
            swap(board[level], board[newLevel]);
        }
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        string board1D;
        unordered_map <string,int> mpp;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                board1D += (char) (board[i][j] + '0');
            }
        }
        helper(board1D.find('0'), board1D, mpp, 0);
        return (mpp.count("123450")?mpp["123450"]:-1);
    }
};
