class Solution{
public:
    long long int sum=0 , level =0 , depth =0;
    Node * level_check(Node *root, int target){
        if(root==NULL)return NULL;
        if(root->data == target)return root;
        if(root->data > target){
            return level_check(root->left , target);
        }
        return level_check(root->right , target);
    }
    
    void dfs(Node *root , int l){
        if(root==NULL)return;
        if(l == 0){
            sum += root->data;
        }
        dfs(root->left , l-1);
        dfs(root->right , l+1);
    }
    
    long long int verticallyDownBST(Node *root,int target){
        sum=0;
        Node * temp = level_check(root , target);
        if(temp == NULL)return -1;
        dfs(temp , 0);
        return sum - temp->data;
    }
};
