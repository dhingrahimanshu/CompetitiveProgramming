vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    queue <Node *> pending;
    pending.push(root);
    int i =1;
    while(pending.size()){
        vector<int>arr;
        int n = pending.size();
        for(int i =0 ;i<n;i++){
            Node * f = pending.front(); pending.pop();
            arr.push_back(f->data);
            if(f->left){
                pending.push(f->left);
            }
            if(f->right){
                pending.push(f->right);
            }
        }
        
        if(i&1){
            reverse(arr.begin() , arr.end());
        }
        for(auto &it : arr){
            ans.push_back(it);

        }
        i++;
    }
    
    
    return ans;
}
