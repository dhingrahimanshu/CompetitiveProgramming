class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = (int)nums.size();

        int ans =INT_MAX;

        
        vector<vector<int>> arr;
        arr.resize(4 ,vector<int>(n+1,0));
        
        for(int i =0 ;i<n;i++){
            
            arr[nums[i]][i+1]++;
            
            
        }
        for(int i =1 ;i<=3;i++){
            for(int j =1;j<=n;j++){
                arr[i][j]+=arr[i][j-1];
            }
        }
        
        for(int i =0 ;i<=n;i++){
            for(int j =i ;j<=n;j++){
                ans = min(ans , n -((arr[1][i]-arr[1][0]) +(arr[2][j] - arr[2][i]) + (arr[3][n] - arr[3][j])));
            }
        }
        
        return ans;
        
    }
};
