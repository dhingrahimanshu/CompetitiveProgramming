

int dp[1001][1001];

int helper(int i , int j , string &a , string &b){
    if(i>=a.size()|| j>=b.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(a[i]==b[j]){
        return 1 + helper(1+i , j+1 , a , b);
    }
    return 0;

}

int lcs(string &str1, string &str2){
    memset(dp , -1 , sizeof dp);
    int ans =0;

    for(int i =0 ;i<str1.size();i++){
        for(int j =0 ;j<str2.size();j++){
            ans= max(ans , helper( i , j , str1 , str2));
        }
    }

    return ans;

}
