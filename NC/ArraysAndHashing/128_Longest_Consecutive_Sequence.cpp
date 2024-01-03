class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> uf;
        for(auto it : nums){
            uf.insert(it);
        }
        vector<int> arr;
        for(auto it : uf){
            arr.push_back(it);
        }
        int ans =0;
        int n = arr.size();
        for(int i =0 ;i<n;){
            int j =i;
            while(j<n && arr[j]-arr[i]==(j-i)){
                j++;
            }
            ans = max(ans , j- i);
            i = j;
            
        }

        return ans;

    }
};
