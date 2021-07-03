class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        
       vector<vector<int>> dp(coins.size()+1,vector<int> (amount+1));
        
        for(int i=0;i<=amount;i++){
            dp[0][i]=10000007;
        }
        
        for(int i=0;i<=coins.size();i++){
            dp[i][0]=0;
        }
        
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                dp[i][j]=10000007;
                if(j-coins[i-1]>=0){
                    dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i-1]]);
                }
                
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
                
            }
        }
        
        return dp[coins.size()][amount]>=10000007?-1:dp[coins.size()][amount];
        
        
    }
};
