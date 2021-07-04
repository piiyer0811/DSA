class Solution {
public:
    int helper(vector<int> &nums,int idx,vector<int> &dp){
        
        if(idx>=nums.size()){
            
            return dp[idx]= 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int include= nums[idx]+helper(nums,idx+2,dp);
        int exclude=helper(nums,idx+1,dp);
        
        return dp[idx]= max(include,exclude);
        
        
    }
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+2,-1);
        return helper(nums,0,dp);
        
        
    }
};
