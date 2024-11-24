class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 0;
        int toRemove = 10;
        
        while (true){
            if (n < toRemove) {
                if (turn == 0) {
                    return false;
                }
                return true;
            }
            n -= toRemove;
            toRemove--;
            turn ^= 1;
        }
        return false;
    }
};
