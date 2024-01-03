class Solution {
public:
    vector<int> vis;

    bool helper(int i , vector<int> & leftChild , vector<int> & rightChild){
        if(vis[i]){
            return false;
        }
        vis[i]=1;
        bool flag = true;
        if(leftChild[i]!=-1){
            flag&= helper(leftChild[i] , leftChild , rightChild);
        }
        if(rightChild[i]!=-1){
            flag&= helper(rightChild[i] , leftChild, rightChild);
        }
        return flag;
    }



    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vis.resize(n+1 , 0);
        int root =-1;
        vector<int> hash(n , 0);
        for(int i=0 ;i<n;i++){
            if(leftChild[i]!=-1){
                hash[leftChild[i]]++;
            }
            if(rightChild[i]!=-1){
                hash[rightChild[i]]++;
            }
        }
        for(int i=0 ;i<n;i++){
            if(hash[i]==0){
                root = i;
                break;
            }
        }
        if(root==-1)return false;
        bool flag = helper(root , leftChild , rightChild);
        bool flag2 = accumulate(vis.begin(), vis.end() ,0)==n;
        return flag && flag2;
    }
};
