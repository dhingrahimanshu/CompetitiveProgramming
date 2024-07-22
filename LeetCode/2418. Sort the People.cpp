class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int,string>> arr;
        for(int i = 0;i<names.size();i++){
            arr.push_back({heights[i],names[i]});
        }
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        for(auto & it : arr){
            ans.push_back(it.second);
        }
        return ans;
    }
};
