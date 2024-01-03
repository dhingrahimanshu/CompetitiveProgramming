vector<int> arr;

void helper(Node *root){
    if(root==NULL){
        return ;
    }
    helper(root->left);
    arr.push_back(root->data);
    helper(root->right);
}

float findMedian(struct Node *root)
{
    arr.clear();
    helper(root);
    int n = arr.size();
    float ans = arr[n/2];
    if(n%2==0){
        ans = (ans + arr[n/2 -1])/2.0;
    }
    return ans;
}
