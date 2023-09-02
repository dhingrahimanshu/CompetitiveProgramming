class Solution
{
public:
    vector<int> cost;
    void dfs(Node *root , int lvl){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL){
            cost.push_back(lvl);
            return ;
        }
        dfs(root->left ,lvl+1);
        dfs(root->right , lvl+1);
    }
    int getCount(Node *root, int k){
        int ans =0;
        dfs(root ,1);
        sort(cost.begin() , cost.end());
        for(int i =0 ;i<cost.size();i++){
            if((k-cost[i])>=0){
                ans++;
                k-=cost[i];
            }else{
                break;
            }
        }
        return ans;
    }
};
