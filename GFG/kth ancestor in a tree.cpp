
vector<int> uf;

int kthAncestor(Node *root, int k, int node)
{
    if(root==NULL){
        return -1;
    }
    
    if(root->data==node){
        if(uf.size()>=k){
            return uf[uf.size()-k];
        }else{
            return -1;
        }
        
    }
    uf.push_back(root->data);
    int ans =max(kthAncestor(root->left , k , node),kthAncestor(root->right, k , node));
    uf.pop_back();
    return ans;
}
