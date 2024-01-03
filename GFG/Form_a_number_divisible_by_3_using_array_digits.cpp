class Solution {
  public:
    int isPossible(int N, int arr[]) {
        int ans =0;
        
        for(int i =0 ;i<N;i++){
            while(arr[i]){
                ans+= arr[i]%10;
                arr[i]/=10;
            }
        }
        
        return (ans%3==0);
    }
};
