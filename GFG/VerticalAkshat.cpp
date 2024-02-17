class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        queue <pair<Node* , int>> pending;
        map <int, vector<int>> check;
        pending.push({root , 0});
        while(pending.size()){
            Node *f =  pending.front().first;
            int d = pending.front().second;
            pending.pop();
            check[d].push_back(f->data);
            if(f->left){
                pending.push({f->left , d-1});
            }
            if(f->right){
                pending.push({f->right , d+1});
            }
        }
        for(auto & it : check){
            for(auto & it2 : it.second){
                ans.push_back(it2);
            }
        }
        return ans;
    }
};
