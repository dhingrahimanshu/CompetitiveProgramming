class Solution{
  public:
    vector<int> arr;
    void dfs(Node *root){
        if(root==NULL)return ;
        arr.push_back(root->data);
        dfs(root->left); dfs(root->right);
        
    }
    Node *make_bst(vector<int> & arr , int start , int end){
        if(start>end){
            return NULL;
        }
        int mid = (start+end)/2;
        Node *ans = new Node(arr[mid]);
        
        Node *lef = make_bst(arr , start , mid-1);
        Node *rig = make_bst(arr , mid+1 , end);
        ans->left  = lef;
        ans->right = rig;
        
        return ans;
    }
    Node *binaryTreeToBST (Node *root)
    {
        dfs(root);
        sort(arr.begin() , arr.end());
        
        Node * ans = make_bst(arr , 0 , arr.size()-1);
       
        return ans;
    }
};
