class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int startval=1;
        int n=nums.size();
        while(true){
            bool startvalwrong=false;
            int sum=startval;
              for(int j=0;j<n;j++){
              sum=sum+nums[j];
              if(sum<1){
              startval=startval+1;
                  startvalwrong=true;
                  break;
              }
          }
            
            if(!startvalwrong){
                break;
            }
          
        
    }
        return startval;
    }
};
