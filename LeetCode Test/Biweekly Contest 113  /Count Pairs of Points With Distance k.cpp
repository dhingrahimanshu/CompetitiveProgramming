class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        long long int n = (int)coordinates.size();
        long long int ans =0;
        
        map<pair<long long int,long long int> ,long long int> temp;
        for(auto & it : coordinates){
            temp[{it[0] , it[1]}]++;
        }
        for(long long int i =0 ;i<n;i++){
            for(long long int j =0 ;j<=k;j++){
                long long int a = j;
                long long int b = k -j;
                pair<long long int,long long int> f = {coordinates[i][0]^a , coordinates[i][1]^b};
                if(f.first==coordinates[i][0] && f.second==coordinates[i][1]){
                    ans+= max(0ll , temp[f]-1);
                }else{
                    ans += temp[f];
                }
            }
        }
        
        
        ans/=2;
        return ans;
    }
};
