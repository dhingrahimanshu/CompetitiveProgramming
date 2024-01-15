    #include <bits/stdc++.h>
    using namespace std;

    vector<vector<int>> up;
    vector<int> parent ,depth;
    int LOG;

    void dfs(int root , vector<int> adj[]){
        for(auto & it : adj[root]){
            parent[it] = root;
            depth[it] = 1+ depth[root];
            dfs(it , adj);
        }
    }



    void binary_uplifting(int n){
        for(int i=0 ;i<n;i++){
            up[i][0] = parent[i];
        }
        for(int i = 1;i<LOG;i++){
            for(int j =0 ;j<n;j++){
                int y = up[j][i-1];
                if(y==-1)continue;
                up[j][i] = up[y][i-1];
            }
        }
    }


    int kthAncestor(int node ,int k){
        for(int i=0 ;i<LOG;i++){
            if(k&(1<<i)){
                node = up[node][i];
                if(node==-1)return -1;
            }
        }
        return node;
    }

    int lca(int u , int v){
        int x = depth[u] , y = depth[v];

        if(x>y){
            swap(x ,y);
            swap(u ,v);
        }
        v = kthAncestor(v , y -x);
        if(u==v)return u;

        for(int i = LOG-1;i>=0;i--){
            int a = up[u][i] , b= up[v][i];
            if(a!=-1 && b!=-1 && a!=b){
                u = a ,v =b;
            }
        }


        return up[u][0];
    }

    void solve(int uf){
        int n; cin>>n;
        up.clear();
        LOG = log2(n)+1;
        parent = depth = vector<int>(n ,0);
        up.resize(n ,vector<int> (LOG ,-1));
        vector<int> adj[n];
        for(int i=0 ;i<n;i++){
            int m; cin>>m;
            while(m--){
                int x; cin>>x;
                adj[i].push_back(x-1);
            }
        }   
        dfs(0 , adj);
        binary_uplifting(n);
        int q;cin>>q;
        cout << "Case "<<uf<<":" <<endl;
        while(q--){
            int u,v; cin>>u>>v;
            u--;v--;
            int x = lca(u ,v) +1;
            cout <<x <<endl;
        }
        

    }


    int main(){
        int t; cin>>t;
        for(int i =1;i<=t;i++){
            solve(i);
        }
    }
