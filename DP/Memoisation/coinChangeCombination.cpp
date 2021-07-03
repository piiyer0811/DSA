class Solution {
public:
    int helper(vector<int> &coins,int idx,int amount,vector<vector<int>> &dp){
        //cout<<amount<<"\n";
        if(amount==0){
            return dp[idx][amount]=0;
        }
        if(idx==coins.size()){
            return dp[idx][amount]=10000007;
        }
        
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
      
      
        int include=10000007;
        int exclude=10000007;
        
            if(amount-coins[idx]>=0){
            include=1+helper(coins,idx,amount-coins[idx],dp);
            }
            exclude= helper(coins,idx+1,amount,dp);
            
            
        
        
        
        return dp[idx][amount]=min(include,exclude);
        
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans= helper(coins,0,amount,dp);
        //cout<<ans<<"\n";        
        return ans>=10000007?-1:ans;
        
    }
};
