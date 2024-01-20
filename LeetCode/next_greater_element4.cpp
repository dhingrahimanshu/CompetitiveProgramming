class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n , -1);

        stack<pair <int,int>> temp;
        for(int i =0 ;i<n;i++){
            if(temp.empty()){
                temp.push({i ,0});
            }else{
                vector<int> arr;
                while(temp.size() && nums[temp.top().first]<nums[i]){
                    pair <int,int> a = temp.top();
                    if(a.second == 1){
                        ans[a.first] = nums[i];
                    }else{
                        arr.push_back(a.first);
                    }
                    temp.pop();
                }
                temp.push({i ,0});
                reverse(arr.begin() , arr.end());
                for(auto & it : arr){
                    temp.push({it , 1});
                }
            }
        }

        return ans;
    }
};
