class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int>temp;
        for(int i =0 ;i<n;i++){
            if(temp.empty() || temp.back()<a[i]){
                temp.push_back(a[i]);
            }else{
                auto it = lower_bound(temp.begin() , temp.end()  ,a[i]);
                *it = a[i];
            }
        }
        return (int)temp.size();
    }
};
