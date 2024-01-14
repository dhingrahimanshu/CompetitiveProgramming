class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n==1)return 0;
        int ans =0;
        for(int i =0 ;i<n;){
            ans++;
            if(arr[i]==0)return -1;
            if((arr[i] + i +1) >=n)break;
            int j =i+1 , val = -100;
            for(int k =i+1 ;k<=(arr[i] + i);k++){
                if((arr[k]+k)>=val){
                    j = k;
                    val = arr[k]+k;
                }
            }
            i = j;
        }
        return ans;
    }
};
