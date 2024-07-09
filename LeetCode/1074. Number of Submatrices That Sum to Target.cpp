class Solution {
public:
    int subArrSumToK(vector<int> & subArr,int target){
        map <int,int>mp;
        int sum = 0,ans=0;
        mp[0] = 1;
        for(auto & it : subArr){
            sum += it;
            ans += mp[sum - target];
            mp[sum]++;
        }
        
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        vector<vector<int>> pref(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                pref[i][j] = matrix[i][j];
                if(j){
                    pref[i][j] += pref[i][j-1];
                }
            }
        }
    
        for(int c1 = 0;c1<m;c1++){
            for(int c2 = c1;c2<m;c2++){
                vector<int> subArr;
                for(int row = 0;row<n;row++){
                    if(c1 == 0){
                        subArr.push_back(pref[row][c2]);
                    }else{
                         subArr.push_back(pref[row][c2] - pref[row][c1 - 1]);
                        
                    }
                }
                ans += subArrSumToK(subArr,target);
            }
        }



        return ans;
    }
};
