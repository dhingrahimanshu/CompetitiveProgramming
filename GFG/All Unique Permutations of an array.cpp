class Solution {
  public:
    vector<vector<int>> ans;
    void rec(int i ,int n , vector<int> & arr){
        if(i==n){
            ans.push_back(arr);
            return;
        }
        for(int j = i;j<n;j++){
            if(j>i && arr[j]==arr[i])continue;
            swap(arr[i] , arr[j]);
            rec(i+1 , n , arr);
            
        }
        for(int j = n-1;j>i;j--){
            swap(arr[i] , arr[j]);
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(arr.begin() , arr.end());
        rec(0 , n , arr);
        // for(auto & it : ans){
        //     temp.push_back(it);
        // }
        return ans;
    }
};
