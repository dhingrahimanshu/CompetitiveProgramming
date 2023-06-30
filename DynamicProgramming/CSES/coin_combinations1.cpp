/* Author: himanshu dhingra */

#include <bits/stdc++.h>
using namespace std;


/*
	State = dp[i] = number of distinct ways you can produce a sum i using available coins
	Transition = dp[i] = dp[i-C1]+ dp[i-C2]+..............+dp[i-Cn]
	Base Case = dp[0]=1 = number of distince ways to produce sum 0 is 1 (choose nothing)
	Final Subproblem = dp[x] = number of ways you can produce sum x using available coins

*/

int const MOD = 1e9+7;

void solve(){
	int n,x; cin>>n>>x;
	int arr[n];
	for(int i =0 ;i<n;i++){
		cin>>arr[i];
	}
	int dp[x+1];
	memset(dp , 0 , sizeof dp);
	dp[0]=1;
	
	for(int i = 1;i<=x;i++){
		for(int j =0 ;j<n;j++){
			if((i-arr[j])>=0){
				dp[i] = (dp[i] + dp[i-arr[j]])%MOD;
			}
		}
	}
	cout << dp[x] <<endl;
}


int main(){
	int t = 1; 
	//cin>>t;
	while(t--){
		solve();
	}
}