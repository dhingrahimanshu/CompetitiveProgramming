/* Author: himanshu dhingra */

#include <bits/stdc++.h>
using namespace std;


/*
	State = dp[i] = minimum steps to make i = 0
	Transition = dp[i]= dp[i-x1]+ dp[i-x2]+.....+dp[i-xN](Xj is the jth digit of number)
	Base Case = dp[0]=0 = minimum steps required to make i =0 is 0 
	Final Subproblem = dp[n] = minimum steps to make n = 0
	
	TC = O(N*log10(N))
	SC = O(N)
*/

void solve(){
	int n; cin>>n;
	int dp[n+1];
	fill(dp , dp+ n+1 , 1e8);
	dp[0]=0;
	for(int i =1 ;i<=n;i++){
		int temp = i;
		while(temp){
			dp[i]=min(dp[i] , 1 + dp[i-(temp%10)]);
			temp/=10;
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