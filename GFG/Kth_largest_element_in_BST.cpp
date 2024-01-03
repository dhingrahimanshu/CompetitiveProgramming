// solved using reverse morris inorder traversal

class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        
        int i =0;
        while(root!=NULL){
            if(root->right==NULL){
                i++;
                if(i==K){
                    return root->data;
                }
                root=root->left;
            }else{
                Node *pred = root->right;
                while(pred->left!=NULL && pred->left!=root){
                    pred = pred->left;
                }
                if(pred->left==NULL){
                    pred->left = root;
                    root = root->right;
                }else{
                    i++;
                    if(i==K){
                        return root->data;
                    }
                    pred->left=NULL;
                    root = root->left;
                }
            }
        }
        
        
        
        return -1;
    }
};
