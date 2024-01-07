class Solution {
public:
    int dp[501][501];

    int helper(int i , int j ,int n , int m , string &s1 , string &s2){
        if(i==n || j==m){
            return abs(i-n) + abs(m-j);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return helper(i+1 ,j +1 , n , m , s1 , s2);
        }
     
        int ans = 1 + helper(i+1 ,j , n , m , s1 , s2);
        ans = min(ans ,1+ helper(i ,j+1 ,n ,m , s1, s2));
        ans =min(ans , 1 + helper(i+1 ,j +1 , n ,m ,s1, s2));

        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        memset(dp , -1 , sizeof dp);
        return helper(0 , 0 , word1.size() , word2.size() , word1 , word2);
    }
};
