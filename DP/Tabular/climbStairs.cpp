# define LAR 10000000
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
         

int dp[n+1];

for(int i=0 ; i<n ; i++)
{
    dp[i] = LAR;
}

dp[n] = 0;
dp[n-1] = 0;


for(int i=n-2 ; i>=0 ; i--)
{
  int ans = LAR;

  if(arr[i] == 0)
  {
    dp[i] =ans;
    continue;
  }

  for(int j=i+1 ; j <= n and j<=arr[i]+i ; j++)
  {
      
          ans = min(ans , 1+dp[j]);
      
  }
  dp[i] = ans;
}

// for(int i=0 ; i<= n ; i++)
// {
//     cout<<dp[i]<<" ";
// }
// cout<<endl;

if(dp[0] == LAR)
{
    return -1;
}
else
{
    return dp[0];

}


   
  
    }
};
