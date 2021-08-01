long long helper(long long N,vector<int> &dp){
         if(N==1||N==2){
            return dp[N]=N;
        }
        
        if(dp[N]!=-1){
            return dp[N];
        }
        
        return dp[N]=(helper(N-1,dp)%1000000007+helper(N-2,dp)%1000000007)%1000000007;
    }
    long long numberOfWays(long long N) {
        
        vector<int> dp(N+1,-1);
       return helper(N,dp);
    }