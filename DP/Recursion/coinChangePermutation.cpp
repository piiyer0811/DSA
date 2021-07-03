class Solution {
public:
    int helper(vector<int> &nums,int target){
        
        if(target==0){
            return 1;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(target-nums[i]>=0){
            ans+=helper(nums,target-nums[i]);
            }
        }
        
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        return helper(nums,target);
        
    }
};
