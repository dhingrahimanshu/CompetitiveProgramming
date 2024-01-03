class Solution {
public:
    static bool mycmp(pair<string,int> & p1 , pair <string,int> & p2){
        return p1.first<p2.first;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <pair <string,int>> arr;
        int i =0;
        for(auto it : strs){
            sort(it.begin(),it.end());
            arr.push_back({it  , i});
            i++;
        }  
        sort(arr.begin() , arr.end() ,  mycmp);
        vector<vector<string>> ans;
        int n = strs.size();
        for(int i =0 ;i<n;){
            int j =i;
            vector<string>uf;
            while(j<n && arr[i].first==arr[j].first){
                uf.push_back(strs[arr[j].second]);
                j++;    
            }
            ans.push_back(uf);
            i = j;
        }

        return ans;
    }
};
