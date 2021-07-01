class Solution {
public:
    
    int helper(vector<int> &nums, int l,int h,vector<vector<int>> &dp){
        
        if(l>h){
            return 0;
        }
        if(l==h){
            return 1;
        }
        
        if(dp[l][h]!=-1){
            return dp[l][h];
        }
        
        int ans=1;
        
        for(int i=l+1;i<=h;i++){
            if(nums[i]>nums[l]){
                ans=max(1+helper(nums,i,h,dp),ans);
            }
        }
        
        return dp[l][h]=ans;
        
       
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size(),vector<int> (nums.size(),-1));
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,helper(nums,i,nums.size()-1,dp));
        }
        
        
        return ans;
        
    }
};


// solution 2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size(),1);
        
        for(int i=0;i<nums.size();i++){
            int ans=1;
            for(int j=i-1;j>=0;j--){
                
                if(nums[j]<nums[i]){
                    ans=max(dp[j]+1,ans);
                }
                
            }
            
            dp[i]=ans;
        }
        
        int ans=0;
        for(auto var:dp){
            ans=max(ans,var);
        }
        
        
        
        return ans;
    }
};
