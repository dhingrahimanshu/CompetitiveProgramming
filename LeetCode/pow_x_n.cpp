class Solution {
public:
    // using binary exponentiation :)

    double bin_pow(double x , int n){
        if(n==0)return 1;
        if(n==1)return x;
        double ans = bin_pow(x , n/2);

        if(n&1){
            return ans*ans*x;
        }else{
            return ans*ans;
        }
    }

    double myPow(double x, int n) {
        if(x==0)return 0;
        if(n>0)return bin_pow(x ,n);
        return 1.0/bin_pow(x,n);
    }
};
