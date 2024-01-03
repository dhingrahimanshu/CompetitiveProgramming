/* Author: himanshu dhingra */

#include <bits/stdc++.h>
using namespace std;

/*
	State = dp[i] = Minimum number of coins needed to make sum i
	Transition = dp[i] = dp[i - C1] + dp[i - C2]+..... dp[i-Cn] (C = value of coins)
	Base Case = dp[0]=0 = Use no coin
	Final Subproblem = dp[x] = Minimum number of coins needed to make sum x
	
	TC = O(X*N)
	SC = O(X + N)


*/

void solve(){
	int n , x; cin>>n>>x;
	int arr[n];
	for(int i =0 ;i<n;i++){
		cin>>arr[i];
	}
	
	int dp[x+1];
	fill(dp , dp +x+1 , INT_MAX-1);
	dp[0]=0;
	for(int i = 1;i<=x;i++){
		for(int j = 0;j<n;j++){
			if((i-arr[j])>=0){
				dp[i]= min(dp[i] , 1 + dp[i-arr[j]]);
			}
		}
	}
	
	if(dp[x]>=1e8){
		cout << -1 <<endl;
	}else{
		cout << dp[x] <<endl;
	}
}


int main(){
	int t = 1; 
	//cin>>t;
	while(t--){
		solve();
	}
}