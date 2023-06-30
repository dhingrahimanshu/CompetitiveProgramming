/* Author: himanshu dhingra */

#include <bits/stdc++.h>
using namespace std;

int const MOD = 1e9 +7;

/*
    State = dp[i] = number of possible ways to construct sum I using numbers between 1 and 6 (inclusive)
	Transition = dp[i]= dp[i-1] + dp[i-2]+....+dp[i-6];
	Base Case = dp[0]=1 = number of ways to construct sum 0 is 1.(Choose Nothing)
	Final Subproblem = dp[n] = number of possible ways to construct sum N using numbers between 1 and 6 (inclusive)
	
	TC = O(N)
	SC = O(N);

*/

void solve(){
	int n; cin>>n;
	int dp[n+1];
	memset(dp , 0 , sizeof dp);
	dp[0]=1; 
	for(int i = 1;i<=n;i++){
		for(int j =1;j<=6;j++){
			if((i-j)>=0){
				dp[i] = (dp[i-j] + dp[i])%MOD;
			}
		}
	}
	cout << dp[n] <<endl;
}


int main(){
	int t = 1; 
	//cin>>t;
	while(t--){
		solve();
	}
}