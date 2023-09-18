class Solution{
    public:
    bool isPowerofTwo(long long n){
        return n && (n&(n-1))==0;
    }
};
