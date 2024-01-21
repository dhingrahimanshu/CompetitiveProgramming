class Solution{
    public:
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            int ans =n;
            
            for(int i = 1;i<(1<<n);i++){
                bool flag = true;
                
                for(int j =0 ;j<edges.size();j++){
                    if(i&(1<<(edges[j].first-1)) || (i&(1<<(edges[j].second-1))))continue;
                    flag =false;
                    break;
                }
                
                if(flag){ 
                    ans = min(ans ,__builtin_popcount(i));
                }
            }
            return ans;
            
        }
};
