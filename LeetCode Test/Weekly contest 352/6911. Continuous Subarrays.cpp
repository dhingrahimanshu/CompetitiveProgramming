class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long int ans =0;
        int n = nums.size();
        multiset <int> temp;
        
        temp.insert(nums[0]);
        int j =0;
        for(int i =1 ;i<n;i++){
            int ma = *temp.rbegin();
            int mi = *temp.begin();
            j =i;
            if(abs(ma-nums[i])<=2 && abs(mi-nums[i])<=2){
                temp.insert(nums[i]);
            }else{
                break;
            }
        }
        long long int uf = ((int)(temp.size()));
        ans += uf;
        // cout << ans <<endl;
        for(int i = 1;i<n;i++){
            temp.erase(temp.find(nums[i-1]));
            if(j==i){
                temp.insert(nums[i]);
                j = i+1;
            }
            int ma = *temp.rbegin();
            int mi = *temp.begin();
            while(j<n && abs(ma-nums[j])<=2 && abs(mi-nums[j])<=2){
                temp.insert(nums[j]);
                ma = *temp.rbegin();
                mi = *temp.begin();
                j++;
            }
            long long int uf = j-i;
            ans += uf;
        }
        
        
        return ans;
    }
};
