class Solution{
public: 
    long long int largestPrimeFactor(int N){
        if(N==1){
            return 1;
        }
        for(long long int i = sqrt(N);i>=2;i--){
            if(N%i==0){
                return max(largestPrimeFactor(N/i) , largestPrimeFactor(i));
            }
        }
        return N;
    }
};
