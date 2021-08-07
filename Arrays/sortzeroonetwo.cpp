
// Solution 1
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int red=0;
        int white=0;
        int blue=0;
        
        for(auto var:nums){
            if(var==0){
                red++;
            }
            else if(var==1){
                white++;
            }
            else{
                blue++;
            }
        }
        
        int idx=0;
        while(red>0){
            nums[idx]=0;
            idx++;
            red--;
        }
        
        while(white>0){
            nums[idx]=1;
            idx++;
            white--;
        }
        
        while(blue>0){
            nums[idx]=2;
            idx++;
            blue--;
        }
        
    
        
    }
};

//Solution 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        
        while(mid<=high){
            
            if(nums[mid]==1){
                
                mid++;
                
            }
            
            else if(nums[mid]==0){
                
                swap(nums[low],nums[mid]);
                mid++;
                low++;
                
            }
            else{
                
                swap(nums[high],nums[mid]);
                high--;
                
            }
            
            
        }
        
    }
};