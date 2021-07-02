#include "bits/stdc++.h"
using namespace std;
#define LAR 100000000

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

  if(arr[idx] == 0)
  {
      return LAR;
  }

  int jumps = LAR;

  for(int i=1 ; i<=arr[idx] and idx + i <= n ; i++)
  {
    jumps = min(jumps , 1 + solve(arr,n,idx+i));
  }

  return jumps;
}
 
int main(){

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int n;
  cin>>n;
  
  int arr[n];

  for(int i=0 ; i<n ; i++)
  {
    cin>>arr[i];
  }

  int ans = solve(arr,n,0);

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
