class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> temp;
        vector<int> ans(n , -1);
        
        for(int i=0 ;i<n;i++){
            if(temp.empty()){
                temp.push(i);
            }else{
                while(temp.size() && arr[temp.top()]>arr[i]){
                    ans[temp.top()] = arr[i];
                    temp.pop();
                }
                temp.push(i);
            }
        }
        
        return ans;
    } 
};
