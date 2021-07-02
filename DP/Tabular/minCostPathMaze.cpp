#include<bits/stdc++.h>
using namespace std;

#define LAR 10000000




int main(){

  #ifndef ONLINE_JUDGE
  freopen("input1.txt","r",stdin);
  freopen("output1.txt","w",stdout);
  #endif

  int n,m;
  cin>>n>>m;

  vector<vector<int>> grid(n,vector<int>(m));

  vector<vector<int>> dp(n,vector<int>(m));
  for(int i=0;i<n;i++){
  	for(int j=0;j<m;j++){
  		cin>>grid[i][j];
  	}
  }

  dp[0][0]=grid[0][0];

  for(int i=1;i<m;i++){

  	dp[0][i]=dp[0][i-1]+grid[0][i];
  }

   for(int i=1;i<n;i++){

  	dp[i][0]=dp[i-1][0]+grid[i][0];
  }

  for(int i=1;i<n;i++){
  	for(int j=1;j<m;j++){
  		dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
  	}
  }



  cout<<dp[n-1][m-1]<<"\n";

  
    
  return 0;



}
