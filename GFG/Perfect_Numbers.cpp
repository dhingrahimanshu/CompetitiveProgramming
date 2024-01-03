class Solution {
  public:
    int isPerfectNumber(long long N) {
        if(N==1)return 0;
        long long int sum=1;
        for(long long int i =2 ; (i*1ll*i)<=N;i++){
            if(N%i==0){
                if(N==(i*1ll*i)){
                    sum += i;
                }else{
                    sum+=(i + N/i);
                }
            }
        }
        return (sum==N);
    }
};
