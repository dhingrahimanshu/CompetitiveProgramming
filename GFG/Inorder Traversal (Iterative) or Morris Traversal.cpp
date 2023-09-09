// Morris Traversal

class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        vector<int> ans;
        while(root!=NULL){
            if(root->left==NULL){
                ans.push_back(root->data);
                root=root->right;
            }else{
                Node *predeccessor = root->left;
                while(predeccessor->right!=NULL && predeccessor->right!=root){
                    predeccessor = predeccessor->right;
                }
                if(predeccessor->right==NULL){
                    predeccessor->right = root;
                    root = root->left;
                }else{
                    predeccessor->right=NULL;
                    ans.push_back(root->data);
                    root = root->right;
                }
                
            }
        }
        return ans;
    }
};
