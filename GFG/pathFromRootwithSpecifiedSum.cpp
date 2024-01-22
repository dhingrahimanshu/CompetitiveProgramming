class Solution
{
    public:
    vector<vector<int>> ans;
        
    void helper(Node *root , int sum , vector<int> & path){
        if(root==NULL){
            return;
        }
        sum-=root->key;
        path.push_back(root->key);
        if(sum==0){
            ans.push_back(path);
        }
        
        helper(root->left  , sum ,path);
        helper(root->right , sum , path);
        path.pop_back();
    }
    
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<int> temp;
        helper(root , sum ,temp);
        return ans;
    }
};
