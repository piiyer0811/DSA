class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxProduct= nums[0];
        int minProduct=nums[0];
        
        int ans=nums[0];
        
        for(int i=1;i<nums.size();i++){
            
            int temp = minProduct;
            minProduct= min(nums[i],min(minProduct*nums[i],maxProduct*nums[i]));
            maxProduct= max(nums[i],max(maxProduct*nums[i],temp*nums[i]));
            
            ans=max(maxProduct,ans);
        }
        
        return ans;
    }
};
