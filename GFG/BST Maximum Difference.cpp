class Solution{
public:
    int sum=0;
    Node * make(Node *root , int target){
        if(root==NULL)return NULL;
        sum += root->data;
        if(root->data == target){
            return root;
        }
        if(root->data > target){
            return make(root->left , target);
        }
        return make(root->right , target);
    }
    int dfs(Node *root){
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL)return root->data;
        if(root->left==NULL){
            return root->data + dfs(root->right);
        }
        if(root->right==NULL){
            return root->data + dfs(root->left);
        }
        return root->data + min(dfs(root->left) , dfs(root->right));
    }
    int dfs2(Node *root){
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL)return root->data;
        if(root->left==NULL){
            return root->data + dfs2(root->right);
        }
        if(root->right==NULL){
            return root->data + dfs2(root->left);
        }
        return root->data + max(dfs2(root->left) , dfs2(root->right));
    }
    int maxDifferenceBST(Node *root,int target){
        Node *temp = make(root , target);
        if(temp == NULL)return -1;
        // cout << sum <<endl;
        int mi = dfs(temp) , ma = dfs2(temp);
        // cout << mi <<" " << ma <<endl;
        return max(sum  - mi , sum -ma);
    }
};
