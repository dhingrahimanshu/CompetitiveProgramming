class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = (int) nums.size();
        int ans =INT_MAX;
        map <int, pair <int,int>> arr;
        map <int,int> arr2;
        map <int,int> arr3;
        for(auto it : nums){
            arr[it]={-1 , -1};
        }
        
        for(int i =0 ;i<n;i++){
            if(arr3[nums[i]]==0){
                arr3[nums[i]] = i+1;
            }
            int f = arr[nums[i]].first;            
            int s = arr[nums[i]].second;
            if( f== -1){
                arr[nums[i]].first = i;
                arr[nums[i]].second = i;

            }else{
                
                arr2[nums[i]] = max(arr2[nums[i]] , (int) ceil(1.0*(i-s-1)/2.0));
                // cout << nums[i] <<" " << i <<"  " << s <<"  " << (int) ceil(1.0*(i-s-1)/2.0) <<endl;
                arr[nums[i]].first = s;
                arr[nums[i]].second = i;
                
            }
        }
        for(auto it : arr2){
            it.second = max(it.second , (int)ceil(1.0*(arr3[it.first]-1 + n - arr[it.first].second -1)/2));
            ans = min(ans , it.second);
            
        }
        ans = min(ans , n/2);
        return ans;
    }
};
