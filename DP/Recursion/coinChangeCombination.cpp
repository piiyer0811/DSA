class Solution {
public:
    int helper(vector<int> &coins,int idx,int amount){
        //cout<<amount<<"\n";
        if(amount==0){
            return 0;
        }
        if(idx==coins.size()){
            return 10000007;
        }
        
       
      
        int include=10000007;
        int exclude=10000007;
        
            if(amount-coins[idx]>=0){
            include=1+helper(coins,idx,amount-coins[idx]);
            }
            exclude= helper(coins,idx+1,amount);
            
            
        
        
        
        return min(include,exclude);
        
        
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int ans= helper(coins,0,amount);
        //cout<<ans<<"\n";        
        return ans>=10000007?-1:ans;
        
    }
};
