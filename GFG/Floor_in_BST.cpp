class Solution{

public:
    
    int floor(Node* root, int x) {
        if(root==NULL)return -1;
        
        if(root->data > x){
            return floor(root->left , x);
        }else if(root->data < x){
            return max({floor(root->left , x) , floor(root->right , x) , root->data});
        }else{
            return root->data;
        }
        
    }
};
