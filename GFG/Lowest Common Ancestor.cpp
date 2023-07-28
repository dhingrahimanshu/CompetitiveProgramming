class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            if(root==NULL){
                return NULL;
            }
            if(root->data==n1 || root->data ==n2){
                return root;
            }
            Node *a = LCA(root->left , n1 , n2);
            Node *b = LCA(root->right , n1 , n2);
            
            if(a!=NULL && b!=NULL){
                return root;
            }else if(a!=NULL){
                return a;
            }else if(b!=NULL){
                return b;
            }else{
                return NULL;
            }
            
        }

};
