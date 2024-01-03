class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        int ans =0;
        for(int i =0 ;i<V;i++){
            ans +=(int) (adj[i].size());
        }
        return ans;
    }
};
