class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, rem = 0;
        while(numBottles){
            ans += numBottles;
            int temp = (rem + numBottles)/numExchange;
            rem = (rem + numBottles)%numExchange;
            numBottles = temp;
        }
        return ans;
    }
};
