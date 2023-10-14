

class Solution
{
    public:
    vector<int> ans,ans2;
    int flag=true;
    void inorder(Node *root){
        if(root==NULL)return;
        inorder(root->left);
        flag?(ans.push_back(root->data)):(ans2.push_back(root->data));
        inorder(root->right);
    }
    
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        inorder(root1);
        flag = false;
        inorder(root2);
        int i =0,j=0;
        vector<int> fans;
        while(i<ans.size() && j<ans2.size()){
            if(ans[i]<ans2[j]){
                i++;
            }else if(ans2[j]<ans[i]){
                j++;
            }else{
                fans.push_back(ans[i]);
                i++;j++;
            }
        }
        return fans;
    }
};

