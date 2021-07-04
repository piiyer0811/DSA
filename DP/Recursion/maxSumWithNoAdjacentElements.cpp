class Solution {
public:
    int helper(vector<int> &nums,int idx){
        
        if(idx>=nums.size()){
            
            return 0;
        }
        
        int include= nums[idx]+helper(nums,idx+2);
        int exclude=helper(nums,idx+1);
        
        return max(include,exclude);
        
        
    }
    int rob(vector<int>& nums) {
        
        return helper(nums,0);
        
        
    }
};
