class Solution
{   
    public:
    static bool mycmp(vector<int> & p1 , vector<int>& p2){
        if(p1[0]== p2[0])return p1[1]<p2[1];
        return p1[0]<p2[0];
    }
    map <int , vector<vector<int>>> temp;
    int mi =1e9 , ma = -1e9;
    void dfs(Node *root , int k , int &num, int depth){
        if(root==NULL)return;
        num++;
        temp[k].push_back({depth ,num, root->data});
        mi = min(mi , k);
        
        ma =max(ma , k);
        dfs(root->left , k-1 , num , depth+1);
        dfs(root->right , k+1 , num , depth+1);
    }
    vector<int> verticalOrder(Node *root)
    {
        int a =0;
        dfs(root , 0 , a ,0);
        vector<int> ans;
        for(int i = mi ;i<=ma ;i++){
            vector<vector<int>> a = temp[i];
            sort(a.begin() , a.end() , mycmp);
            for(auto & it : a){
                ans.push_back(it[2]);
            }
        }
        return ans;
    }
};
