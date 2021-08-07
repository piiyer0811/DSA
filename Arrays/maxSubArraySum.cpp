class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum=INT_MIN;
        
       for(int len=1;len<=nums.size();len++){
           
           int i=0;
           int j=len-1;
           int sum=0;
           for(int k=i;k<=j;k++){
               sum+=nums[k];
           }
           
           maxSum=max(maxSum,sum);
          
           j++;
           
           while(j<nums.size()){
               
               sum-=nums[i];
               i++;
               sum+=nums[j];
               
                maxSum=max(maxSum,sum);
           
               j++;
               
               
               
           }
       }
        
        return maxSum;
        
    }
};

//Solution 2

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
        }
        
        return *(max_element(dp.begin(),dp.end()));
        
    }
};

//Solution 3
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currsum=nums[0];
        int maxSum=nums[0];
        
        for(int i=1;i<nums.size();i++){
            
            currsum=max(currsum+nums[i],nums[i]);
            maxSum=max(maxSum,currsum);
            
        }
        
        return maxSum;
        
    }
};