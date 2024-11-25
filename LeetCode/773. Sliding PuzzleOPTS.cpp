class Solution {
public:

    vector<pair<int,int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    vector<int> getMoves (int a) {
        int row = a / 3;
        int col = a % 3;
        vector<int> ans;
        for (auto &it : dir) {
            int x = row + it.first;
            int y = col + it.second;

            if (x < 0 || y < 0 || x>=2 || y>=3) continue;
            int conv = (3 * x) + (y % 3);
            ans.push_back(conv);
        }
        return ans;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        string sBoard;
        string target = "123450";

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                sBoard += (char)(board[i][j] + '0');
            }
        }

        queue <string> pending;
        pending.push(sBoard);

        unordered_set <string> vis;

        int moves = 0;
        while (pending.size()) {
            int n = pending.size();

            
            while (n--) {
                string newBoard = pending.front(); pending.pop();

                if (newBoard == target) return moves;

                int pos = newBoard.find('0');

                for (auto &it: getMoves(pos)) {
                    swap(newBoard[pos], newBoard[it]);
                    
                    if (vis.count(newBoard)) {
                        swap(newBoard[pos], newBoard[it]);
                        continue;
                    }

                    vis.insert(newBoard);
                    pending.push(newBoard);

                    swap(newBoard[pos], newBoard[it]);
                }

                
            }
            moves++;
        }
        return -1;
    }
};
