class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long long int ans =0;
        long long int temp =0;
        
        for(int i=0 ;i<K;i++){
            temp+=Arr[i];
        }
        ans = max(ans , temp);
        for(int i = K;i<N;i++){
            temp -= Arr[i-K];
            temp+=Arr[i];
            ans =max(ans , temp);
        }
        return ans;
    }
};
