#include<bits/stdc++.h>
using namespace std;

#define LAR 10000000

int minCostPath(vector<vector<int>> &grid,int i,int j,int n,int m,vector<vector<int>> &dp){

	if(i==n&&j==m){
		return dp[i][j]=grid[i][j];
	}

	if(i<0||i>n||j<0||j>m){
		return dp[i][j]=LAR;
	}

	if(dp[i][j]!=LAR){
		return dp[i][j];
	}

	return dp[i][j]=grid[i][j]+min(minCostPath(grid,i+1,j,n,m,dp),minCostPath(grid,i,j+1,n,m,dp));


}


int main(){

  #ifndef ONLINE_JUDGE
  freopen("input1.txt","r",stdin);
  freopen("output1.txt","w",stdout);
  #endif

  int n,m;
  cin>>n>>m;

  vector<vector<int>> grid(n,vector<int>(m));

  vector<vector<int>> dp(n+5,vector<int>(m+5,LAR));
  for(int i=0;i<n;i++){
  	for(int j=0;j<m;j++){
  		cin>>grid[i][j];
  	}
  }



  cout<<minCostPath(grid,0,0,n-1,m-1,dp)<<"\n";

  
    
  return 0;



}
