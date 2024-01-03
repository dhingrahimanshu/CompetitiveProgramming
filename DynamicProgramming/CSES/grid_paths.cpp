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

void solve(){
	int n; cin>>n;
	char arr[n][n];
	for(int i =0 ;i<n;i++){
		for(int j =0 ;j<n;j++){
			char a; cin>>a;
			arr[i][j]=a;
		}
	}
	int dp[n][n];
	memset(dp , 0 , sizeof dp);
	dp[0][0]= (arr[0][0]=='.');
	
	for(int i =0 ;i<n;i++){
		for(int j =0 ;j<n;j++){
			if(arr[i][j]=='*')continue;
			if(i>0){
				dp[i][j]= (dp[i][j] +dp[i-1][j])%MOD;
			}
			if(j>0){
				dp[i][j]= (dp[i][j] + dp[i][j-1])%MOD;
			}
		}
	}
	
	cout << dp[n-1][n-1] <<endl;
}


int main(){
	int t = 1; 
	//cin>>t;
	while(t--){
		solve();
	}
}