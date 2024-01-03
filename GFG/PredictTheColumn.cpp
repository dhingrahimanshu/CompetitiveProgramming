class Solution{
    public:
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        
        int ans =-1;
        int val = N;
        
        for(int i=0 ;i<N;i++){
            int count=0;
            for(int j =0 ;j<N;j++){
                count+=arr[j][i];
            }
            if(count < val){
                val = count; 
                ans = i;
            }
        }
        
        return ans;
    }
};
