void printCorner(Node *root)
{
    queue < Node *> pending;
    pending.push(root);
    
    while(pending.size()){
        int n = pending.size();
        
        for(int i =0 ;i<n;i++){
            Node * f = pending.front(); pending.pop();
            if(i==0 || i==n-1){
                cout << f->data <<" ";
            }
            if(f->left){
                pending.push(f->left);
            }
            if(f->right){
                pending.push(f->right);
            }
            
        }
    }

}
