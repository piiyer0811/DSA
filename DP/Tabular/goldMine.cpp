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

  vector<vector<int>> dp(n+1,vector<int>(m+1));
  for(int i=0;i<n;i++){
  	for(int j=0;j<m;j++){
  		cin>>grid[i][j];
  	}
  }

  for(int i=0;i<n;i++){
  	dp[i][0]=grid[i][0];
  }

  for(int j=1;j<m;j++){
  	for(int i=0;i<n;i++){

  		if(i==0){

  			dp[i][j]= grid[i][j]+max(dp[i][j-1],dp[i+1][j-1]);
  			continue;
  		}

  		if(i==n-1){
  			dp[i][j]= grid[i][j]+max(dp[i][j-1],dp[i-1][j-1]);
  			continue;
  		}

  		dp[i][j]= grid[i][j]+max(dp[i][j-1],max(dp[i-1][j-1],dp[i+1][j-1]));

  	}
  }


int ans=INT_MIN;
for(int i=0;i<n;i++){
	ans=max(ans,dp[i][m-1]);
}
 

 



  cout<<ans<<"\n";

  
    
  return 0;



}
