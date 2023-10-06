class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)return n-1;

        int a = n/3;
        int ans = pow(3 ,a)*max(1 , n%3);
        int ans2 = pow(3 , a-1)*max(1 , 3 + n%3);
        return max(ans , ans2);
    }
};
