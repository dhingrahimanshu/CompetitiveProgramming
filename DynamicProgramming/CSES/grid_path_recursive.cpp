/* Author: himanshu dhingra */

#include <bits/stdc++.h>
using namespace std;


int const MOD = 1e9+7;

/*
	State = dp[i][j] = number of paths from (0,0) to (i , j)
	Transition = dp[i][j] = (dp[i-1][j] + dp[i][j-1]) // add only when there is no trap at (i,j)
	Base Case = dp[0][0]=1 if no trap at (0,0)
				dp[0][0] =0 if trap at (0 ,0);
				
	Final Subproblem = dp[n-1][n-1]= number of paths from (0,0) to (n-1  , n-1);

*/

int const maxN = 1001;
char arr[maxN][maxN];
int dp[maxN][maxN];

int helper(int i , int j){
	if(i<0 || j<0){ // not possible
		return 0;
	}
	if(i==0 && j==0){
		return dp[0][0] = (arr[0][0]=='.');
	}
	if(dp[i][j]!=-1){ // memoization
		return dp[i][j];
	}
	if(arr[i][j]=='*'){ // base case
		return dp[i][j]=0;
	}
	return dp[i][j] = (helper(i-1 , j) + helper(i , j-1))%MOD; // transition

}

void solve(){
	int n;cin>>n;
	for(int i =0 ;i<n;i++){
		for(int j =0 ;j<n;j++){
			cin>>arr[i][j];
		}
	}
	
	memset(dp , -1 , sizeof dp);
	helper(n-1 , n-1);
	cout << dp[n-1][n-1] <<endl;
}


int main(){
	int t = 1; 
	//cin>>t;
	while(t--){
		solve();
	}
}