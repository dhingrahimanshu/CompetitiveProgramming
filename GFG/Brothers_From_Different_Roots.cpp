class Solution
{

public:
    int ans =0;
    
    void traverse(Node *root , vector<int> & arr){
        if(root==NULL)return;
        traverse(root->left , arr);
        arr.push_back(root->data);
        traverse(root->right , arr);
    }
    
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int> arr ,arr2;
        traverse(root1 , arr);
        traverse(root2 , arr2);
        map <int,bool> uf;
        for(auto & it : arr){
            uf[it]+=1;
        }
        for(int i =0 ;i<arr2.size();i++){
            ans += uf[x -arr2[i]];
        }
        
        return ans;
    }
};
