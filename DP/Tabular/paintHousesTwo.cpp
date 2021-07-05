#include<bits/stdc++.h>
using namespace std;

#define LAR 10000000




int main(){

  #ifndef ONLINE_JUDGE
  freopen("input1.txt","r",stdin);
  freopen("output1.txt","w",stdout);
  #endif

int n;
cin>>n;
 vector<vector<int>> costs(3,vector<int>(n));

 for(int i=0;i<n;i++){
 	for(int j=0;j<3;j++){
 		cin>>costs[j][i];
 	}
 }

 vector<vector<int>> dp(3,vector<int>(n+1));
 for(int i=0;i<3;i++){
 	dp[i][0]=0;
 }

 for(int i=1;i<=n;i++){
 	dp[0][i]=costs[0][i-1]+min(dp[1][i-1],dp[2][i-1]);
 	dp[1][i]=costs[1][i-1]+min(dp[0][i-1],dp[2][i-1]);
 	dp[2][i]=costs[2][i-1]+min(dp[0][i-1],dp[1][i-1]);
 }

 int ans=INT_MAX;

 for(int i=0;i<3;i++){
 		ans=min(ans,dp[i][n]);
 }
  
  cout<<ans<<"\n";
    
  return 0;



}