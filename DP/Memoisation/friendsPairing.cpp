#define mod 1000000007
    long long helper(int n,vector<int> &dp){
        
        if(n==1||n==2||n==0){
            return dp[n]=n;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        long long takeOne= (helper(n-1,dp))%mod;
        long long takeTwo= ((n-1)%mod*(helper(n-2,dp))%mod)%mod;
        
        return dp[n]=(takeOne%mod+takeTwo%mod)%mod;
        
    }
    int countFriendsPairings(int n) 
    { 
        vector<int> dp(n+1,-1);
        
        return helper(n,dp);
    }