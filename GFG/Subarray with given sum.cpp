class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        
        if(s==0)return {-1};
        
        vector<int> pre;
        pre.push_back(0);
        for(int i =0;i<n;i++){
            pre.push_back(pre.back() + arr[i]);
            int re =pre.back() - s;
            
            int v = lower_bound(pre.begin() , pre.end() ,re) - pre.begin();
            if(pre[v]==re){
                return {v+1 , i+1};
            }
            
            
        }
        
        return {-1};
    }
};
