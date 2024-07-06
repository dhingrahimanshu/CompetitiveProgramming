class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = time/(n-1);
        int pos = time%(n-1);
        if(dir%2){
            return n - pos;
        }
        return pos + 1;
    }
};
