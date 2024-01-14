class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stockie = prices[0];
        int ans =0;
        int n = (int)prices.size();
        for(int i = 1;i<n;i++){
            if(prices[i]>stockie){
                ans += prices[i] - stockie;
                stockie = prices[i];
            }else{
                stockie =  prices[i];
            }
        }

        return ans;
    }
};
