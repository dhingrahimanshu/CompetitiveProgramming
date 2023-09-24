class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        int hash[n];
        memset(hash , 0 , sizeof hash);
        for(int i =0 ;i<n;i++){
            hash[arr[i]]++;
        }
        vector<int>ans;
        for(int i = 0;i<n;i++){
            if(hash[i]>1)ans.push_back(i);
        }
        
        if(ans.size()==0)ans.push_back(-1);
        return ans;
    }
};
