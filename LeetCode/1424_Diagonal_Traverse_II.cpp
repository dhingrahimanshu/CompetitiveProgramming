class Solution {
public:

    static bool comp(pair<int,int> & p1 , pair<int,int> &p2){
        int x = p1.first+p1.second;
        int y = p2.first+p2.second;
        if(x == y){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
        return x<y;
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        vector<pair<int,int>> uf;

        for(int i=0 ;i<(int)nums.size();i++){
            for(int j =0 ;j<(int)nums[i].size();j++){
                uf.push_back({i , j});
            }
        }
        sort(uf.begin() , uf.end() , comp);

        for(int i =0 ;i<(int)uf.size();i++){
            ans.push_back(nums[uf[i].first][uf[i].second]);

        }

        return ans;
    }
};
