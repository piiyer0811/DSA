//Solution 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n= nums.size();
        
        for(int i=0;i<n;i++){
            
            int idx= nums[i]%n;
            
            nums[idx]+=n;
        }
        
        int ans;
        
        for(int i=0;i<n;i++){
            if(nums[i]/n>=2){
                ans=i;
                break;
            }
        }
        
        return ans;
        
    }
};

//Solution 2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int hare= nums[0];
        int tortoise=nums[0];
        
       do{
           
           hare=nums[nums[hare]];
           tortoise=nums[tortoise];
           
       }while(hare!=tortoise);
        
        hare=nums[0];
        while(hare!=tortoise){
            hare=nums[hare];
            tortoise=nums[tortoise];
        }
        
        return hare;
    }
};