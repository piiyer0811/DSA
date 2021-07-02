class Solution {
  public:
    long long helper(long long n,vector<long long > &dp){
        
         if(n==0||n==1){
            return dp[n]=n;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        return dp[n]=(helper(n-1,dp)%1000000007+helper(n-2,dp)%1000000007)%1000000007;
        
    }
    long long int nthFibonacci(long long int n){
        
       vector<long long> dp(n+1,-1);
       return helper(n,dp);
    }
};
