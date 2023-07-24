class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        
        queue <Node *> pending;
        pending.push(root);
        while(pending.size()){
            vector<int>temp;
            int n = pending.size();
            for(int i =0 ;i<n;i++){
                Node * front = pending.front(); pending.pop();
                if(i+1==n){
                    ans.push_back(front->data);
                }
               
                if(front->left){
                    pending.push(front->left);
                }
                if(front->right){
                    pending.push(front->right);
                }
            }
        }
        
        
        
        return ans;
    }
};
