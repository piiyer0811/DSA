#include "bits/stdc++.h"
using namespace std;
#define LAR 100000000

int dp[10001];

int solve(int arr[] , int n , int idx)
{
  if(idx == n)
  {
    return 0;
  }

  // if(idx > n)
  // {
  //   return LAR;
  // }

  if(dp[idx] != -1)
  {
    return dp[idx];
  }

  if(arr[idx] == 0)
  {
      return LAR;
  }

  int jumps = LAR;

  for(int i=1 ; i<=arr[idx] and idx + i <= n ; i++)
  {
    jumps = min(jumps , 1 + solve(arr,n,idx+i));
  }

  dp[idx] = jumps;

  return dp[idx];
}
 
int main(){

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int n;
  cin>>n;
  
  int arr[n];

  memset(dp,-1,sizeof(dp));

  for(int i=0 ; i<n ; i++)
  {
    cin>>arr[i];
  }

  int ans = solve(arr,n,0);

  //cout<<ans<<"\n";

  if(ans >= LAR)
  {
     cout<<-1; 
  }
  else
  {
    cout<< ans;

  }

  
  return 0;
}
