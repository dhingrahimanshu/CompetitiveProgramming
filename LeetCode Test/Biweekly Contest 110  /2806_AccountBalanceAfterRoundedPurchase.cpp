class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int a = (100 - purchaseAmount);
        cout << a <<endl;
        if(a%10<=5){
            a-=(a%10);
        }else{
            a-=(a%10)-10;
        }
        return a;
    }
};
