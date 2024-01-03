

class Solution{
    
    public:
    vector<int> arr;
    void inorder(Node * root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        arr.push_back(root->data);
        inorder(root->right);
    }
    Node * buildit(int i , int j){
        if(i>=j){
            return NULL;
        }
        int mid = (i + j)/2;
        Node * ans = new Node(arr[mid]);
        ans->left = buildit(i , mid);
        ans->right = buildit(mid +1, j);
        return ans;
    }
    Node* buildBalancedTree(Node* root)
    {
    	inorder(root);
    	Node * ans = buildit(0 , (int) arr.size());
    	
    }
};
