class TreeAncestor {
public:
    vector<vector<int>> up;
    int LOG;
    TreeAncestor(int n, vector<int>& parent) {
        LOG = log2(n)+1;
        up.resize(n , vector<int>(LOG));
        for(int i=0 ;i<n;i++){
            up[i][0] = parent[i];
        }
        for(int i =1;i<LOG;i++){
            for(int j =0 ;j<n;j++){
                int y = up[j][i-1];
                if(y==-1){
                    up[j][i] = -1;
                    continue;
                }
                up[j][i] = up[y][i-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<LOG;i++){
            if(k&(1<<i)){
                node = up[node][i];
                if(node==-1)return node;
            }
        }
        return node;
    }
};
